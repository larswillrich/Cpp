/*
 * TCustomer.cpp
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#include "TCustomer.h"
#include <iomanip>
#include "TAccount.h"

TCustomer::TCustomer(char* name, TDate birthday, char* street, char* streetnumber, char* plz, char* city) : tAccountsInCustomer(0){
	this->street = street;
	this->streetnumber = streetnumber;
	this->plz = plz;
	this->city = city;
	this->birthday = birthday;
	this->name = name;
}

TCustomer::~TCustomer() {
}

TDate TCustomer::getBirthday() const {
	return birthday;
}

void TCustomer::setBirthday(TDate birthday) {
	this->birthday = birthday;
}

char* TCustomer::getCity() const {
	return city;
}

void TCustomer::setCity(char* city) {
	this->city = city;
}

char* TCustomer::getName() const {
	return name;
}

void TCustomer::setName(char* name) {
	this->name = name;
}

int TCustomer::getNumberTAccounts() const {
	return tAccountsInCustomer;
}

void TCustomer::setNumberTAccounts(int numberTAccounts) {
	this->tAccountsInCustomer = numberTAccounts;
}

char* TCustomer::getPlz() const {
	return plz;
}

void TCustomer::setPlz(char* plz) {
	this->plz = plz;
}

char* TCustomer::getStreet() const {
	return street;
}

void TCustomer::setStreet(char* street) {
	this->street = street;
}

char* TCustomer::getStreetnumber() const {
	return streetnumber;
}

void TCustomer::setStreetnumber(char* streetnumber) {
	this->streetnumber = streetnumber;
}

void TCustomer::addNewAccount(TAccount* acc){
	if (tAccountsInCustomer >= tAccountInCustomerArray_MAX) return;

	tAccountInCustomerArray[tAccountsInCustomer] = acc;
	tAccountsInCustomer++;
}


TAccount* TCustomer::getAccountByID(int id){
	if (id > tAccountInCustomerArray_MAX || id < 0) return NULL;

	return tAccountInCustomerArray[id];
}

void TCustomer::print(){
	//cout << "Kunde:" << "\n";
	cout << getName() << "\n";
	cout << getStreet() << " " << getStreetnumber() << "\n";
	cout << getPlz() << " " << getCity() << "\n";
	cout << "geboren am: ";
	getBirthday().print();
	cout << "\n";

	//Ausgabe Konten
	cout << "Konten: " << "\n";
	for (int i = 0; i < tAccountsInCustomer ; i++) {
		cout << "- Kontonr.: " << std::left << std::setw(12) << tAccountInCustomerArray[i]->getAccountNumber() << std::setw(12) << " (Kontostand:     ";
		tAccountInCustomerArray[i]->getAccountAmount().print();
		cout << ")\n";
	}

	cout << "\n";
}
ostream& operator<<(ostream & out, TCustomer* tl){
	//cout << "Kunde:" << "\n";
	out << tl->getName() << "\n";
	out << tl->getStreet() << " " << tl->getStreetnumber() << "\n";
	out << tl->getPlz() << " " << tl->getCity() << "\n";
	out << "geboren am: ";
	out << tl->getBirthday();
	out << "\n";

	//Ausgabe Kontent
	out << "Konten: " << "\n";
	for (int i = 0; i < tl->getNumberTAccounts() ; i++) {
		TAccount* tAccountInCustomerArray = tl->getAccountByID(i);
		out << "- Kontonr.: " << std::left << std::setw(12) << tAccountInCustomerArray->getAccountNumber() << std::setw(12) << " (Kontostand:     ";
		tAccountInCustomerArray->getAccountAmount().print();
		out << ")\n";
	}

	out << "\n";
	return out;
}
