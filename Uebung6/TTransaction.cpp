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

string TTransaction::getAccountNr() const {
	return accountNr;
}

void TTransaction::setAccountNr(string accountNr) {
	this->accountNr = accountNr;
}

string TTransaction::getBLZ() const {
	return bLZ;
}

void TTransaction::setBLZ(string blz) {
	bLZ = blz;
}

string TTransaction::getContraAccountNr() const {
	return contraAccountNr;
}

void TTransaction::setContraAccountNr(string contraAccountNr) {
	this->contraAccountNr = contraAccountNr;
}

string TTransaction::getContraBLZ() const {
	return contraBLZ;
}

void TTransaction::setContraBLZ(string contraBlz) {
	contraBLZ = contraBlz;
}

string TTransaction::getText() const {
	return text;
}

void TTransaction::setText(string text) {
	this->text = text;
}

TMoney* TTransaction::getAmount() const{
	return this->amount;
}
void TTransaction::setAmount(TMoney* amount){
	this->amount = amount;
}
