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
	TAccount(TCustomer* customer, TBank* bank, string accountNumber, string pin);

	virtual ~TAccount();

	TMoney getAccountAmount() const;
	string getAccountNumber() const;
	void setAccountNumber(string accountNumber);
	TCustomer* getCustomer() const;
	void setCustomer(TCustomer* customer);
	int getNumberBookings() const;
	void setNumberBookings(int numberBookings);
	string getPin() const;
	void setPin(string pin);
	void print();
	void printLastMessage(string klasse, string kontenart);
	TBank* getBank() const;
	void setBank(TBank* bank);
	TBooking** getBookings();
	char negZeichen(TMoney m);

	int addBooking(TBooking* b);
	int removeBooking(TBooking* b);
	int getBookingsCount() const;
	virtual void printAccountStatement();


private:

	TCustomer* customer;
	string accountNumber;
	string pin;
	TMoney accountAmount;

	//Uebung 3
	TBooking* bookings[MAXBOOKING];
	TBank* bank;
	int bookingsCount;
};

#endif /* TACCOUNT_H_ */
