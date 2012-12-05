/*
 * TMoney.cpp
 *
 *  Created on: 20.10.2012
 *      Author: Lars Willrich
 */

#include "TMoney.h"
#include <iostream>
#include <stdio.h>
using namespace std;

TMoney::TMoney(double amount, const char* currency) {
	this->amount = amount;
	this->currency = currency;
}

TMoney::~TMoney() {
}

double TMoney::getAmount(){
	return amount;
}

void TMoney::setAmount(double amount){
	this->amount = amount;
}

const char* TMoney::getCurrency(){
	return currency;
}

void TMoney::setCurrency(const char* currency){
	this->currency = currency;
}

void TMoney::addValue(double value){
	setAmount(getAmount() + value);
}

std::string TMoney::toString(){
	char buffer [30];
	sprintf (buffer, "%0.2f %s", getAmount(), getCurrency());

	std::string ret = buffer;
	return ret;
}

void TMoney::print(){
	printf("%0.2f %s", getAmount(), getCurrency());
}

