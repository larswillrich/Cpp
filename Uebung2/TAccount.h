/*
 * TAccount.h
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */


#ifndef TACCOUNT_H_
#define TACCOUNT_H_

#include "TMoney.h"
class TCustomer;
#include "TCustomer.h"

using namespace std;

class TAccount {
public:
	TAccount(TCustomer* customer, char* accountNumber, char* pin);
	virtual ~TAccount();

	TMoney getAccountAmount() const;
	void setAccountAmount(TMoney accountAmount);
	char* getAccountNumber() const;
	void setAccountNumber(char* accountNumber);
	TCustomer* getCustomer() const;
	void setCustomer(TCustomer* customer);
	int getNumberBookings() const;
	void setNumberBookings(int numberBookings);
	char* getPin() const;
	void setPin(char* pin);
	void print();


private:
	TCustomer* customer;
	char* accountNumber;
	char* pin;
	int numberBookings;
	TMoney accountAmount;
};

#endif /* TACCOUNT_H_ */
