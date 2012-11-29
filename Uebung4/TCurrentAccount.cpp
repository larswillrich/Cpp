/*
 * TCurrentAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#include "TCurrentAccount.h"

TCurrentAccount::TCurrentAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, TMoney* dispo ) : TAccount(customer, bank, accountNumber, pin), accountDispoCredit(dispo) {


}

TCurrentAccount::~TCurrentAccount() {
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
