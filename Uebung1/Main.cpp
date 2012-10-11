/*
 * Main.cpp
 *
 *  Created on: 06.10.2012
 *      Author: Lars Willrich
 */

#include <iostream>
using namespace std;
#include "tdate.h"
#include "ttime.h"
int main() {
	TDate D1, D2(3, 3, 2012);
	TTime T1, T2(12, 10, 0);

	cout << "\nKlasse TDate:" << endl;
	cout << "Standardkonstruktor 	Heutiges Datum D1: \t";
	D1.print();
	cout << endl;
	cout << "Konstruktor 		Tag der Einheit (D2): \t";
	D2.print();
	cout << endl;

	cout << "\nKlasse TTime:" << endl;
	cout << "Standardkonstruktor 	Aktuelle Uhrzeit T1: \t";
	T1.print();
	cout << endl;
	cout << "Konstruktor 		Uebungsbeginn (T2): \t";
	T2.print();
	cout << endl;

	return 0;
}
