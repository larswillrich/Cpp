/*
 * TFixedDepositAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#include "TFixedDepositAccount.h"

TFixedDepositAccount::TFixedDepositAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, TMoney* dispo, double* zinsSatz)
	: TSavingsAccount(customer, bank, accountNumber, pin, zinsSatz),  TCurrentAccount(customer, bank, accountNumber, pin, dispo) {

}

TFixedDepositAccount::TFixedDepositAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin)
	: TSavingsAccount(customer, bank, accountNumber, pin, NULL),  TCurrentAccount(customer, bank, accountNumber, pin, NULL ) {

}

TFixedDepositAccount::~TFixedDepositAccount() {
	// TODO Auto-generated destructor stub
}

