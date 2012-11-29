/*
 * TSavingsAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#include "TSavingsAccount.h"

TSavingsAccount::TSavingsAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, double* zinsSatz) : TAccount(customer, bank, accountNumber, pin), zinsSatz(zinsSatz) {

}

TSavingsAccount::~TSavingsAccount() {
	delete zinsSatz;
	zinsSatz = NULL;
}

int TSavingsAccount::addBooking(TBooking* b){
	if (b->getCreditor() == this){
		if ((getAccountAmount().getAmount() + b->getAmount().getAmount()) < 0 ) return 1;
	}else{
		return TAccount::addBooking(b);
	}
	return 0;
}
