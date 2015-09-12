/*
* Copyright (C) TuxSH 2015
* This file is part of LibPkmGC.
*
* LibPkmGC is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* LibPkmGC is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with LibPkmGC.  If not, see <http://www.gnu.org/licenses/>.
*/

// This file uses code from libiconv : 

/*
* Copyright (C) 1999-2001, 2004 Free Software Foundation, Inc.
* This file is part of the GNU LIBICONV Library.
*
* The GNU LIBICONV Library is free software; you can redistribute it
* and/or modify it under the terms of the GNU Library General Public
* License as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* The GNU LIBICONV Library is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Library General Public License for more details.
*
* You should have received a copy of the GNU Library General Public
* License along with the GNU LIBICONV Library; see the file COPYING.LIB.
* If not, write to the Free Software Foundation, Inc., 51 Franklin Street,
* Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include <LibPkmGC/Base/PokemonString.h>

namespace LibPkmGC {
namespace Base {


PokemonString::PokemonString(void) : hasChanged(true), _str(NULL), strSz(0), strCapacity(0), _data(NULL), dataSz(0), dataCapacity(0), _japanese(false) {
}

PokemonString::~PokemonString(void) {
	delete[] _str;
	delete[] _data;
}

PokemonString & PokemonString::operator=(PokemonString const & other) {
	if (this != &other) {
		assert(isGBA() == other.isGBA());
		hasChanged = true;
		strSz = other.strSz;
		_japanese = other._japanese;
		dataSz = other.dataSz;
		dataCapacity = other.dataCapacity;
		resizeStr();
		resizeData();
		std::copy(other._data, other._data + dataSz, _data);
	}
	return *this;
}


PokemonString::operator const char*(void) const {
	return toUTF8();
}

bool PokemonString::usesJapaneseCharset(void) const {
	return _japanese;
}

void PokemonString::setCharset(bool jap) {
	if (jap != _japanese) hasChanged = true;
	_japanese = jap;
}

PokemonString::PokemonString(PokemonString const & other) : hasChanged(true), strSz(other.strSz), strCapacity(0), _str(NULL), 
dataSz(other.dataSz), dataCapacity(0), _data(NULL), _japanese(other._japanese) {
	resizeStr();
	resizeData();
	std::copy(other._data, other._data + dataSz, _data);
}

void PokemonString::resizeStr(void) const {
	if (strCapacity < strSz) {
		strCapacity = strSz;
		delete[] _str;
		_str = new char[strSz];
	}
}

void PokemonString::resizeData(void) {
	if (dataCapacity < dataSz) {
		dataCapacity = dataSz;
		delete[] _data;
		_data = new u8[dataSz];
	}
}

}

namespace Detail {

/*
* UTF-8
*/

/* Specification: RFC 3629 */

