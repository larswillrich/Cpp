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
	this->printed_cre = 1; //0 wahr, anderes: falsch.... ausgedruckt = true = 0
	this->printed_deb = 1; //0 wahr, anderes: falsch.... ausgedruckt = true = 0

	//Kreditüberlastung bei TCurrentAccount oder Nulldurchgang bei TSavingsAccount
	if (creditor->addBooking(this) == 1 || depitor->addBooking(this) == 1){
		return;
	}

}

TBooking::~TBooking() {
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

int TBooking::getPrinted(TAccount* acc) const{
	if (this->getCreditor() == acc){
		return printed_cre;
	}else{
		return printed_cre;
	}
}

void TBooking::setPrinted(int printed_cre, TAccount* acc){
	if (this->getDepitor() == acc){
		this->printed_cre = printed_deb;
	}else{
		this->printed_cre = printed_deb;
	}

}

TTime TBooking::getTime() const {
	return time;
}

void TBooking::setTime(TTime time) {
	this->time = time;
}

void TBooking::print() {

}
