/*
 * TCurrentAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#include "TCurrentAccount.h"
#include <iomanip>
TCurrentAccount::TCurrentAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, TMoney* dispo ) : TAccount(customer, bank, accountNumber, pin), accountDispoCredit(dispo) {


}

TCurrentAccount::~TCurrentAccount() {
	TAccount::printLastMessage("TCurrentAccount", "Girokonto");
	delete accountDispoCredit;
	accountDispoCredit = NULL;
}

void TCurrentAccount::setAccountDispoCredit(TMoney* accountDispoCredit){
	this->accountDispoCredit = accountDispoCredit;
}

TMoney* TCurrentAccount::getAccountDispoCredit(){
	return this->accountDispoCredit;
}

int TCurrentAccount::addBooking(TBooking* b){
	if (b->getCreditor() == this){
		if ((getAccountAmount().getAmount() + b->getAmount().getAmount()) * (-1) >= getAccountDispoCredit()->getAmount()) return 1;
	}else{
		return TAccount::addBooking(b);
	}
	return 0;
}

void TCurrentAccount::printAccountStatement(){
	TAccount::printAccountStatement();
	std::cout << "max. Dispo: ";
	TCurrentAccount::getAccountDispoCredit()->print();
	std::cout << endl;
}

void TCurrentAccount::print(){
	TAccount::print();
	std::cout << "max. Dispo: ";
	TCurrentAccount::getAccountDispoCredit()->print();
	std::cout << endl;
}