int
utf8_mbtowc(conv_t conv, ucs4_t *pwc, const unsigned char *s, int n)
{
	unsigned char c = s[0];

	if (c < 0x80) {
		*pwc = c;
		return 1;
	}
	else if (c < 0xc2) {
		return RET_ILSEQ;
	}
	else if (c < 0xe0) {
		if (n < 2)
			return RET_TOOFEW(0);
		if (!((s[1] ^ 0x80) < 0x40))
			return RET_ILSEQ;
		*pwc = ((ucs4_t)(c & 0x1f) << 6)
			| (ucs4_t)(s[1] ^ 0x80);
		return 2;
	}
	else if (c < 0xf0) {
		if (n < 3)
			return RET_TOOFEW(0);
		if (!((s[1] ^ 0x80) < 0x40 && (s[2] ^ 0x80) < 0x40
			&& (c >= 0xe1 || s[1] >= 0xa0)))
			return RET_ILSEQ;
		*pwc = ((ucs4_t)(c & 0x0f) << 12)
			| ((ucs4_t)(s[1] ^ 0x80) << 6)
			| (ucs4_t)(s[2] ^ 0x80);
		return 3;
	}
	else if (c < 0xf8 && sizeof(ucs4_t) * 8 >= 32) {
		if (n < 4)
			return RET_TOOFEW(0);
		if (!((s[1] ^ 0x80) < 0x40 && (s[2] ^ 0x80) < 0x40
			&& (s[3] ^ 0x80) < 0x40
			&& (c >= 0xf1 || s[1] >= 0x90)))
			return RET_ILSEQ;
		*pwc = ((ucs4_t)(c & 0x07) << 18)
			| ((ucs4_t)(s[1] ^ 0x80) << 12)
			| ((ucs4_t)(s[2] ^ 0x80) << 6)
			| (ucs4_t)(s[3] ^ 0x80);
		return 4;
	}
	else if (c < 0xfc && sizeof(ucs4_t) * 8 >= 32) {
		if (n < 5)
			return RET_TOOFEW(0);
		if (!((s[1] ^ 0x80) < 0x40 && (s[2] ^ 0x80) < 0x40
			&& (s[3] ^ 0x80) < 0x40 && (s[4] ^ 0x80) < 0x40
			&& (c >= 0xf9 || s[1] >= 0x88)))
			return RET_ILSEQ;
		*pwc = ((ucs4_t)(c & 0x03) << 24)
			| ((ucs4_t)(s[1] ^ 0x80) << 18)
			| ((ucs4_t)(s[2] ^ 0x80) << 12)
			| ((ucs4_t)(s[3] ^ 0x80) << 6)
			| (ucs4_t)(s[4] ^ 0x80);
		return 5;
	}
	else if (c < 0xfe && sizeof(ucs4_t) * 8 >= 32) {
		if (n < 6)
			return RET_TOOFEW(0);
		if (!((s[1] ^ 0x80) < 0x40 && (s[2] ^ 0x80) < 0x40
			&& (s[3] ^ 0x80) < 0x40 && (s[4] ^ 0x80) < 0x40
			&& (s[5] ^ 0x80) < 0x40
			&& (c >= 0xfd || s[1] >= 0x84)))
			return RET_ILSEQ;
		*pwc = ((ucs4_t)(c & 0x01) << 30)
			| ((ucs4_t)(s[1] ^ 0x80) << 24)
			| ((ucs4_t)(s[2] ^ 0x80) << 18)
			| ((ucs4_t)(s[3] ^ 0x80) << 12)
			| ((ucs4_t)(s[4] ^ 0x80) << 6)
			| (ucs4_t)(s[5] ^ 0x80);
		return 6;
	}
	else
		return RET_ILSEQ;
}

int
utf8_wctomb(conv_t conv, unsigned char *r, ucs4_t wc, int n) /* n == 0 is acceptable */ {
	int count;
	if (wc < 0x80)
		count = 1;
	else if (wc < 0x800)
		count = 2;
	else if (wc < 0x10000)
		count = 3;
	else if (wc < 0x200000)
		count = 4;
	else if (wc < 0x4000000)
		count = 5;
	else if (wc <= 0x7fffffff)
		count = 6;
	else
		return RET_ILUNI;
	if (n < count)
		return RET_TOOSMALL;
	switch (count) { /* note: code falls through cases! */
	case 6: r[5] = 0x80 | (wc & 0x3f); wc = wc >> 6; wc |= 0x4000000;
	case 5: r[4] = 0x80 | (wc & 0x3f); wc = wc >> 6; wc |= 0x200000;
	case 4: r[3] = 0x80 | (wc & 0x3f); wc = wc >> 6; wc |= 0x10000;
	case 3: r[2] = 0x80 | (wc & 0x3f); wc = wc >> 6; wc |= 0x800;
	case 2: r[1] = 0x80 | (wc & 0x3f); wc = wc >> 6; wc |= 0xc0;
	case 1: r[0] = wc;
	}
	return count;
}

}
}
