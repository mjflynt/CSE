// Assignment #: 7
// Name: Michael Jeffrey Flynt
// Email Address: mflynt@asu.edu

#include <iostream>
#include <string>
#include <cstdlib>

#include "Bank.h"

Bank::Bank()
{
	bankName = "?";
	bankID = 0;
	bankAddress = new Address();
}
Bank::~Bank()
{
	delete bankAddress;
	bankAddress = NULL;
	cout << "The bank " << bankName << " is getting destroyed." << endl;
}
string Bank::getBankName()
{
	return bankName;
}
Address * Bank::getBankAddress()
{
	return bankAddress;
}
int Bank::getBankID()
{
	return bankID;
}
void Bank::setBankName(string n)
{
	bankName = n;
}
void Bank::setAddress(string c, string s)
{
	bankAddress->setCity(c);
	bankAddress->setState(s);
}
void Bank::setBankID(int ID)
{
	bankID = ID;
}
void Bank::printInfo()
{
	cout << "\nBank Name:\t\t" << bankName << endl;
	cout << "Bank ID:\t\t" << bankID << endl;
	cout << "Bank Address:\t\t" << bankAddress->getCity() << "," << bankAddress->getState() << endl << endl;
}

