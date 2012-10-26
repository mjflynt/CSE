// Assignment #: 7
// Name: Michael Jeffrey Flynt
// Email Address: mflynt@asu.edu

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "Address.h"


Address::Address()
{
	city = "?";
	state = "?";
}
Address::~Address()
{
	cout << "Address with the city " << city << " and the state " << state << " is being destroyed." << endl;
}
string Address::getCity()
{
	return city;
}
string Address::getState()
{
	return state;
}
void Address::setCity(string c)
{
	city = c;
}
void Address::setState(string s)
{
	state = s;
}
void Address::printInfo()
{
	cout << city << ", " << state << endl;
}

