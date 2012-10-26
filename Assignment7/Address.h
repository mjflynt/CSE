// Assignment #: 7
// Name: Michael Jeffrey Flynt
// Email Address: mflynt@asu.edu

#ifndef  ADDRESS_H   // preprocessor directive
#define  ADDRESS_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Address
{
private:
	string city;
	string state;
public:
	Address();
	~Address();
	string getCity();
	string getState();
	void setCity(string c);
	void setState(string s);
	void printInfo();
};

#endif
