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
	TDate Datum1(7, 7, 1977);
	TDate Datum2(8, 8, 1988);
	TCustomer Bundesdruckerei("Geldquelle", TDate(), "", "", "", "");
	TCustomer Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889", "Musterstadt");
	TCustomer Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999", "Berlin");
	TBank Bank1("Berliner Bank", "10020000");
	TAccount Geldquelle(&Bundesdruckerei, &Bank1, "0", "0000");
	TAccount Konto1(&Kunde1, &Bank1, "1234567890", "9999");
	TAccount Konto2(&Kunde2, &Bank1, "9876543120", "0101");
	TAccount Konto3(&Kunde1, &Bank1, "111333555", "1357");
	TMoney asdadasd(150.0);
	TBooking Buchung1(TMoney(150.0), &Konto1, &Geldquelle, TDate(), TTime(), string("Startguthaben"));
	TBooking Buchung2(TMoney(50.0), &Konto3, &Konto1, TDate(), TTime(), string("Umbuchung"));
	TBooking Buchung3(TMoney(39.9), &Konto2, &Konto1, TDate(), TTime(), string("Rechnung 4711"));
	// Ausgaben:
	cout << "Kunde 1:" << endl; Kunde1.print(); cout << endl;
	cout << "Kunde 2:" << endl; Kunde2.print(); cout << endl;
	cout << "Bank 1: " << endl; Bank1.print(); cout << endl;
	Konto1.printAccountStatement();
	Konto1.printAccountStatement(); // darf die Buchungen nicht noch einmal ausdrucken!
	return 0;
}
