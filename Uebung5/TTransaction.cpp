/*
 * TTransaction.cpp
 *
 *  Created on: 02.12.2012
 *      Author: Lars Willrich
 */

#include "TTransaction.h"

TTransaction::TTransaction() {
	// TODO Auto-generated constructor stub

}

TTransaction::~TTransaction() {
	// TODO Auto-generated destructor stub
}

char* TTransaction::getAccountNr() const {
	return accountNr;
}

void TTransaction::setAccountNr(char* accountNr) {
	this->accountNr = accountNr;
}

char* TTransaction::getBLz() const {
	return bLZ;
}

void TTransaction::setBLz(char* blz) {
	bLZ = blz;
}

char* TTransaction::getContraAccountNr() const {
	return contraAccountNr;
}

void TTransaction::setContraAccountNr(char* contraAccountNr) {
	this->contraAccountNr = contraAccountNr;
}

char* TTransaction::getContraBlz() const {
	return contraBLZ;
}

void TTransaction::setContraBlz(char* contraBlz) {
	contraBLZ = contraBlz;
}

char* TTransaction::getText() const {
	return text;
}

void TTransaction::setText(char* text) {
	this->text = text;
}

TMoney* TTransaction::getAmount() const{
	return this->amount;
}
void TTransaction::setAmount(TMoney* amount){
	this->amount = amount;
}
