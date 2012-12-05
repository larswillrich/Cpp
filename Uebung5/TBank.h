/*
 * TBank.h
 *
 *  Created on: 31.10.2012
 *      Author: Lars Willrich
 */

#ifndef TBANK_H_
#define TBANK_H_
class TAccount;
#include "TAccount.h"
#include <string>

#define tAccountInBankArray_MAX 10

using namespace std;
class TBank {
public:
	TBank(string name, string blz);
	virtual ~TBank();

	int getAccountArrayCounter() const;
	string getBLZ() const;
	void setBLZ(string blz);
	string getName() const;
	void setName(string name);
	TAccount** getAccountArray();
	void addAccount(TAccount* acc);

	void print();

private:

	string name;
	string blz;
	TAccount* tAccountInBankArray[tAccountInBankArray_MAX];
	int accountsInBank_counter;
};

#endif /* TBANK_H_ */
