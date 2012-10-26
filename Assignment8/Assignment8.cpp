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
#include <vector>
#include "Cake.h"
#include "CakeParser.h"

using namespace std;

void printMenu();


int main()
{
	char input1;
	string inputInfo;
	bool operation;
    double total;

	vector<Cake *> cakeList;


	printMenu();     // print out menu


	do
	{
		cout << "What action would you like to perform?" << endl;
		cin >> input1;
                input1 = toupper(input1);

		switch (input1)
		{
		case 'A':   //Add Cake
			cout << "Please enter a cake information to add:\n";
			cin >> inputInfo;
  /***********************************************************************************
  ADD your code here to create a pointer to an object of one of child classes of
  Cake class and add it to the cakeList
  ***********************************************************************************/
  			cakeList.push_back(CakeParser::parseStringToCake(inputInfo));
			break;


		case 'C':   //Compute Total Price
            total = 0;
  /***********************************************************************************
  ***  ADD your code here to compute the total price for each cake in the cakeList,
  ***  then add them to compute the total.
  ***********************************************************************************/
  				for(int i = 0; i <= cakeList.size() - 1; i++ )
  				{
  					total += cakeList[i]->computeTotalPrice();
  				}

			cout << "total price = $" << fixed << setprecision(2)
                             << total << "\n";
			break;


		case 'D':   //Search for Cake
			cout << "Please enter a cakeID to search:\n";
			cin >> inputInfo;
			operation = false;
  /***********************************************************************************
  ***  ADD your code here to search a given cakeID. If found, set "operation" true,
  ***  and set "operation" false otherwise.
  ***********************************************************************************/
  				// iterate thru the entire cakeList vector looking for the cake id.
  				for(int i = 0; i <= cakeList.size() - 1; i++ )
  				{
  					if(cakeList[i]->getCakeId() == inputInfo)
  					{
  						operation = true;
  					}
  				}

			if (operation == true)
				cout << "cake found\n";
			else
				cout << "cake not found\n";
			break;


		case 'L':   //List Cakes
  /***********************************************************************************
  ***  ADD your code here to print out all cake objects. If there is no cake,
  ***  print "no cake\n"
  ***********************************************************************************/
  			if(cakeList.size() > 0)
  			{
  				for(int i = 0; i <= cakeList.size() - 1; i++ )
  				{
  					cakeList[i]->printInfo(); // printinfo called from derived class.
  				}
  			}
  			else
  			{
  				cout << "no cake\n";
  			}
			break;


		case 'Q':   //Quit
		    //destroying all cakes in the cakeList
			for (int j=0; j < cakeList.size(); j++)
			{
				delete cakeList.at(j);
			}
			break;

		case '?':   //Display Menu
			printMenu();
			break;

		default:
			cout << "Unknown action\n";
			break;


		}

	} while (input1 != 'Q' && input1 != 'q'); // stop the loop when Q is read

}

/** The method printMenu displays the menu to a user **/
void printMenu()
{
	cout << "Choice\t\tAction\n";
	cout << "------\t\t------\n";
	cout << "A\t\tAdd Cake\n";
	cout << "C\t\tCompute Total Price\n";
	cout << "D\t\tSearch for Cake\n";
	cout << "L\t\tList Cakes\n";
	cout << "Q\t\tQuit\n";
	cout << "?\t\tDisplay Help\n\n";
}



