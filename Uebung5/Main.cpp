#include <iostream>
using namespace std;
#include "tdate.h"
#include "tmoney.h"
#include "tcustomer.h"
#include "tbank.h"
#include "taccount.h"
#include "tbooking.h"
#include "ttransaction.h"
#include "ttransactionlist.h"
#include "TCurrentAccount.h"
#include "TFixedDepositAccount.h"
#include "TCurrentAccount.h"

TBank *getBank(TBank *, TBank *, string);
int main() {
	char *Dateiname = (char *) "transactions.list";
	TDate Datum1(7, 7, 1977);
	TDate Datum2(8, 8, 1988);
	TDate Datum3(6, 6, 1966);
	TCustomer Bundesdruckerei("Geldquelle", TDate(), "", "", "", "");
	TCustomer Kunde1("Egon Muster", Datum1, "Mustergasse", "3a", "99889",
			"Musterstadt");
	TCustomer Kunde2("Rudolph Rednose", Datum2, "Berliner Str.", "17", "10999",
			"Berlin");
	TCustomer Kunde3("Karin Kunze", Datum3, "Muenchner Str.", "39", "90123",
			"Muenchen");
	TBank *Bank = NULL;
	TBank *Bank1 = new TBank("Berliner Bank", "10020000");
	TBank *Bank2 = new TBank("Muenchner Bank", "10090099");
	TAccount *Geldquelle = new TAccount(&Bundesdruckerei, Bank1, "0", "0000");
	TAccount *Konto1 = new TCurrentAccount(&Kunde1, Bank1, "1234567890", "9999",
			new TMoney(100.0));
	TAccount *Konto2 = new TSavingsAccount(&Kunde2, Bank1, "9876543120", "0101",
			1.5);
	TAccount *Konto3 = new TFixedDepositAccount(&Kunde1, Bank2, "111333555",
			"1357", new TMoney(100.0), 1.5);
	TAccount *Konto4 = new TCurrentAccount(&Kunde3, Bank2, "999777555", "4444",
			new TMoney(200.0));
	TTransactionList TL(Dateiname);
}
