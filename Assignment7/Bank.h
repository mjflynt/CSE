// Assignment #: 7
// Name: Michael Jeffrey Flynt
// Email Address: mflynt@asu.edu

#include <iostream>
#include <string>
#include <cstdlib>
#include "Address.h"

using namespace std;

#ifndef  BANK_H   // preprocessor directive
#define  BANK_H

class Bank
{
private:
	string bankName;
	Address * bankAddress;
	int bankID;

public:
	Bank();
	~Bank();
	string getBankName();
	Address * getBankAddress();
	int getBankID();
	void setBankName(string n);
	void setAddress(string c, string s);
	void setBankID(int ID);
	void printInfo();
};

#endif
