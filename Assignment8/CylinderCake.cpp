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

#include "Cake.h"

using namespace std;

#include "CylinderCake.h"

#define PI 3.14159

	// make a CylinderCake with the specific parameters.
	CylinderCake::CylinderCake(string id, double uPrice, int radius2, int height2) : Cake(id, uPrice)
	{
		radius = radius2;
		height = height2;
	}

	// this destructor is called in a polymorphic way to destroy this CylinderCake.
	CylinderCake::~CylinderCake()
	{
		cout << "Cylinder Cake with the cake id: " << cakeId << " is being destroyed\n";
	}

	// computes the total price of this CylinderCake in a polymorphic way.
	double CylinderCake::computeTotalPrice()
	{
		volume = (int)(PI * radius * radius * height);
		totalPrice = volume * unitPrice;
		return totalPrice;
	}

	// this is the polymorphic printInfo called for a CylinderCake type object. Note it refers to the base printInfo().
	void CylinderCake::printInfo()
	{
		cout << "\nThe Cylinder Cake\n"; 
		cout << "The Radius:\t\t" << radius << "\n";
		cout << "The Height:\t\t" << height;
		Cake::printInfo();
	}

