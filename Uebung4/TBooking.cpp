/*
 * TBooking.cpp
 *
 *  Created on: 31.10.2012
 *      Author: Lars Willrich
 */

#include "TBooking.h"

TBooking::TBooking(TMoney amount, TAccount* creditor, TAccount* depitor,
		TDate date, TTime time, string memo): amount(amount) {

	this->creditor = creditor;
	this->depitor = depitor;
	this->date = date;
	this->time = time;
	this->memo = memo;
	this->printed = 1; //0 wahr, anderes: falsch.... ausgedruckt = true = 0

	//Kreditüberlastung bei TCurrentAccount oder Nulldurchgang bei TSavingsAccount
	if (creditor->addBooking(this) == 1 || depitor->addBooking(this) == 1){
		return;
	}

}

TBooking::~TBooking() {
	// TODO Auto-generated destructor stub
}

TMoney TBooking::getAmount() const {
	return amount;
}

void TBooking::setAmount(TMoney amount) {
	this->amount = amount;
}

TAccount* TBooking::getCreditor() const {
	return creditor;
}

void TBooking::setCreditor(TAccount* creditor) {
	this->creditor = creditor;
}

TDate TBooking::getDate() const {
	return date;
}

void TBooking::setDate(TDate date) {
	this->date = date;
}

TAccount* TBooking::getDepitor() const {
	return depitor;
}

void TBooking::setDepitor(TAccount* depitor) {
	this->depitor = depitor;
}

string TBooking::getMemo() const {
	return memo;
}

void TBooking::setMemo(string memo) {
	this->memo = memo;
}

int TBooking::getPrinted() const {
	return printed;
}

void TBooking::setPrinted(int printed) {
	this->printed = printed;
}

TTime TBooking::getTime() const {
	return time;
}

void TBooking::setTime(TTime time) {
	this->time = time;
}

void TBooking::print() {

}
