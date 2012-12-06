/*
 * TTransaction.h
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#ifndef TTRANSACTION_H_
#define TTRANSACTION_H_
#include "TMoney.h"
#include <string>

using namespace std;
class TTransaction {
public:
	TTransaction();
	virtual ~TTransaction();

	string getAccountNr() const;
	void setAccountNr(string accountNr);
	string getBLZ() const;
	void setBLZ(string blz);
	string getContraAccountNr() const;
	void setContraAccountNr(string contraAccountNr);
	string getContraBLZ() const;
	void setContraBLZ(string contraBlz);
	string getText() const;
	void setText(string text);
	TMoney* getAmount() const;
	void setAmount(TMoney* amount);


private:
	string accountNr;
	string bLZ;
	string contraBLZ;
	string contraAccountNr;
	TMoney* amount;
	string text;
};

#endif /* TTRANSACTION_H_ */
