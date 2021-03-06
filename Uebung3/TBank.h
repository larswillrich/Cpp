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
#define tAccountInBankArray_MAX 10
class TBank {
public:
	TBank(char* name, char* blz);
	virtual ~TBank();

	int getAccountArrayCounter() const;
	char* getBlz() const;
	void setBlz(char* blz);
	char* getName() const;
	void setName(char* name);
	TAccount** getAccountArray();
	void addAccount(TAccount* acc);

	void print();

private:

	char* name;
	char* blz;
	TAccount* tAccountInBankArray[tAccountInBankArray_MAX];
	int accountsInBank_counter;
};

#endif /* TBANK_H_ */
