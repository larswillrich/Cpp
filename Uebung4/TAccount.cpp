/*
 * TAccount.cpp
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#include "TAccount.h"
#include <iostream>
#include <math.h>
#include <iomanip>
TMoney getSignValueFromBookingByAccount(TAccount* acc, TBooking* b);
char negZeichen(TMoney m);

TAccount::TAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin) :
		accountAmount(0, "EUR"), bank(bank), bookingsCount(0) {
	this->accountNumber = accountNumber;
	this->pin = pin;
	this->bookingsCount = 0;
	this->customer = customer;

	//Dem Kunden das Konto hinzufügen
	customer->addNewAccount(this);

	//Der Bank das Konto hinzufügen
	bank->addAccount(this);
}

void TAccount::printLastMessage(string klasse, string kontenart){
	klasse += ":";
	cout << std::left << std::setw(25) << klasse << std::setw(20) << kontenart << "(KtoNr. " << getAccountNumber() << ") wird vernichtet!" << endl;
}

TAccount::~TAccount() {
	printLastMessage("TAccount", "Konto");
	for (int i = 0;i<getBookingsCount();i++){
		delete getBookings()[i];
	}
}

TMoney TAccount::getAccountAmount() const {
	return accountAmount;
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

TBooking** TAccount::getBookings() {
	return bookings;
}

int TAccount::getBookingsCount() const {
	return bookingsCount;
}

int TAccount::addBooking(TBooking* b) {
	if (bookingsCount >= MAXBOOKING)
		return -1;

	bookings[bookingsCount] = b;
	bookingsCount++;

	if (b->getCreditor() == this)
		accountAmount.addValue(b->getAmount().getAmount());
	else
		accountAmount.addValue(b->getAmount().getAmount() * (-1));

	return 0;
}

int TAccount::removeBooking(TBooking* b) {

	if (b->getCreditor() != this)
		accountAmount.addValue(b->getAmount().getAmount());
	else
		accountAmount.addValue(b->getAmount().getAmount() * (-1));

	bookings[bookingsCount] = NULL;
	bookingsCount--;
	return 0;
}

void TAccount::printAccountStatement() {

	//Kontoauszug erstellen...

	TTime t_current;
	TDate d_current;

	cout << "Kontoauszug vom " << d_current.toString() << "; " << t_current.toString() << "\n";
	cout << "Kontonr.: " << getAccountNumber() << "; BLZ " << getBank()->getBlz() << "\n";
	cout << "Kontoinhaber: " << getCustomer()->getName() << "\n";

	std::cout << std::left << std::setw(11) << "Datum" << std::left
			<< std::setw(17) << "| Betrag" << std::left << std::setw(33)
			<< "| Absender / Empfaenger" << std::left << std::setw(14)
			<< "| Buchungstext" << endl;

	std::cout << setfill('-') << std::left << std::setw(11) << "" << std::left
			<< std::setw(17) << "|" << std::left << std::setw(33) << "|"
			<< std::left << std::setw(14) << "|" << endl;

	std::cout << setfill(' ');

	int bookingsAvailable = -1;
	for (int i = 0; i < getBookingsCount(); i++) {

		if (getBookings()[i]->getPrinted(this) != 0) {
			bookingsAvailable = 0;
			//Kontoauszug...

			TMoney a = getBookings()[i]->getAmount();

			TMoney m = getSignValueFromBookingByAccount(this, getBookings()[i]);
			double dABS = fabs(m.getAmount());
			char negSign = negZeichen(m);

			TCustomer* sender = (getBookings()[i]->getDepitor()->getCustomer() == getCustomer()) ? getBookings()[i]->getCreditor()->getCustomer() : getBookings()[i]->getDepitor()->getCustomer();
			std::cout << std::left << std::setw(9)
					<< getBookings()[i]->getDate().toString() << " | "
					<< std::left << std::setw(0) << negSign << std::right
					<< std::setw(9) << dABS << " " << m.getCurrency() << " | "
					<< std::left << std::setw(30)
					<< sender->getName()
					<< " | " << std::left << std::setw(14)
					<< getBookings()[i]->getMemo() << endl;

			//std::setprecision( 24 )
			//Am Ende wurde der Kontoauszug gedruckt
			//und die Buchung wird gekennzeichnet
			getBookings()[i]->setPrinted(0, this);
		}
	}


	if (bookingsAvailable == -1){
		//Keine Buchungen vorhanden
		cout << "keine neuen Buchungen vorhanden!\n";
	}

	std::cout << setfill('-') << std::left << std::setw(11) << "" << std::left
			<< std::setw(17) << "|" << std::left << std::setw(33) << "|"
			<< std::left << std::setw(14) << "|" << endl;

	cout << "aktueller Kontostand: " << getAccountAmount().toString() << "\n";

	cout << setfill(' ') << flush;
}

TMoney getSignValueFromBookingByAccount(TAccount* acc, TBooking* b) {

	if (acc == b->getCreditor())
		return b->getAmount();
	else
		return TMoney(b->getAmount().getAmount() * (-1),
				b->getAmount().getCurrency());
}

void TAccount::print() {

	//Daten des Kunden ausgeben
	getCustomer()->print();

	//Kontospezifische Daten ausgeben

	cout << "Kontonr.:\t" << getAccountNumber() << "\n";
	cout << "Anz. Buchungen:\t" << getBookingsCount() << "\n";
	cout << "Kontostand:\t";
	getAccountAmount().print();
	cout << "\n";
}

