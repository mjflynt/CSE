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

#ifndef  CYLINDERCAKE_H   // preprocessor directive
#define  CYLINDERCAKE_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Cake.h"

using namespace std;

class CylinderCake : public Cake
{
private:
	int radius;
	int height;

public:
	CylinderCake(string, double, int, int);
	~CylinderCake();
	double computeTotalPrice();
	void printInfo();
};

#endif
