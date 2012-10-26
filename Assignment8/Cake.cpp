// Assignment #: 8
//         Name: Michael Jeffrey Flynt
// EmailAddress: mflynt@asu.edu
//  Description: It displays a menu of choices
//               (add cylinder cakes or box cakes,
//               compute their total price, search a cake, list cakes,
//               quit, display menu) to a user.
//               Then it performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

#include "Cake.h"
	
	// make a Cake with default values.
	Cake::Cake()
	{
		cakeId = "?";
		Cake::unitPrice = 0.0;
	}

	// make a cake with specified id and unit price.
	Cake::Cake(string id, double uPrice)
	{
		cakeId = id;
		unitPrice = uPrice;
		volume = 0;
		totalPrice = 0.0;
	}

	// destroy a cake. This is virtual so the polymorphic derived class' destructors get called.
	Cake::~Cake() 
	{
		// cout << "destroying a cake!" << endl;
	}

	// just returns the cakeId.
	string Cake::getCakeId()
	{
		return cakeId;
	}

	// this is the base class Cake's printInfo which is also referenced in the derived classes.
	void Cake::printInfo()
	{
		// You can make use of string manipulators fixed and setprecision in iomanip.h file
		cout << "\nThe CakeId:\t\t" << cakeId << "\n"; 
		cout << "The Volume:\t\t" << volume << "\n";
		cout << "The Unit Price:\t\t" << fixed << setprecision(3) << unitPrice << "\n"; 
		cout << "The Total Price:\t$" << fixed << setprecision(2) << totalPrice << "\n\n";
	}
