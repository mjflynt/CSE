// Assignment9
// Name:
// email:
// Description: This program reads a string containing an arithmetic expression
// after the option "E" (enter a string) is chosen, and evaluates its value.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printMenu();
int evaluate(string exp);

int main()
{
       char choice;
       int result;
       string line;

       printMenu();

       choice = 'Z';

       do
       {
        cout << "What action would you like to perform?\n";

        cin.get(choice);
        cin.ignore(20, '\n'); //to flush '\n'
        choice = toupper(choice);

        switch(choice)
         {
          case 'E':
               cout << "Enter an arithmetic expression:" << endl;
               getline(cin, line);
               result = evaluate(line);
               cout << "The evaluated value is: " << result << endl;
               break;
          case 'Q':   //Quit
               break;
          case '?':   //Display Menu
               printMenu();
               break;
          default:
               cout << "Unknown action\n";
               break;
         }
        } while (choice != 'Q');
       return 0;
}

//Print the menu to a user
void printMenu()
 {
        cout << "Choice\t\tAction\n";
        cout << "------\t\t------\n";
        cout << "E\t\tEnter an arithmetic expression to evaluate\n";
        cout << "Q\t\tQuit\n";
        cout << "?\t\tDisplay Help\n\n";

        return;
  }

//The evaluate function takes a string containing an arithmetic expression,
//evaluates it,and returns its result
int evaluate(string exp)
 {

//To be completed

 }





