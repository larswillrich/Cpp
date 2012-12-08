using namespace std;
#include <iostream>
#include "TESTKLASSE.h"

using namespace std;

void fkt(TESTKLASSE k);
int main() {

	TESTKLASSE t;
	//fkt(t);

	cout << t << endl;
}

void fkt(TESTKLASSE k){

	cout << "fkt" << endl;
	k.run();
	return;
}
