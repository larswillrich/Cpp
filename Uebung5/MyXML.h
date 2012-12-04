/*
 * MyXML.h
 *
 *  Created on: 03.12.2012
 *      Author: Lars Willrich
 */

#ifndef MYXML_H_
#define MYXML_H_
#include <string>
#include <list>

using namespace std;

class MyXML {
public:
	MyXML();
	virtual ~MyXML();

	string getTagContent() const;
	void setTagContent(string tagContent);
	string getTagValue() const;
	void setTagValue(string tagValue);
	bool isBranch() const;
	void addXMLTag(MyXML* x);
	void print();
	list<MyXML*> getList();
	void setList(list<MyXML*> l);
	MyXML* operator[](int index){

		int counter = 0;
		list<MyXML*>::iterator i;
		for (i = listOfInternBranch.begin(); i != listOfInternBranch.end(); ++i){
			if (counter == index) return *i;
			counter++;
		}

		return NULL;
	}

private:
	list<MyXML*> listOfInternBranch;
	string tagValue;
	string tagContent;
};

#endif /* MYXML_H_ */
