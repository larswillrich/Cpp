/*
 * TFixedDepositAccount.h
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#ifndef TFIXEDDEPOSITACCOUNT_H_
#define TFIXEDDEPOSITACCOUNT_H_

#include "TCurrentAccount.h"
#include "TSavingsAccount.h"
class TFixedDepositAccount : public TCurrentAccount, public TSavingsAccount {
public:
	TFixedDepositAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, TMoney* dispo, double* zinsSatz);
	TFixedDepositAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin);
	virtual ~TFixedDepositAccount();
};

#endif /* TFIXEDDEPOSITACCOUNT_H_ */
