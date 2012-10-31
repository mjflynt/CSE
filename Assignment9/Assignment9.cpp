// Assignment9
// Name:  Michael Jeffrey Flynt
// email: mflynt@asu.edu
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
    #define superBad 100000;

    // Create three stacks, one to store left (open) parentheses, one to store 
    // operand numbers (single digit integers), and one to store operations (+,-,*,/, and %).
    stack<char> parenthesis, operand;
    stack<int> number;

    // Read the string staring from the left most character.
    for(int i=0; i < exp.length(); i++)
    {
      switch(exp[i])
      {
        case '('  : // If a character is a left (open) parenthesis, push it onto the parentheses stack.
                    parenthesis.push(exp[i]);
                    break;

        case ')'  :
                    if(!parenthesis.empty()) // If a character is a right (close) parenthesis, check if the parentheses stack is not empty
                    {
                      parenthesis.pop(); // and it is not, then pop it.
                      // Also the top item of the operations stack needs to be removed
                      // and the top two items of the operations need to be removed
                      int rightOperand = number.top(); // because the order of operands is backward.
                      number.pop(); // why is C++ stacks so weird? pop should return the top of stack too!
                      int leftOperand = number.top(); // because the order of operands is backward.
                      number.pop();
                      switch(operand.top()) //  switch depending on operand
                      {
                        case '+'  : number.push(leftOperand + rightOperand); break;
                        case '-'  : number.push(leftOperand - rightOperand); break;
                        case '*'  : number.push(leftOperand * rightOperand); break;
                        case '/'  : number.push(leftOperand / rightOperand); break;
                        case '%'  : number.push(leftOperand % rightOperand); break;
                        default   : break;
                      }
                      operand.pop(); // forced to pop the top of stack to remove the switch operand. Dumb!
                    }
                    else
                    {
                      // If the parentheses stack is empty, then just return 10000 and exit this function.
                      return superBad;
                    }
                    break;

        // If a character is a digit (one of the operands), then push it onto the numbers stack.            
        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '8': case '9':
                    number.push((int)exp[i] - (int)'0'); // asuume a sequencial coding (ASCII) and subtract offset.
                    break;

        // If a character is an operation, then push it onto the operations stack.            
        case '+': case '-': case '*': case '/': case '%': 
                    operand.push(exp[i]);
                    break;

        default   : // If a character is something else besides the ones listed above, just skip it.
                    break;
      }
    }
    // After checking every character of the parameter string
    if(!number.empty()) // check if the numbers stack is empty
    {
      int result = number.top(); // It would be nice to be able to return the pop result. Who is the tragic designer of this library?
      number.pop();
      return result; // and it is not, then retrieve the top item and return it as the result integer
    }
    else
    {
      return superBad; // Otherwise, return 100000
    }
 }
