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

TMoney::TMoney(double amount, char* currency) {
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

char* TMoney::getCurrency(){
	return currency;
}

void TMoney::setCurrency(char* currency){
	this->currency = currency;
}

void TMoney::print(){
	printf("%.2f %s", getAmount(), getCurrency());
}

