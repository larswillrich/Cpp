/*
 * TBank.cpp
 *
 *  Created on: 31.10.2012
 *      Author: Lars Willrich
 */

#include "TBank.h"
#include "TAccount.h"

TBank::TBank(char* name, char* blz) {

	this->setName(name);
	this->setBlz(blz);
}

int TBank::getAccountArrayCounter() const {
	return accountArray_counter;
}

char* TBank::getBlz() const {
	return blz;
}

void TBank::setBlz(char* blz) {
	this->blz = blz;
}

char* TBank::getName() const {
	return name;
}

void TBank::setName(char* name) {
	this->name = name;
}

TAccount** TBank::getAccountArray() {
	return tAccountArray;
}

void TBank::print(){
	cout << getName();
	cout << "BLZ " << getBlz() << "\n";
	cout << "Anzahl Konten: " << getAccountArrayCounter() << "\n";
	cout << "Kontenliste: ";

	//Generierung Kontenliste
	//...
}

TBank::~TBank() {
	// TODO Auto-generated destructor stub
}

