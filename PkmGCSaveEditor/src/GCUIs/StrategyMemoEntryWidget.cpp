/*
* Copyright (C) TuxSH 2015
* This file is part of PkmGCSaveEditor.
*
* PkmGCSaveEditor is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* PkmGCSaveEditor is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with PkmGCSaveEditor.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <GCUIs/StrategyMemoEntryWidget.h>

using namespace LibPkmGC;
using namespace Localization;

namespace GCUIs {

StrategyMemoEntryWidget::StrategyMemoEntryWidget(LibPkmGC::GC::StrategyMemoEntry* inEntry, int inEntryIndex, QWidget* parent) : QWidget(parent), IDataUI(),
entry(inEntry), entryIndex(inEntryIndex) {
	init();
}


void StrategyMemoEntryWidget::updatePIDText(void) {
	if (speciesSelector->currentIndex() == 0 && firstTIDFld->unsignedValue() == 0 && firstSIDFld->unsignedValue() == 0) {
		PIDText->setText(tr("(randomly generated)"));
		return;
	}

	if (Base::Pokemon::isShiny(firstPIDFld->unsignedValue(), (u16)firstTIDFld->unsignedValue(), (u16)firstSIDFld->unsignedValue()) && !isXD) {
		PIDText->setText("<span style='color:red;'>\xe2\x98\x85</span>");
	}
	else {
		PIDText->setText("");
	}
}

void StrategyMemoEntryWidget::generateShinyIDs(void) {
	u32 PID = firstPIDFld->unsignedValue();
	firstTIDFld->setUnsignedValue(PID >> 16);
	firstSIDFld->setUnsignedValue(PID & 0xffff);
}

void StrategyMemoEntryWidget::truncateMemoFromHere(void) {
	speciesSelector->setCurrentIndex(0);
}

void StrategyMemoEntryWidget::initWidget(void) {
	LanguageIndex lg = generateDumpedNamesLanguage();
	mainLayout = new QVBoxLayout;
	mainLayout2 = new QFormLayout;
	speciesSelector = new QComboBox;

	partialInfoCheckBox = new QCheckBox;

	firstTIDFld = new UnsignedSpinbox<16>;
	firstSIDFld = new UnsignedSpinbox<16>;
	PIDLayout = new QVBoxLayout;
	firstPIDFld = new UnsignedSpinbox<32>;
	PIDText = new QLabel;
	generateShinyIDsButton = new QPushButton(tr("Generate shiny IDs"));
	truncateMemoFromHereButton = new QPushButton(tr("Truncate memo from here"));

	for (size_t i = 0; i <= 386; ++i)
		speciesSelector->addItem(getPokemonSpeciesNameByPkdxIndex(lg, (u16)i));

	PIDLayout->addWidget(firstPIDFld);
	PIDLayout->addWidget(PIDText);

	mainLayout2->addRow(tr("Species"), speciesSelector);
	mainLayout2->addRow(tr("First TID"), firstTIDFld);
	mainLayout2->addRow(tr("First SID"), firstSIDFld);
	mainLayout2->addRow(tr("First PID"), PIDLayout);
	mainLayout2->addRow(tr("Partial information"), partialInfoCheckBox);
	mainLayout->addLayout(mainLayout2);
	mainLayout->addWidget(generateShinyIDsButton);
	mainLayout->addWidget(truncateMemoFromHereButton);

	mainLayout2->setHorizontalSpacing(20);
	this->setLayout(mainLayout);


	connect(speciesSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(speciesChangeHandler(int)));
	connect(firstPIDFld, SIGNAL(valueChanged(int)), this, SLOT(updatePIDText()));
	connect(firstTIDFld, SIGNAL(valueChanged(int)), this, SLOT(updatePIDText()));
	connect(firstSIDFld, SIGNAL(valueChanged(int)), this, SLOT(updatePIDText()));
	connect(generateShinyIDsButton, SIGNAL(clicked()), this, SLOT(generateShinyIDs()));
	connect(truncateMemoFromHereButton, SIGNAL(clicked()), this, SLOT(truncateMemoFromHere()));
}

StrategyMemoEntryWidget::~StrategyMemoEntryWidget(void) {
}

void StrategyMemoEntryWidget::parseData(void) {
	if (entry == NULL) return;
	isXD = LIBPKMGC_IS_XD(StrategyMemoEntry, entry);

	generateShinyIDsButton->setVisible(!isXD);
	partialInfoCheckBox->setChecked(entry->isInfoPartial());
	partialInfoCheckBox->setDisabled(isXD);

	speciesSelector->setCurrentIndex(pkmSpeciesIndexToNameIndex(entry->species));

	firstSIDFld->setUnsignedValue(entry->firstSID);
	firstTIDFld->setUnsignedValue(entry->firstTID);
	firstPIDFld->setUnsignedValue(entry->firstPID);
	updatePIDText();
}

void StrategyMemoEntryWidget::saveChanges(void) {
	entry->setInfoCompleteness(partialInfoCheckBox->isChecked());
	entry->species = nameIndexToPkmSpeciesIndex(speciesSelector->currentIndex());
	entry->firstSID = (u16)firstSIDFld->unsignedValue();
	entry->firstTID = (u16)firstTIDFld->unsignedValue();
	entry->firstPID = firstPIDFld->unsignedValue();
}


void StrategyMemoEntryWidget::speciesChangeHandler(int nameIndex) {
	generateShinyIDsButton->setDisabled(nameIndex == 0);
	updatePIDText();
	emit speciesChanged(entryIndex, nameIndex);
}


}