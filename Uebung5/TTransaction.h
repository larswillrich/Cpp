/*
 * TTransaction.h
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#ifndef TTRANSACTION_H_
#define TTRANSACTION_H_
#include "TMoney.h"

class TTransaction {
public:
	TTransaction();
	virtual ~TTransaction();

	char* getAccountNr() const;
	void setAccountNr(char* accountNr);
	char* getBLz() const;
	void setBLz(char* blz);
	char* getContraAccountNr() const;
	void setContraAccountNr(char* contraAccountNr);
	char* getContraBlz() const;
	void setContraBlz(char* contraBlz);
	char* getText() const;
	void setText(char* text);
	TMoney* getAmount() const;
	void setAmount(TMoney* amount);

private:
	char* accountNr;
	char* bLZ;
	char* contraBLZ;
	char* contraAccountNr;
	TMoney* amount;
	char* text;
};

#endif /* TTRANSACTION_H_ */
