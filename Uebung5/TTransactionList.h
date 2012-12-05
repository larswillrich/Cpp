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
	MyXML* travers(string::iterator* it_p, string* s, int* depth);
	int getTransactionsCount();

	TTransaction operator[](int index){

		int counter = 0;
		vector<TTransaction*>::iterator i;
		for (i = myTransactionVector.begin(); i != myTransactionVector.end(); ++i){
			if (counter == index) return **i;
			counter++;
		}

		return *(new TTransaction());
	}

private:
	vector<TTransaction*> myTransactionVector;
};

#endif /* TTRANSACTIONLIST_H_ */
