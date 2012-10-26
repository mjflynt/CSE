/*
Michael Jeffrey Flynt
mflynt@asu.edu

CSE 240 Programming Assignment #2
*/



#include <stdio.h>
#include <ctype.h>

#define SIZE 60

void printMenu();

/////////////////////////////////////////////////////////////////////////////////////////
//
// This is the group of functions and methods needed to complete this assignment.
// It basically does the minimal to implement the functionality. It does not check
// for errors as most error situations have not been defined by the assignment.
// For example, inserting beyond the end of a string does not error nor does doing
// something to the string to make it larger than its max size.
//
/////////////////////////////////////////////////////////////////////////////////////////

// Based on each character’s corresponding ASCII number, it determines the character with the largest ASCII number and returns it.
char largestCharacter(char input_string[])
{
	int i = 0;
	int max_char = -1;
	// Loop until the string terminator
	while(input_string[i] != '\0')
	{
		// determine the max char by comparing it to all previous to see if this one is larger.
		max_char = ((int)input_string[i] < max_char ? max_char : (int)input_string[i]);;
		i++;
	}
	return (char)max_char;
}

// It counts how many upper case letters are in the parameter C-string (you can assume that there are only characetrs ‘a’-‘z’, and ‘A’-‘Z’) and returns it.
int howManyUpperCase(char input_string[])
{
	int i = 0;
	int uppercase_cnt = 0;
	// Loop until the string terminator
	while(input_string[i] != '\0')
	{
		// count the number of chars between 'A' and 'Z' inclusive.
		uppercase_cnt += input_string[i] >= 'A' && input_string[i] <= 'Z';
		i++;
	}
	return uppercase_cnt;
}

// It modifies the parameter C-string to the string containing two of them. For instance, if the parameter C-string is “abc\0”, then it will be changed to “abcabc\0”.
void doubleString(char input_string[])
{
	int i = 0;
	while(input_string[i] != '\0') i++; // count the number of char elements in the input_string sans the terminator.
	int string_length = i;

	for(i = 0; i < string_length; i++)
	{
		// looping over the original string duplicate it onto itself starting at the terminator position.
		input_string[i+string_length] = input_string[i];
	}
	input_string[i+string_length] = '\0'; // then tack on a new terminator.
}

// It replaces the 2nd parameter character in the parameter C-string with the 3rd parameter character.
void replaceChar(char input_string[], char before_char, char after_char)
{
	int i = 0;
	while(input_string[i] != '\0') // loop over the input string
	{
		// and replace each element with either what it already contained or the replacement char.
		input_string[i] = input_string[i] == before_char ? after_char : input_string[i];
		i++;
	}
}

// It inserts the 2nd paramter character at the 3rd paramter index in the parameter C-string. For instance, if we use insertChar(“abcd\0”, ‘e’, 1), then the paramter C-string should become “aebcd\0”.
void insertChar(char input_string[], char insertchar, int slot)
{
	int i = 0;
	while(input_string[i] != '\0') i++;  // determine the starting length of the input_string.
	int string_length = i;

	// starting at the end of the string (just before the terminator) move each char one to the right until you get to the slot.
	for(i = string_length; i > slot; i--)
	{
		input_string[i] = input_string[i - 1];
	}
	input_string[slot] = insertchar; // Place the insertchar into the slot.
	input_string[string_length + 2] = '\0'; // Add a new terminator to the end of the string.
}

// Print the parameter C-string horizontally.
void printString(char mystring[])
{
	printf("%s \n", mystring);  // Just print the string.
}

//
/////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    char inputStr[SIZE];
    int i;
    char char1, char2, char3;
    int index;
    char inputChar;
    char choice;
    char largest;
    int count;

    printf("Please enter a string and hit Return\n");

    i = 0;
    do
    {
     inputChar = getchar();
     if (inputChar != '\n' && inputChar != '\r')
              {
                 inputStr[i] = inputChar;
              }
      else
             break;

              i++;
    } while (i < 30 && inputChar != '\n' && inputChar != '\r');

       inputStr[i] = '\0';

       printf("You entered the string:  ");
       printString(inputStr);
       printf("  \n");

       printMenu();

      choice = 'Z';

      do
      {
       printf("What action would you like to perform?\n");

       choice = getchar();
       getchar(); //to flush '\n'
       choice = toupper(choice);


       switch(choice)
        {
          case 'A':
               largest = largestCharacter(inputStr);
               printf("The largest Character is: %c\n", largest);
               break;
          case 'B':
               count = howManyUpperCase(inputStr);
               printf("The number of the upper case characters in the string is: %d\n", count);
               break;
          case 'C':
               doubleString(inputStr);
               printf("The string is doubled\n");
               break;
          case 'D':
               printf("Please enter a character to be replaced: \n");
               char1 = getchar();
               getchar(); //to flush '\n'
               printf("Please enter a character to replace with: \n");
               char2 = getchar();
               getchar(); //to flush '\n'
               replaceChar(inputStr, char1, char2);
               printf("The characters are replaced\n");
               break;
          case 'E':
               printf("Please enter a character to be inserted: \n");
               char3 = getchar();
               getchar(); //to flush '\n'
               printf("Please enter an index to insert: \n");
               scanf("%d", &index);
               getchar(); //to flush '\n'
               insertChar(inputStr, char3, index);
               printf("The character %c is inserted at %d\n", char3, index);
               break;
          case 'L':
               printf("The string is: ");
               printString(inputStr);
               printf(" \n");
               break;
          case 'Q':   //Quit
               break;
          case '?':   //Display Menu
               printMenu();
               break;
          default:
               printf("Unknown action\n");
               break;
        }
       } while (choice != 'Q');

       return 0;
}

void printMenu()
{
        printf("Choice\t\tAction\n");
        printf("------\t\t------\n");
        printf("A\t\tFind The Largest\n");
        printf("B\t\tCount Upper Case Characters\n");
        printf("C\t\tDouble String\n");
        printf("D\t\tReplace Character\n");
        printf("E\t\tInsert Character\n");
        printf("L\t\tPrint String\n");
        printf("Q\t\tQuit\n");
        printf("?\t\tDisplay Help\n\n");

        return;
}

