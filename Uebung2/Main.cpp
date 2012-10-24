/*
 * Main.cpp
 *
 *  Created on: 06.10.2012
 *      Author: Lars Willrich
 */

#include <iostream>
#include "tdate.h"
#include "ttime.h"
#include "TMoney.h"
#include "TCustomer.h"
#include "TAccount.h"

using namespace std;

int main() {
	TDate Datum(7, 7, 1977);
	TMoney Betrag1(150.0, "EUR");
	TCustomer Kunde1("Egon Muster", Datum, "Mustergasse", "3a", "99889", "Musterstadt");

	TAccount Konto1(&Kunde1, "1234567890", "9999");

	cout << "Betrag 1: " << endl; Betrag1.print(); cout << endl << endl;
	cout << "Kunde 1: " << endl; Kunde1.print(); cout << endl << endl;
	cout << "Konto 1; " << endl; Konto1.print(); cout << endl << endl;

	TAccount Konto2(&Kunde1, "9876543210", "0101");
	cout << "Kunde 1: " << endl; Kunde1.print(); cout << endl << endl;
	cout << "Konto 2; " << endl; Konto2.print(); cout << endl << endl;
	return 0;
}
