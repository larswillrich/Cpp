/*
 * TTransactionList.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#include "TTransactionList.h"
#include <iostream>
#include <iomanip>

MyXML* TTransactionList::travers(string::iterator* it_p, string* s, int* depth) {
	MyXML* r = new MyXML();

	string::iterator* it = it_p;

	while (*(*it) == '<') {
		MyXML* m = new MyXML();

		//TagName
		//====================
		string tagName = "";
		++(*it);

		for (; *(*it) != '>'; ++(*it))
			tagName += *(*it);

		m->setTagValue(tagName);
		++(*it);
		//====================


		//Beginning further Tags
		//====================
		int travers = -1;
		if (*(*it) == '<') {

			MyXML* mt = this->travers(it, s, &(++(*depth)));
			m->setList(mt->getList());


			travers = 0;
		}
		//====================


		//Take TagValue
		//====================
		string tagValue = "";
		for (; *(*it) != '<'; ++(*it))
			tagValue += *(*it);


		if (travers == -1)
			m->setTagContent(tagValue);

		*it = *it + 2;
		//====================


		//Closed Tag
		//====================
		for (; *(*it) != '>'; ++(*it));

		++(*it);
		//====================

		if (*(*it) == '<' && *((*it) + 1) == '/') {
			*depth = *depth - 1;
			r->addXMLTag(m);
			return r;
		}
		r->addXMLTag(m);
	}

	return r;
}

TTransactionList::TTransactionList(char* path) {

	string completeContent = "";
	string line;

	ifstream myFile(path);
	while (myFile.good()) {
		getline(myFile, line);
		completeContent += line;
	}

	myFile.close();
	string::iterator it = completeContent.begin();
	int depth = 1;
	MyXML* transactionList = travers(&it, &completeContent, &depth);

	//(*transactionList)[0]->print();

	vector<TTransaction*>* v = (*transactionList)[0]->toTransactionVector();
}

TTransactionList::~TTransactionList() {
	// TODO Auto-generated destructor stub
}

int TTransactionList::getTransactionsCount(){
	return this->myTransactionVector.size();
}

