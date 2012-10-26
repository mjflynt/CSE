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

#include "BoxCake.h"

	// make a BoxCake with the specific parameters.
	BoxCake::BoxCake(string id, double uPrice, int height2, int width2, int depth2) : Cake(id, uPrice)
	{
		height = height2;
		width = width2;
		depth = depth2;
	}

	// this destructor is called in a polymorphic way to destroy this BoxCake.
	BoxCake::~BoxCake()
	{
		cout << "Box Cake with the cake id: " << cakeId << " is being destroyed\n"; 
	}

	// computes the total price of this BoxCake in a polymorphic way.
	double BoxCake::computeTotalPrice()
	{
		volume = height * width * depth;
		totalPrice = volume * unitPrice;
		return totalPrice;
	}

	// this is the polymorphic printInfo called for a BoxCake type object. Note it refers to the base printInfo().
	void BoxCake::printInfo()
	{
		cout << "\nThe Box Cake\n";
		cout << "The Height:\t\t" << height << "\n";
		cout << "The Width:\t\t" << width << "\n";
		cout << "The Depth:\t\t" << depth;
		Cake::printInfo();
	}

