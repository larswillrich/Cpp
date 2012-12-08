/*
 * TESTKLASSE.h
 *
 *  Created on: 08.12.2012
 *      Author: Lars Willrich
 */

#ifndef TESTKLASSE_H_
#define TESTKLASSE_H_
#include <iostream>
#include <list>
using namespace std;
class TESTKLASSE {
public:
	TESTKLASSE();
	virtual ~TESTKLASSE();
	friend ostream& operator<<(ostream & out, TESTKLASSE kl);
	void run();
};

#endif /* TESTKLASSE_H_ */
