/*
 * TCurrentAccount.h
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#ifndef TCURRENTACCOUNT_H_
#define TCURRENTACCOUNT_H_

#include "TAccount.h"

class TCurrentAccount : virtual public TAccount {
public:
	TCurrentAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, TMoney* dispo);
	virtual ~TCurrentAccount();
	void setAccountDispoCredit(TMoney* accountDispoCredit);
	TMoney* getAccountDispoCredit();
	void print();
	virtual void printAccountStatement();
	int addBooking(TBooking* b);

private:
	TMoney* accountDispoCredit;
};

#endif /* TCURRENTACCOUNT_H_ */
