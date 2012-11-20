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
	TFixedDepositAccount();
	virtual ~TFixedDepositAccount();
};

#endif /* TFIXEDDEPOSITACCOUNT_H_ */
