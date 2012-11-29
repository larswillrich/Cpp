/*
 * TSavingsAccount.h
 *
 *  Created on: 20.11.2012
 *      Author: Lars Willrich
 */

#ifndef TSAVINGSACCOUNT_H_
#define TSAVINGSACCOUNT_H_

#include "TAccount.h"
class TSavingsAccount  : public TAccount {
public:
	TSavingsAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin, double* zinsSatz);
	virtual ~TSavingsAccount();

	int addBooking(TBooking* b);
private:
	double* zinsSatz;
};

#endif /* TSAVINGSACCOUNT_H_ */
