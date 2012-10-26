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

#ifndef  CAKE_H   // preprocessor directive
#define  CAKE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Cake
{
protected:
	int volume;
	double unitPrice;
	double totalPrice;
	string cakeId;

public:
	Cake();
	Cake(string, double);
	virtual ~Cake();
	string getCakeId();
	virtual void printInfo();
	virtual double computeTotalPrice()=0;
};

#endif
