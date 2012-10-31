/*
 * TAccount.cpp
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#include "TAccount.h"
#include <iostream>

TAccount::TAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin) : accountAmount(0,"EUR"), bank(bank), bookingsCount(0) {
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

char* TAccount::getPin() const {
	return pin;
}

void TAccount::setPin(char* pin) {
	this->pin = pin;
}

TBank* TAccount::getBank() const {
	return bank;
}

void TAccount::setBank(TBank* bank) {
	this->bank = bank;
}

TBooking** TAccount::getBookings(){
	return bookings;
}

int TAccount::getBookingsCount() const {
	return bookingsCount;
}

void TAccount::printAccountStatement(){

	//Kontoauszug erstellen...

	for (int i = 0;i<getBookingsCount();i++){
		if (getBookings()[i]->getPrinted() != 0) {
			//Kontoauszug...


			//Am Ende wurde der Kontoauszug gedruckt
			//und die Buchung wird gekennzeichnet
			getBookings()[i]->setPrinted(0);
		}
	}
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

