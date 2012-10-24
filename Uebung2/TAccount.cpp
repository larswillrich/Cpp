/*
 * TAccount.cpp
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#include "TAccount.h"
#include <iostream>

TAccount::TAccount(TCustomer* customer, char* accountNumber, char* pin) : accountAmount(0,"EUR") {
	this->accountNumber = accountNumber;
	this->pin = pin;
	this->numberBookings = 0;
	this->customer = customer;

	//Dem Kunden das Konto hinzufügen
	customer->addNewAccount(this);
}

TAccount::~TAccount() {
}

TMoney TAccount::getAccountAmount() const {
	return accountAmount;
}

void TAccount::setAccountAmount(TMoney accountAmount) {
	this->accountAmount = accountAmount;
}

char* TAccount::getAccountNumber() const {
	return accountNumber;
}

void TAccount::setAccountNumber(char* accountNumber) {
	this->accountNumber = accountNumber;
}

TCustomer* TAccount::getCustomer() const {
	return customer;
}

void TAccount::setCustomer(TCustomer* customer) {
	this->customer = customer;
}

int TAccount::getNumberBookings() const {
	return numberBookings;
}

void TAccount::setNumberBookings(int numberBookings) {
	this->numberBookings = numberBookings;
}

char* TAccount::getPin() const {
	return pin;
}

void TAccount::setPin(char* pin) {
	this->pin = pin;
}

void TAccount::print(){

	//Daten des Kunden ausgeben
	getCustomer()->print();

	//Kontospezifische Daten ausgeben

	cout << "Kontonr.:\t" << getAccountNumber() << "\n";
	cout << "Anz. Buchungen:\t" << getNumberBookings() << "\n";
	cout << "Kontostand:\t";
	getAccountAmount().print();
	cout << "\n";
}

