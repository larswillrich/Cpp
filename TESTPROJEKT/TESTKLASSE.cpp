/*
 * TESTKLASSE.cpp
 *
 *  Created on: 08.12.2012
 *      Author: Lars Willrich
 */

#include "TESTKLASSE.h"

TESTKLASSE::TESTKLASSE() {

	cout << "TESTKLASSE: Erstelle Klasse!" << endl;
}

TESTKLASSE::~TESTKLASSE() {
	cout << "TESTKLASSE: Lösche Klasse!" << endl;
}

void TESTKLASSE::run(){
	cout << "BLA" << endl;
}

ostream& operator<<(ostream & out, TESTKLASSE k1){
	cout << "TESTKLASSE: Operator Aufruf!" << endl;
	return out;
}
