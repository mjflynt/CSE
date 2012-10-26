/*
Michael Jeffrey Flynt
mflynt@asu.edu

CSE 240 Programming Assignment #5
*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/*
Assignment Description:          
This assignment will be the construction of a program that reads in a sequence of numbers (not necessary integers) from standard input, and store them in an array. This is done using iteration. 
You need to create recursive functions doubleEach, addPreviousToEach, and printArray that will be called by a main function.
Specifically, the following recursive functions must be implemented (These functions should not contain any loop):
*/ 
// It doubles each element in the array.
void doubleEach(double array[], int startIndex, int endIndex)
{
    array[startIndex] *= 2;
    if (startIndex < endIndex)
    {
        doubleEach(array, startIndex+1, endIndex);
    }
}
                  
// It adds the value of the previous index (i-1) to its value (array[i]), except for the index 0.
void addPreviousToEach(double array[], int startIndex, int endIndex)
{
    if(startIndex==0)
    {
        addPreviousToEach(array, startIndex+1, endIndex);
    }
    else if(startIndex <= endIndex)
    {
        addPreviousToEach(array, startIndex+1, endIndex);
        array[startIndex] += array[startIndex - 1];
    }
}  

// It prints all elements in the array horizontally.
void printArray(double array[], int startIndex, int endIndex)
{
    printf("%.2f  ", array[startIndex]);
    if (startIndex < endIndex)
    {
        printArray(array, startIndex+1, endIndex);
    }
    else printf("\n");
}
 
// Use your functions with the following main:
// ----------------------------------------------------------------------------------
int main()
{
    int i;
    double numArray[7];
    int size = 7;
    double num;
 
    printf("Please enter 7 numbers:\n");
 
    for (i=0; i<size; i++)
    {
       scanf("%lf", &num);  //read in a double entered by user
       numArray[i] = num;
    }
 
    printArray(numArray, 0, size-1);
    doubleEach(numArray, 0, size-1);
    printArray(numArray, 0, size-1);
    addPreviousToEach(numArray, 0, size-1);
    printArray(numArray, 0, size-1);
 
    return 0;
}