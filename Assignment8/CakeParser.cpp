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
#include <cctype>

#include "Cake.h"
#include "BoxCake.h"
#include "CylinderCake.h"
#include "CakeParser.h"

using namespace std;


	// The CakeParser class is a utility class that will be used 
	// to create a pointer to a Cake object (one of a cylinder cake 
	// and a box cake) from a parsable string. The CakeParser class object will not be instantiated.
	Cake * CakeParser::parseStringToCake(string lineToParse)
	{
		string token[6] = {"", "", "", "", "", ""}; // places for up to six tokens in the input data.
		int currTokenSlot = 0;

		for(int i = 0; i < lineToParse.length(); i++)
		{
			if(lineToParse[i] != '/') // keep appending chars until a delim
				token[currTokenSlot].append(1, lineToParse[i]);	// sweet fuction allows adding a string of 1 repetions of the char!		
			else // if a delimeter is encountered then go to the next slot
				currTokenSlot++;
		}

		if (toupper(token[0][0]) == 'B') // If the upcase first char of the first slot is a 'B'
		{
			// it's a "Box!"
			// BoxCake(string id, double uPrice, int height2, int width2, int depth2)
			return new BoxCake(token[1], atof(token[2].c_str()), atoi(token[3].c_str()), atoi(token[4].c_str()), atoi(token[5].c_str()));
		}
		else // because it is guaranteed to be a "Box" or "Cylinder" and it isn't a "Box" then it is a "Cylinder!"
		{
			// it's a "Cylinder!"
			// CylinderCake(string id, double uPrice, int radius2, int height2) 
			return new CylinderCake(token[1], atof(token[2].c_str()), atoi(token[3].c_str()), atoi(token[4].c_str()));
		}
	}
