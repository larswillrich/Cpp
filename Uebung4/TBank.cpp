/*
 * TBank.cpp
 *
 *  Created on: 31.10.2012
 *      Author: Lars Willrich
 */

#include "TBank.h"
#include "TAccount.h"
#include <iostream>
#include <math.h>
#include <iomanip>

char negZeichen(TMoney m);

TBank::TBank(char* name, char* blz) :
		accountsInBank_counter(0) {

	this->setName(name);
	this->setBlz(blz);
}

int TBank::getAccountArrayCounter() const {
	return accountsInBank_counter;
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
	return tAccountInBankArray;
}

void TBank::addAccount(TAccount* acc) {
	if (accountsInBank_counter >= tAccountInBankArray_MAX)
		return;

	tAccountInBankArray[accountsInBank_counter] = acc;
	accountsInBank_counter++;
}

void TBank::print() {
	cout << getName();
	cout << "BLZ " << getBlz() << "\n";
	cout << "Anzahl Konten: " << getAccountArrayCounter() << "\n";
	cout << "Kontenliste: \n";

	//Generierung Kontenliste
	//...
	std::cout << std::left << std::setw(12) << "Kontonr." << std::left
			<< std::setw(33) << "| Kundenname" << std::left << std::setw(17)
			<< "| Anz. Buchungen" << std::left << std::setw(17)
			<< "| Kontostand" << "\n";

	std::cout << setfill('-') << std::left << std::setw(12) << "" << std::left
			<< std::setw(33) << "|" << std::left << std::setw(17) << "|"
			<< std::left << std::setw(17) << "|" << "\n";

	for (int i = 0;i<getAccountArrayCounter();i++){
		std::cout << setfill(' ') << std::right << std::setw(12) << tAccountInBankArray[i]->getAccountNumber()
		  	    << "| "<< std::left << std::setw(31) << tAccountInBankArray[i]->getCustomer()->getName()
				<< std::left << std::setw(15) << "|" << tAccountInBankArray[i]->getBookingsCount()
				<< std::left << std::setw(0) << " | " << negZeichen(tAccountInBankArray[i]->getAccountAmount())
				<< std::right << std::setw(10) << setiosflags(ios::fixed) <<setprecision(2) << fabs(tAccountInBankArray[i]->getAccountAmount().getAmount())
				<< " " << tAccountInBankArray[i]->getAccountAmount().getCurrency() << "\n";

	}

	cout << "\n" << flush;
}

char negZeichen(TMoney m)
{
	if (m.getAmount() < .0) return '-';
	return ' ';
}

TBank::~TBank() {
	for (int i = 0;i<getAccountArrayCounter();i++){
		TAccount* a = getAccountArray()[i];
		a->getAccountAmount();
		delete a;
	}
}

