/*
 * TSavingsAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#include "TSavingsAccount.h"
#include <iomanip>
TSavingsAccount::TSavingsAccount(TCustomer* customer, TBank* bank,
		char* accountNumber, char* pin, double zinsSatz) :
		TAccount(customer, bank, accountNumber, pin) {

	this->zinsSatz = zinsSatz;
}

TSavingsAccount::~TSavingsAccount() {
	TAccount::printLastMessage("TSavingsAccount", "Sparbuchkonto");
}

int TSavingsAccount::addBooking(TBooking* b) {
	if (b->getCreditor() == this) {
		if ((getAccountAmount().getAmount() + b->getAmount().getAmount()) < 0)
			return 1;
	} else {
		return TAccount::addBooking(b);
	}
	return 0;
}

double TSavingsAccount::getZinsSatz() {
	return zinsSatz;
}
void TSavingsAccount::setZinsSatz(double zinsSatz) {
	this->zinsSatz = zinsSatz;
}

void TSavingsAccount::printAccountStatement(){
	TAccount::printAccountStatement();
	cout << "Zinssatz: " << TSavingsAccount::getZinsSatz() << " %";
	std::cout << endl;
}

void TSavingsAccount::print() {
	TAccount::print();
	cout << "Zinssatz: " << TSavingsAccount::getZinsSatz() << " %";
	std::cout << endl;
}
