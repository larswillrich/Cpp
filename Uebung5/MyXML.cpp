/*
 * MyXML.cpp
 *
 *  Created on: 03.12.2012
 *      Author: Lars Willrich
 */

#include "MyXML.h"

MyXML::MyXML() {
	// TODO Auto-generated constructor stub

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
	return ListOfInternBranch.size() > 0;
}
void  MyXML::addXMLTag(MyXML* x){
	ListOfInternBranch.push_back(x);
}


