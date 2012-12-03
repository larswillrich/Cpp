/*
 * TTransactionList.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#include "TTransactionList.h"
#include <iostream>
#include <iomanip>

void TTransactionList::travers(string::iterator* it_p, string* s, int* depth) {
	MyXML m;

	string::iterator* it = it_p;
	//for (; it != s->end(); ++it) {
	//while(counter != 0){
	//New TagName
	//TagName
	//-----------------------

	while (*(*it) == '<') {
		string tagName = "";
		++(*it);

		for (; *(*it) != '>'; ++(*it)) {
			tagName += *(*it);
		}

		if (*(*it) == '>') {
			cout  <<  setw(*depth * 3) << "" << "<" << tagName << ">" << endl;
			++(*it);
		}
		//-----------------------

		//Beginning further Tags
		int travers = -1;
		if (*(*it) == '<') {

			this->travers(it, s, &(++(*depth)));
			travers = 0;
			//continue;
			//Tag- Value
		}

		string tagValue = "";
		for (; *(*it) != '<'; ++(*it)) {
			tagValue += *(*it);
		}
		if (travers == -1)
			cout << setw(*depth * 4) << "" << tagValue << endl;

		if (*(*it) == '<' && *(++(*it)) == '/') {
			(*it)++;
		}

		string tagName2 = "";
		for (; *(*it) != '>'; ++(*it)) {
			tagName2 += *(*it);
		}
		if (*(*it) == '>') {
			cout << setw(*depth * 3) << "" << "</" << tagName2 << ">" << endl;
			++(*it);
		}
		if (*(*it) == '<' && *((*it) + 1) == '/') {
			*depth = *depth - 1;
			return;
		}
	}

	//Have to be the same as 'tagName'
	//End TagEnd
	//}
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
	travers(&it, &completeContent, &depth);

	//myTransactionVector.push_back(t);
}

TTransactionList::~TTransactionList() {
	// TODO Auto-generated destructor stub
}

