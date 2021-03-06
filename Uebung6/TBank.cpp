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



TBank::TBank(string name, string blz) :
		accountsInBank_counter(0) {

	this->setName(name);
	this->setBLZ(blz);
}

TBank::~TBank() {
	Liste<TAccount*>::Iterator it(list_acc);

	while(!list_acc.empty()){
		TAccount* t = list_acc[0];
		delete t;
		list_acc.pop_front();
	}
}

int TBank::getAccountCounter() const {
	return accountsInBank_counter;
}

string TBank::getBLZ() const {
	return blz;
}

void TBank::setBLZ(string blz) {
	this->blz = blz;
}

string TBank::getName() const {
	return name;
}

void TBank::setName(string name) {
	this->name = name;
}

Liste<TAccount*> TBank::getAccountArray() {
	return list_acc;
}

void TBank::addAccount(TAccount* acc) {
	if (accountsInBank_counter >= tAccountInBankArray_MAX)
		return;

	list_acc.push_back(acc);
	//list_acc[accountsInBank_counter] = acc;
	accountsInBank_counter++;
	TAccount* a = list_acc[accountsInBank_counter - 1];
	a->getAccountNumber();
}

void TBank::print() {
	cout << getName() << "\n";
	cout << "BLZ " << getBLZ() << "\n";
	cout << "Anzahl Konten: " << getAccountCounter() << "\n";
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

	for (int i = 0; i < getAccountCounter(); i++) {
		std::cout << setfill(' ') << std::right << std::setw(11)
				<< list_acc[i]->getAccountNumber() << " " << "| "
				<< std::left << std::setw(31)
				<< list_acc[i]->getCustomer()->getName() << std::left
				<< std::setw(15) << "|"
				<< list_acc[i]->getBookingsCount() << std::left
				<< std::setw(0) << " | "
				<< negZeichen(list_acc[i]->getAccountAmount())
				<< std::right << std::setw(10) << setiosflags(ios::fixed)
				<< setprecision(2)
				<< fabs(list_acc[i]->getAccountAmount().getAmount())
				<< " "
				<< list_acc[i]->getAccountAmount().getCurrency()
				<< "\n";

	}

	cout << "\n" << flush;
}

char TBank::negZeichen(TMoney m) {
	if (m.getAmount() < .0)
		return '-';
	return ' ';
}

TAccount* TBank::getAccount(string acc){
	for (int i = 0; i < getAccountCounter(); i++) {
		TAccount* a = getAccountArray()[i];
		if (a->getAccountNumber().compare(acc) == 0) return a;
	}
	return NULL;
}

TAccount* TBank::getAccountByID(int id){
	return getAccountArray()[id];
}



ostream& operator<<(ostream & out, TBank& m){

	out << m.getName() << "\n";
	out << "BLZ " << m.getBLZ() << "\n";
	out << "Anzahl Konten: " << m.getAccountCounter() << "\n";
	out << "Kontenliste: \n";

	//Generierung Kontenliste
	//...
	out << std::left << std::setw(12) << "Kontonr." << std::left
			<< std::setw(33) << "| Kundenname" << std::left << std::setw(17)
			<< "| Anz. Buchungen" << std::left << std::setw(17)
			<< "| Kontostand" << "\n";

	out << setfill('-') << std::left << std::setw(12) << "" << std::left
			<< std::setw(33) << "|" << std::left << std::setw(17) << "|"
			<< std::left << std::setw(17) << "|" << "\n";

	for (int i = 0; i < m.getAccountCounter(); i++) {
		out << setfill(' ') << std::right << std::setw(11)
				<< m.getAccountByID(i)->getAccountNumber() << " " << "| "
				<< std::left << std::setw(31)
				<< m.getAccountByID(i)->getCustomer()->getName() << std::left
				<< std::setw(15) << "|"
				<< m.getAccountByID(i)->getBookingsCount() << std::left
				<< std::setw(0) << " | "
				<< m.negZeichen(m.getAccountByID(i)->getAccountAmount())
				<< std::right << std::setw(10) << setiosflags(ios::fixed)
				<< setprecision(2)
				<< fabs(m.getAccountByID(i)->getAccountAmount().getAmount())
				<< " "
				<< m.getAccountByID(i)->getAccountAmount().getCurrency()
				<< "\n";

	}
	out << "\n";
	return out;
}

