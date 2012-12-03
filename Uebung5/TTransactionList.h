/*
 * TTransactionList.h
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#ifndef TTRANSACTIONLIST_H_
#define TTRANSACTIONLIST_H_
#include "TTransaction.h"
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "MyXML.h"
#include "TMoney.h"

using namespace std;
class TTransactionList {
public:
	TTransactionList(char* path);
	virtual ~TTransactionList();
	void travers(string::iterator* it_p, string* s, int* depth);
private:
	vector<TTransaction*> myTransactionVector;
};

#endif /* TTRANSACTIONLIST_H_ */
