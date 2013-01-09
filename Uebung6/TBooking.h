/*
 * TBooking.h
 *
 *  Created on: 31.10.2012
 *      Author: Lars Willrich
 */

#ifndef TBOOKING_H_
#define TBOOKING_H_

#include "TTime.h"
#include "TDate.h"
#include "TMoney.h"
class TAccount;
#include "TAccount.h"
#include <string>
using namespace std;

class TBooking {
public:
	TBooking(TMoney amount, TAccount* creditor, TAccount* depitor,
			TDate date, TTime time, string memo);
	//TMoney(39.9), &Konto2, &Konto1, TDate(), TTime(), string("Rechnung 4711")
	virtual ~TBooking();

	TMoney getAmount() const;
	void setAmount(TMoney amount);
	TAccount* getCreditor() const;
	void setCreditor(TAccount* creditor);
	TDate getDate() const;
	void setDate(TDate date);
	TAccount* getDepitor() const;
	void setDepitor(TAccount* depitor);
	string getMemo() const;
	void setMemo(string memo);
	int getPrinted(TAccount* acc) const;
	void setPrinted(int printed_cre, TAccount* acc);
	TTime getTime() const;
	void setTime(TTime time);

	void print();

private:

	TMoney amount;
	TAccount* creditor; //Kreditor (Gläubiger von Forderungen aus L. u. L.)
	TAccount* depitor; //Debitor (Schuldner von Forderungen aus L. u. L.)
	TDate date;
	TTime time;
	string memo;
	int printed_deb; //0 wahr, anderes: falsch.... ausgedruckt = true = 0
	int printed_cre; //0 wahr, anderes: falsch.... ausgedruckt = true = 0
};

#endif /* TBOOKING_H_ */
