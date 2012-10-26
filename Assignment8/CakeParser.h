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

#ifndef  CAKEPARSER_H   // preprocessor directive
#define  CAKEPARSER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

#include "Cake.h"
#include "BoxCake.h"
#include "CylinderCake.h"

using namespace std;

class CakeParser
{
public:
	static Cake * parseStringToCake(string lineToParse);
};

#endif
