/*
 * MyXML.cpp
 *
 *  Created on: 03.12.2012
 *      Author: Lars Willrich
 */

#include "MyXML.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "TMoney.h"
MyXML::MyXML() {

}

MyXML::~MyXML() {
	// TODO Auto-generated destructor stub
}

string MyXML::getTagContent() const {
	return tagContent;
}

void MyXML::setTagContent(string tagContent) {
	this->tagContent = tagContent;
}

string MyXML::getTagValue() const {
	return tagValue;
}

void MyXML::setTagValue(string tagValue) {
	this->tagValue = tagValue;
}
bool MyXML::isBranch() const {
	return listOfInternBranch.size() > 0;
}
void MyXML::addXMLTag(MyXML* x) {
	listOfInternBranch.push_back(x);
}
list<MyXML*> MyXML::getList() {
	return listOfInternBranch;
}
void MyXML::setList(list<MyXML*> l) {
	listOfInternBranch = l;
}

void MyXML::print() {
	//MyXML* a = ListOfInternBranch.pop_back();

	if (listOfInternBranch.size() == 0) {
		cout << tagValue << ": ";
		cout << tagContent << endl;
	} else {
		cout << "\n" << tagValue << "\n============ " << endl;

		list<MyXML*>::iterator i;
		for (i = listOfInternBranch.begin(); i != listOfInternBranch.end();
				++i) {
			MyXML* tmp = *i;
			if (tmp == NULL)
				continue;
			tmp->print();
		}
	}
}

vector<TTransaction*>* MyXML::toTransactionVector() {

	vector<TTransaction*>* v = new vector<TTransaction*>;
	MyXML* r = (*this)[0];

	if (r->getTagValue().compare("Transactionlist")) {
		list<MyXML*> transactionList = r->getList();

		list<MyXML*>::iterator transactionList_it;

		for (transactionList_it = listOfInternBranch.begin();
				transactionList_it != listOfInternBranch.end();
				++transactionList_it) {
			MyXML* transaction = *transactionList_it;
			list<MyXML*> transaction_data = transaction->getList();

			TTransaction* t = new TTransaction();

			list<MyXML*>::iterator transaction_it;
			for (transaction_it = transaction_data.begin();
					transaction_it != transaction_data.end();
					++transaction_it) {

				MyXML* tmp = *transaction_it;

				if (tmp->getTagValue().compare("AccountNr") == 0) {
					//cout << "AccountNr" << ":" << tmp->getTagContent() << endl;
					t->setAccountNr(tmp->getTagContent());
				} else if (tmp->getTagValue().compare("BLZ") == 0) {
					//cout << "BLZ" << ":" << tmp->getTagContent() << endl;
					t->setBLZ(tmp->getTagContent());
				} else if (tmp->getTagValue().compare("ContraAccountNr") == 0) {
					//cout << "ContraAccountNr" << ":" << tmp->getTagContent()
					//		<< endl;
					t->setContraAccountNr(tmp->getTagContent());
				} else if (tmp->getTagValue().compare("ContraBLZ") == 0) {
					//cout << "ContraBLZ" << ":" << tmp->getTagContent() << endl;
					t->setContraBlz(tmp->getTagContent());
				} else if (tmp->getTagValue() == "Money") {

					//cout << "Money:" << endl;


					list<MyXML*>::iterator money_it;

					list<MyXML*> moneyList = tmp->getList();
					double amount;
					const char* currency;
					for (money_it = moneyList.begin();
							money_it != moneyList.end(); ++money_it) {

						MyXML* tmp_money = *money_it;


						if (tmp_money->getTagValue().compare("Amount") == 0) {
							//cout << "Amount" << ":" << tmp_money->getTagContent() << endl;
							amount = atof(tmp_money->getTagContent().c_str());
						} else if (tmp_money->getTagValue().compare("Currency") == 0) {
							//cout << "Currency" << ":" << tmp_money->getTagContent() << endl;
							currency = tmp_money->getTagContent().c_str();
						}

					}

					TMoney* moneyObj = new TMoney(amount, currency);
					//moneyObj->print();
					t->setAmount(moneyObj);
				} else if (tmp->getTagValue().compare("Text") == 0) {
					//cout << "Text" << ":" << tmp->getTagContent() << endl;
					t->setText(tmp->getTagContent());
				}
			}
			v->push_back(t);
		}
	}

	return v;
}
