/*
 * TCustomer.cpp
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#include "TCustomer.h"
#include <iostream>

TCustomer::TCustomer(char* name, TDate birthday, char* street, char* streetnumber, char* plz, char* city) : numberTAccounts(0){
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
	return numberTAccounts;
}

void TCustomer::setNumberTAccounts(int numberTAccounts) {
	this->numberTAccounts = numberTAccounts;
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
	if (numberTAccounts >= MAXCACCOUNTS) return;

	tAccountArray[numberTAccounts] = acc;
	numberTAccounts++;
}


TAccount* TCustomer::getAccountByID(int id){
	if (id > MAXCACCOUNTS || id < 0) return NULL;

	return tAccountArray[id];
}

void TCustomer::print(){
	cout << "Kunde:" << "\n";
	cout << getName() << "\n";
	cout << getStreet() << " " << getStreetnumber() << "\n";
	cout << getPlz() << " " << getCity() << "\n";
	cout << "geboren am: ";
	getBirthday().print();
	cout << "\n";

	//Ausgabe Konten
	cout << "Konten: " << "\n";
	for (int i = 0; i < numberTAccounts ; i++) {
		cout << "- Kontonr.: " << tAccountArray[i]->getAccountNumber() << "\n";
	}
}
