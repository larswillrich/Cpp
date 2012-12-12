/*
 * TCustomer.h
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#ifndef TCUSTOMER_H_
#define TCUSTOMER_H_

#include "TDate.h"
class TAccount;
#include "TAccount.h"
#include <iostream>
#include <list>
using namespace std;
#define tAccountInCustomerArray_MAX 10

class TCustomer {
public:
	TCustomer(char* name, TDate birthday, char* street, char* streetnumber, char* plz, char* city);

	virtual ~TCustomer();

	TDate getBirthday() const;
	void setBirthday(TDate birthday);
	char* getCity() const;
	void setCity(char* city);
	char* getName() const;
	void setName(char* name);
	int getNumberTAccounts() const;
	void setNumberTAccounts(int numberTAccounts);
	char* getPlz() const;
	void setPlz(char* plz) ;
	char* getStreet() const;
	void setStreet(char* street);
	char* getStreetnumber() const;
	void setStreetnumber(char* streetnumber);
	void addNewAccount(TAccount* acc);
	TAccount* getAccountByID(int id);
	void print();
	friend ostream& operator<<(ostream & out, TCustomer& tl);

private:

	char* name;
	char* street;
	char* streetnumber;
	char* plz;
	char* city;
	TDate birthday;
	int tAccountsInCustomer;
	TAccount* tAccountInCustomerArray[tAccountInCustomerArray_MAX];
};

#endif /* TCUSTOMER_H_ */
