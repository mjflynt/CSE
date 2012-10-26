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

#ifndef  BOXCAKE_H   // preprocessor directive
#define  BOXCAKE_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Cake.h"

using namespace std;

class BoxCake : public Cake
{
private:
	int height;
	int width;
	int depth;

public:
	BoxCake(string, double, int, int, int);
	~BoxCake();
	double computeTotalPrice();
	void printInfo();
};

#endif
