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
class TBank;
#include "TBank.h"
class TBooking;
#include "TBooking.h"

#define MAXBOOKING 10
using namespace std;

class TAccount {
public:
	TAccount(TCustomer* customer, TBank* bank, char* accountNumber, char* pin);

	virtual ~TAccount();

	TMoney getAccountAmount() const;
	char* getAccountNumber() const;
	void setAccountNumber(char* accountNumber);
	TCustomer* getCustomer() const;
	void setCustomer(TCustomer* customer);
	int getNumberBookings() const;
	void setNumberBookings(int numberBookings);
	char* getPin() const;
	void setPin(char* pin);
	void print();
	void printLastMessage(string klasse, string kontenart);
	TBank* getBank() const;
	void setBank(TBank* bank);
	TBooking** getBookings();

	int addBooking(TBooking* b);
	int removeBooking(TBooking* b);
	int getBookingsCount() const;
	virtual void printAccountStatement();


private:

	TCustomer* customer;
	char* accountNumber;
	char* pin;
	TMoney accountAmount;

	//Uebung 3
	TBooking* bookings[MAXBOOKING];
	TBank* bank;
	int bookingsCount;
};

#endif /* TACCOUNT_H_ */
