/*
 * TFixedDepositAccount.cpp
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#include "TFixedDepositAccount.h"
#include <iomanip>
TFixedDepositAccount::TFixedDepositAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, TMoney* dispo, double zinsSatz)
	: TSavingsAccount(customer, bank, accountNumber, pin, zinsSatz),  TCurrentAccount(customer, bank, accountNumber, pin, dispo), TCurrentAccount::TAccount(customer, bank, accountNumber, pin) {
	this->setZinsSatz(zinsSatz);
}

TFixedDepositAccount::TFixedDepositAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin)
	: TSavingsAccount(customer, bank, accountNumber, pin, NULL),  TCurrentAccount(customer, bank, accountNumber, pin, NULL ), TCurrentAccount::TAccount(customer, bank, accountNumber, pin) {
}

TFixedDepositAccount::~TFixedDepositAccount() {
	TAccount::printLastMessage("TFixedDepositAccount", "Tagesgeldkonto");
}

void TFixedDepositAccount::printAccountStatement(){
	TSavingsAccount::TAccount::printAccountStatement();
	std::cout << "max. Dispo: ";
	TCurrentAccount::getAccountDispoCredit()->print();
	std::cout << endl;
	cout << "Zinssatz: " << TSavingsAccount::getZinsSatz() << " %";
	std::cout << endl;
}

void TFixedDepositAccount::print(){

	TSavingsAccount::TAccount::print();
	std::cout << "max. Dispo: ";
	TCurrentAccount::getAccountDispoCredit()->print();
	std::cout << endl;
	cout << "Zinssatz: " << TSavingsAccount::getZinsSatz() << " %";
	std::cout << endl;
}
