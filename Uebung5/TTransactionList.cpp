/*
 * TTransactionList.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#include "TTransactionList.h"
#include <iostream>
#include <iomanip>

MyXML* TTransactionList::travers(string::iterator* it_p, string* s,
		int* depth) {
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
		for (; *(*it) != '>'; ++(*it))
			;

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

	setDate(TDate());
	setTime(TTime());
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
	this->myTransactionVector = *v;
}

TTransactionList::~TTransactionList() {
	// TODO Auto-generated destructor stub
}

TDate TTransactionList::getDate() {
	return date;
}
TTime TTransactionList::getTime() {
	return time;
}
void TTransactionList::setDate(TDate d) {
	this->date = d;
}
void TTransactionList::setTime(TTime t) {
	this->time = t;
}

vector<TTransaction*> TTransactionList::getTransactions(){
	return myTransactionVector;
}

int TTransactionList::getTransactionsCount() {
	return this->myTransactionVector.size();
}

ostream& operator<<(ostream & out, TTransactionList tl){

	vector<TTransaction*>::iterator transaction_it;

	for (int i = 0;i<tl.getTransactionsCount();i++){
		out << std::setfill(' ') << "Transaction Nr. " << i+1 << endl;
		out  << std::left << std::setw(18) << "AccountNr =" << std::setw(18)   << tl[i].getAccountNr() << endl;
		out   << std::left << std::setw(18) << "BLZ ="  << std::setw(18)  << tl[i].getBLZ() << endl;
		out  << std::left << std::setw(18)<< "ContraAccountNr ="  << std::setw(18)  << tl[i].getContraAccountNr() << endl;
		out  << std::left << std::setw(18)<< "ContraBLZ ="  << std::setw(18)  << tl[i].getContraBLZ() << endl;
		out  << std::left << std::setw(18)<< "Amount =" << *(tl[i].getAmount()) << endl;
		out  << std::left << std::setw(18)<< "Text ="  << std::setw(18)  << tl[i].getText()  << "\n" << endl;
	}

	return out;
}


