using namespace std;
#include <iostream>
#include "TDate.h"
#include "TMoney.h"
#include "TCustomer.h"
#include "TBank.h"
#include "TAccount.h"
#include "TBooking.h"
#include "TTransaction.h"
#include "TTransactionlist.h"
#include "TCurrentAccount.h"
#include "TSavingsAccount.h"
#include "TFixedDepositAccount.h"


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
	for (unsigned i = 0; i < TL.getTransactionsCount(); i++) {
		TAccount *Konto = NULL, *Gegenkonto = NULL;
		Konto = NULL;
		Bank = getBank(Bank1, Bank2, TL[i].getBLZ());
		if (Bank)
			Konto = Bank->getAccount(TL[i].getAccountNr());
		Gegenkonto = NULL;
		Bank = getBank(Bank1, Bank2, TL[i].getContraBLZ());
		if (Bank)
			Gegenkonto = Bank1->getAccount(TL[i].getContraAccountNr());
		if (Konto && Gegenkonto)
			TBooking *Buchung = new TBooking(*(TL[i].getAmount()), Konto,
					Gegenkonto, TL.getDate(), TL.getTime(), TL[i].getText());
	}

// Ausgaben:
	cout << "Transaktionsliste:" << endl << TL << endl;
	cout << "Kunde 1:" << endl << Kunde1 << endl;
	cout << "Kunde 2:" << endl << Kunde2 << endl;
	cout << "Kunde 3:" << endl << Kunde3 << endl;

	cout << "Bank 1: " << endl << *Bank1 << endl;
	cout << "Bank 2: " << endl << *Bank2 << endl;
	for (int i = 0; i < Bank1->getAccountCounter(); i++) {
		(Bank1->getAccountByID(i))->printAccountStatement();
		cout << endl;
	}
	for (int i = 0; i < Bank2->getAccountCounter(); i++) {
		(Bank2->getAccountByID(i))->printAccountStatement();
		cout << endl;
	}
	cout
			<< "Jetzt werden die Banken vernichtet und damit auch die Konten der Banken:"
			<< endl;
	delete Bank1;
	delete Bank2;
	return 0;
}
TBank *getBank(TBank *B1, TBank *B2, string BLZ) {
	if ((B1->getBLZ()).compare(BLZ) == 0)
		return B1;
	if ((B2->getBLZ()).compare(BLZ) == 0)
		return B2;
	return NULL;
}

