/*
 * TTransactionList.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#include "TTransactionList.h"
#include <iostream>
#include <iomanip>

string travers_takeBeginningTag(string::iterator* it_p);
string travers_takeTagValue(string::iterator* it_p);
string travers_takeClosedTAg(string::iterator* it_p);
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

		//cout << setw(*depth * 3) << "" << "<" << tagName << ">";
		m->setTagValue(tagName);
		++(*it);
		//====================


		//Beginning further Tags
		//====================
		int travers = -1;
		if (*(*it) == '<') {

		//	cout << endl;
			MyXML* mt = this->travers(it, s, &(++(*depth)));
			//mt->print();
			//cout << endl;
			m->addXMLTag(mt);
			//m->setList(mt->getList());
			travers = 0;
		}
		//====================


		//Take TagValue
		//====================
		string tagValue = "";
		for (; *(*it) != '<'; ++(*it)) {
			tagValue += *(*it);
		}


		if (travers == -1){
			m->setTagContent(tagValue);
			//cout << tagValue;
		}
		*it = *it + 2;
		//====================


		//Closed Tag
		//====================
		string tagName2 = "";
		for (; *(*it) != '>'; ++(*it)) {
			tagName2 += *(*it);
		}

		//if (travers == -1)
		//	cout << "</" << tagName2 << ">" << endl;
		//else
		//	cout << setw(*depth * 3) << "" << "</" << tagName2 << ">" << endl;
		++(*it);
		//====================

		if (*(*it) == '<' && *((*it) + 1) == '/') {
			*depth = *depth - 1;
			r->addXMLTag(m);
			return r;
		}
		r->addXMLTag(m);
		//r->print();
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

	transactionList->print();

/*
	transactionList->getTagContent();
	MyXML* transaction = (*transactionList)[0];
	transaction->getTagContent();
	MyXML* a1 = (*transaction)[0];
	a1->getTagContent();

	MyXML* a2 = (*transaction)[1];
	a2->getTagContent();*/
	//myTransactionVector.push_back(t);
}

TTransactionList::~TTransactionList() {
	// TODO Auto-generated destructor stub
}

