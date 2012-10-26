// Assignment6
// Name: Michael Jeffrey Flynt
// email: mflynt@asu.edu
/***************************************************
This program reads from a file, then based on the index
that a user enters, it extracts that index-th number from
each line within the data from the file, then writes
the extracted information into a file as well as standard output 
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Read data from a file and store them as a string in the variable "str"
void * loadFile(char * filename, char * str)
{
        int i = 0;
        FILE * filePtr;
        char * temp = str; //temp has the initial address of str

        //open the file to read "r" (note "w" for write, "a" for append)
        filePtr = fopen(filename, "r");

        //if the file cannot be read
        //then an error message is given and the program exits
        if (filePtr==NULL)
         {
           fputs ("File error",stderr);
           exit (1);
         }

        //keep reading until the end of the file (eof)
        while(!feof(filePtr))
         {
           fscanf(filePtr, "%c", temp); //read in a character  
           i++;
           temp = str+i;
         }

       str[i] = '\0';
       fclose(filePtr);
   }

//Write the string "str" in the file named "filename"
void saveFile(char * filename, char * str)
  {
    FILE *filePtr; // declare a pointer to File type
    int i = 0;
    int size = strlen(str);
    char * temp = str; //temp has the initial address in str

    //open the file for writing 
    filePtr = fopen(filename, "w");

    //If the file cannot be opened, 
    //then an error message
    if (filePtr==NULL)
       {
         fputs ("File error",stderr);
         exit (1);
       }

    while(i < size)
     {
       fprintf(filePtr, "%c",  *temp);
       i++;
       temp = (str+i);
     }

    fclose(filePtr);
  }

//========================================================================================================
//It extracts the parameter index-th number from
//each line within the input string 
//append those numbers into a string and returns it
char * extractData(char * inputStr, int index)
 {
  char * result = (char *)malloc(2000 * sizeof(char));
  int inputStrLen = strlen(inputStr);
  int inputStrCurrentPos;
  int resultPos = 0;
  int octet = 0;

  // scan every char of the file
  for(inputStrCurrentPos = 0; inputStrCurrentPos < inputStrLen - 1; inputStrCurrentPos++)
  {
    // use '.' & ':' as delimiters. Track the current octet. If it is the index column grab it to ouput. 
    // Reset octet count on end of line.
    switch(inputStr[inputStrCurrentPos])
    {
      case ':'  : 
      case '.'  : if(octet==index)
                  {
                    result[resultPos++] = '\n';
                  }
                  octet++;
                  break;

      case '\n' : octet = 0;
                  break;

      default   : if(octet==index)
                  {
                    result[resultPos++] = inputStr[inputStrCurrentPos];
                  }
                  break;
    }
  }
  return result;
 }
//========================================================================================================

int main()
{
    char filename1[30], filename2[30];
    char str1[2000];
    char * str2;
    char numStr[10];
    int index;

    //prompt to a user to enter an index of number to extract
    //this will also be used to create a file name to write
    printf("Please enter an index(integer)\n");
    scanf("%d", &index);

    // added for minor error checking...
    if(index<0 || index>3)
    {
      printf("Index out of range.\n");
      exit(1);
    }


    //filename2 = "write#.txt" where # is the index
    strcpy(filename2, "write");
    sprintf(numStr, "%d", (index+1)); 
    strcat(filename2, numStr);
    strcat(filename2, ".txt");

    //file to read is "read1.txt"
    strcpy(filename1, "read1.txt");

    //get data from the file
    loadFile(filename1, str1);

    //extract some data from str1 and put int into str2
    str2 = extractData(str1, index);

    //print out the string str2 into a screen
    printf("%s\n", str2);

    //save str2 in to the file
    saveFile(filename2, str2);     

    return 0;
}



