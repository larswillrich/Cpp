/*
 * MyXML.cpp
 *
 *  Created on: 03.12.2012
 *      Author: Lars Willrich
 */

#include "MyXML.h"
#include <iostream>
#include <iomanip>
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
bool  MyXML::isBranch() const{
	return listOfInternBranch.size() > 0;
}
void  MyXML::addXMLTag(MyXML* x){
	listOfInternBranch.push_back(x);
}
list<MyXML*> MyXML::getList(){
	return listOfInternBranch;
}
void MyXML::setList(list<MyXML*> l){
	listOfInternBranch = l;
}

void MyXML::print(){
	//MyXML* a = ListOfInternBranch.pop_back();
	cout << tagValue << ": ";
	cout << tagContent << endl;
	list<MyXML*>::iterator i;

	for (i = listOfInternBranch.begin(); i != listOfInternBranch.end(); ++i){
		MyXML* tmp = *i;
		if (tmp == NULL) return;
		tmp->print();
	}
}
