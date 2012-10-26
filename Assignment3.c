/*
Michael Jeffrey Flynt
mflynt@asu.edu

CSE 240 Programming Assignment #3
*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////////////////
//                                                                                       //
// This is the group of functions and methods needed to complete this assignment.        //
//                                                                                       //
///////////////////////////////////////////////////////////////////////////////////////////

// It increases the number at the parameter index within the array by the parameter amount.
	void increaseNumber(double * array, int arraySize, int index, double amount)
	{
		if(index < arraySize && index >= 0)
		{
			*(array + index) += amount;
		}
		else
		{
			printf("Array index out of bounds.\n");
			exit(1);
		}
	}


// It decreases the number at the parameter index within the array by the parameter amount.
	void decreaseNumber(double * array, int arraySize, int index, double amount)
	{
		if(index < arraySize && index >= 0)
		{
			*(array + index) -= amount;
		}
		else
		{
			printf("Array index out of bounds.\n");
			exit(1);
		}
	}


// It prints all elements in the array horizontally.
	void printArray(double * array, int arraySize)
	{
		int i;
		for(i = 0; i < arraySize ; i++)
		{
			printf("%.2f \t",*(array + i));
		}
		printf("\n");
	}

//////////////////////////////////////////
// main program - mostly provided code. //
//////////////////////////////////////////
int main()
{
    int i;
    double * numArray;
    int size;
    double num;

    int increaseIndex;
    double increaseAmount;
    int decreaseIndex;
    double decreaseAmount;

    printf("Please enter a number of floating numbers to be entered:\n");
    scanf("%d", &size);

    /***   Enter a line of code to allocate memory for the array here ***/
    numArray = (double *)malloc(sizeof(double));

    for (i=0; i<size; i++)
    {
       scanf("%lf", &num);  //read in a double entered by user
       *(numArray+i) = num;
    }

    printArray(numArray, size);

    printf("Please enter an index to increase:\n");
    scanf("%d", &increaseIndex);

    printf("Please enter an amount to increase:\n");
    scanf("%lf", &increaseAmount);

    increaseNumber(numArray, size, increaseIndex, increaseAmount);
    printArray(numArray, size);

    printf("Please enter an index to decrease:\n");
    scanf("%d", &decreaseIndex);

    printf("Please enter an amount to decrease:\n");
    scanf("%lf", &decreaseAmount);

    decreaseNumber(numArray, size, decreaseIndex, decreaseAmount);
    printArray(numArray, size);
    return 0;
}
