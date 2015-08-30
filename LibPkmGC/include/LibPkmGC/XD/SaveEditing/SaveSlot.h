#ifndef _LIBPKMGC_XD_SAVE_EDITING_SAVE_SLOT_H
#define _LIBPKMGC_XD_SAVE_EDITING_SAVE_SLOT_H

#include <LibPkmGC/GC/SaveEditing/SaveSlot.h>
#include <LibPkmGC/XD/Common/Everything.h>

namespace LibPkmGC {
namespace XD {
namespace SaveEditing {

/*
	0x00: u32 magic
	0x04: s32 saveCount
	0x08: u16 encryptionKeys[4] (random generated)

	0x10: **ENCRYPTED DATA**
	0x10: u32 checksum[4] (stored in a particular way, see below)
	0x20: u16 substructureSizes[16]
	0x40: u32 substructureOffsets[16] (stored in a particular way, see below)
	0x80: u16 substructure8SubsubstructureSizes[5] (??)

	0xa8: substructures
	(end)-40: **END OF ENCRYPTED DATA**
	(end)-40: u8 randomBytes[40];
*/

/*
	Substructures, in order :
	- [0] metadata/game config, size=0x88 (for compat. w/ colosseum it is directly handled within GC::SaveSlot)
	- [1] party & player data
	- [2] PC Storage
	- [3] Mailbox
	- [4] Daycare
	- [5] Strategy memo
	- [6] Battle mode
	- [7] Shadow Pokémon data (in Colosseum, this is apparently a PID list; the full shadow data SEEMS to be included in the Pokémon's data)
	- ?
	- ?
	- map data / script state
	- Purifier
*/


/*
	Metadata substructure (off 0 (total 0xa8)) :
	0x00: VersionInfo version (game, region, language)
	0x04--0x07: u32 ?
	0x08: u64 memcardUID (see GCSaveSlot.h)

	0x29: u8 noRumble
	0x2a: u16 titleScreenLanguage
	0x38: s32 headerChecksum
*/

class LIBPKMGC_DECL SaveSlot :
	public GC::SaveEditing::SaveSlot
{
public:
	static const size_t size = 0x28000;
	SaveSlot(void);
	SaveSlot(const u8* inData, bool isDecrypted = false);
	SaveSlot(SaveSlot const& other);

	~SaveSlot(void);

	SaveSlot* clone(void) const;
	SaveSlot* create(void) const;

	void swap(SaveSlot& other);
	SaveSlot& operator=(SaveSlot const& other);

	void save(void);

	bool checkChecksum(bool fix = false);
	bool checkHeaderChecksum(bool fix = false);
	std::pair<bool, bool> checkBothChecksums(bool fixGlobalChecksum = false, bool fixHeaderChecksum = false);
	bool isCorrupt(void);

	void reorderSubstructures(void);
	void saveUnshuffled(void);

	void saveEncrypted(u8* outBuf);

	PurifierData* purifier;

	u32 checksum[4];

	u16 encryptionKeys[4];
	u32 substructureSizes[16]; // there are actually 12 substructures
	u32 substructureOffsets[16]; // there are actually 12 substructures


protected:
	void loadData(u32 flags = 0);
	void deleteFields(void);
	void loadFields(void);

private:
	Base::UnimplementedStruct* unhandledSubstructures[16]; // by definition don't pay attention to that
	void _deleteFields_extension(void);
	bool _other_corruption_flags;
	SaveSlot(Colosseum::SaveEditing::SaveSlot const&);
};

}
}
}

#endif