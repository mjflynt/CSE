// Assignment #: 7
// Name:
// Email Address:
// Description: This program displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream>
#include <string>
#include <cstdlib>
#include "Bank.h"
#include "Address.h"

using namespace std;

void printMenu();

int main()
   {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string inputInfo;
       string bankName;
       int id;
       string city, state;
       string line;

       // instantiate a Bank object
       Bank * bank1 = new Bank();

       printMenu();


       do  // will ask for user input
        {
           cout << "What action would you like to perform?\n";
           cin.get(input1);
           input1 = toupper(input1);
           cin.ignore(20, '\n');
           // matches one of the case statement
           switch (input1)
            {
             case 'A':   //Add Bank
               cout << "Please enter a bank information:\n";
               cout << "Enter a bank name:\n";
               getline(cin, bankName);
               bank1->setBankName(bankName);

               cout << "Enter the ID for the bank:\n";
               cin >> id;
               cin.ignore(20, '\n');
               bank1->setBankID(id);

               cout << "Enter the city for the bank:\n";
               getline(cin, city);
               cout << "Enter the state for the bank:\n";
               getline(cin, state);
               bank1->setAddress(city, state);
               break;
             case 'D':   //Display Bank
               bank1->printInfo();
               break;
             case 'Q':   //Quit
               delete bank1;
               break;
             case '?':   //Display Menu
               printMenu();
               break;
             default:
               cout << "Unknown action\n";
               break;
            }

        } while (input1 != 'Q');

      return 0;
   }


  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd Bank\n";
     cout << "D\t\tDisplay Bank\n";
     cout << "Q\t\tQuit\n";
     cout << "?\t\tDisplay Help\n\n";
  }
