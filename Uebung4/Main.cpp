/*
 * Main.cpp
 *
 *  Created on: 06.10.2012
 *      Author: Lars Willrich
 */

#include <iostream>
using namespace std;
#include "tdate.h"
#include "tmoney.h"
#include "tcustomer.h"
#include "tbank.h"
#include "taccount.h"
#include "TCurrentAccount.h"
#include "tbooking.h"
#include "TSavingsAccount.h"
#include "TFixedDepositAccount.h"

int main() {
	TDate Datum1(7, 7, 1977);
	TDate Datum2(8, 8, 1988);
	TCustomer Bundesdruckerei("Geldquelle", TDate(), "", "", "", "");
	TCustomer Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889", "Musterstadt");
	TCustomer Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999", "Berlin");
	TBank *Bank1 = new TBank("Berliner Bank", "10020000");
	TAccount *Geldquelle = new TAccount(&Bundesdruckerei, Bank1, "0", "0000");
	TCurrentAccount *Konto1 = new TCurrentAccount(&Kunde1, Bank1, "1234567890", "9999", new TMoney(100.0));
	TSavingsAccount *Konto2 = new TSavingsAccount(&Kunde2, Bank1, "9876543120", "0101", 1.5);
	TFixedDepositAccount *Konto3 = new TFixedDepositAccount(&Kunde1, Bank1, "111333555", "1357", new TMoney(100.0), 1.5);
	TBooking Buchung1(TMoney(150.0), Konto1, Geldquelle, TDate(), TTime(), string("Startguthaben"));
	TBooking Buchung2(TMoney(50.0), Konto3, Konto1, TDate(), TTime(), string("Umbuchung"));
	TBooking Buchung3(TMoney(39.9), Konto2, Konto1, TDate(), TTime(), string("Rechnung 4711"));
// Ausgaben:
	cout << "Kunde 1:" << endl;
	Kunde1.print();
	cout << endl;
	cout << "Kunde 2:" << endl;
	Kunde2.print();
	cout << endl;
	cout << "Bank 1: " << endl;
	Bank1->print();
	cout << endl;
	for (int i = 0; i < Bank1->getAccountArrayCounter(); i++) {
		(Bank1->getAccountArray()[i])->printAccountStatement();
		cout << endl;
	}
	cout << "Jetzt wird die Bank vernichtet und damit auch die Konten der Bank:" << endl;
	delete Bank1;
	return 0;
}
