/*
Michael Jeffrey Flynt
mflynt@asu.edu

CSE 240 Programming Assignment #4
*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void printMenu();

//const int SIZE = 30;
#define SIZE 30

struct Computer
{
	char brand[SIZE];  //doesn't like the const int SIZE = 30;
	float memory;
	float speed;
	float price;
	struct Computer * next;
};

struct Computer * head = NULL;

/////////////////////////////////////////////////////////////////////////////////////////
// This function attemps to insert a new computer data into the linked list
// using the parameter values – brandname, memory, speed, and price at the
// location indicated by the parameber “index”. If “index” is 0, then that
// means that it should be inserted as the first data in the linked list.
// If it is successfully inserted, then it should return the index of where
// it is inserted. If the parameter “index” value is not within the linked
// list size (for instance, less than 0, or greater than the index of the
// end data in the list.), then it should return -1.
int insertAtIndex(char * brandname, float memory, float speed, float price, int index)
{
	int result = -1; // defaults to failure

	struct Computer * insert;
	insert = (struct Computer *)malloc(sizeof(struct Computer));

	// using a different notation for this part just to try it out.
	strcpy((*insert).brand, brandname);
	(*insert).memory = memory;
	(*insert).speed = speed;
	(*insert).price = price;

	if(index < 0) {}
	else if(index <= size())
	{
		int loop_position = 0;
		struct Computer * curr_item = head;
		struct Computer * prev_item = head;

		if(head != NULL)  // list not empty
		{
			// follow the list until you reach desired element.
			while(curr_item->next != NULL && loop_position < index)
			{
				prev_item = curr_item;
				curr_item = curr_item->next;
				loop_position++;
			}

			if(index == 0)  // inserting at head of list
			{
				insert->next = curr_item;
				head = insert;
			}
			else if (index == size())  // inserting at end of list
			{
				insert->next = NULL;
				curr_item->next = insert;
			}
			else  //  inserting in the middle of the list
			{
				insert->next = curr_item;
				prev_item->next = insert;
			}
			result = index;
		}
		else  // inserting into an empty list
		{
			head = insert;
			insert->next = NULL;
			result = 0;
		}
	}
	return result;
}

/////////////////////////////////////////////////////////////////////////////////////////
// This function returns the number of entries in the linked list. If the
//linked list is empty, it should return 0.
int size()
{
	int listSize = 0;
	struct Computer * currentElement = head;
	if(head != NULL)  // if list not empty
	{
		while(currentElement->next != NULL)  // follow the list
		{
			listSize++;
			currentElement = currentElement->next;
		}
		++listSize;
	}

	return listSize;
}

/////////////////////////////////////////////////////////////////////////////////////////
// It prints all entries in the linked list in the following format:
void displayLinkedList()
{
	struct Computer * curr_item = head;

	if(head != NULL)  // if list not empty
		while(curr_item != NULL)  // so long as more items to follow
		{  
			printf("\tBrand Name: %s\n\tMemory: %.3fGB\n\tSpeed: %.3fGHz\n\tPrice: $ %.2f\n\n", 
						curr_item->brand, 
						curr_item->memory, 
						curr_item->speed, 
						curr_item->price);

			curr_item = curr_item->next;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////
// This function searches a computer with the parameters, memory and speed,
// removes the computer entry, and returns the index of where that entry was
// located. It should return -1 if such computer entry with the given memory
// and speed was not found. The first computer in the linked list with the
// memory and speed should be removed if there are two such computer entries.
int removeComputer(float memory, float speed)
{
	struct Computer * temp_item = head;
	struct Computer * curr_item = head;
	struct Computer * prev_item = NULL;
	int found_at = 0;

	// I was going to use the searchComputer function but didn't as I still have to traverse
	// the list to find the found element and the previous. Not much gained from it.
	while(curr_item != NULL)
	{
		if (curr_item->memory == memory && curr_item->speed == speed)
		{
			if (curr_item == head)
			{
				temp_item = head;
				head = head->next;
				free(temp_item);
			}
			else
			{
				prev_item->next = curr_item->next;
				free(curr_item);
			}
			return found_at;
		}

		found_at++;
		prev_item = curr_item;
		curr_item = curr_item->next;
	}
	// if the computer isn't found you'll end up here...
	return -1;
}

/////////////////////////////////////////////////////////////////////////////////////////
// This function searches a computer entry with the parameters, memory and
// speed, and returns that computer entry once it is found (The first found
// entry should be returned). It should return NULL if not found.
struct Computer * searchComputer(float memory, float speed)
{
	struct Computer * curr_item = head;

	while(curr_item != NULL)
	{
		if (curr_item->memory == memory && curr_item->speed == speed)
		{
			return curr_item;
		}
		curr_item = curr_item->next;
	}
	// if the computer isn't found you'll end up here...
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////
// main program                                                                        //
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	char name[30];
	float memory, speed, price;
	int index,add_index;
	char choice = 'Z';

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

	printMenu();

	do
	{
		printf("What action would you like to perform?\n");

	   	choice = getchar();
	   	getchar(); //to flush '\n'
	   	choice = toupper(choice);

	   	switch(choice)
		{
		  	case 'A':
				printf("Please enter a computer to add:\n");

				printf("Please enter the brand name:\n");
				scanf("%s", name);
				printf("Please enter the memory:\n");
				scanf("%f", &memory);
				printf("Please enter the speed:\n");
				scanf("%f", &speed);
				printf("Please enter the price:\n");
				scanf("%f", &price);
				printf("Please enter the index to insert:\n");
				scanf("%d", &index);
				getchar(); //to flush '\n'
				if((add_index = insertAtIndex(name, memory, speed, price, index)) >= 0)
				{
					printf("The computer is added at %d\n", add_index);
				}
				else
				{
					printf("The computer could not be added\n");
				}

				break;
		  	case 'D':
				printf("The size of the linked list is %d\n", size());
				break;
			case 'C':

				break;
			case 'P':
				displayLinkedList();
				break;
			case 'R':
				printf("Please enter a memory(number) to remove:\n");
				scanf("%f", &memory);
				printf("Please enter a speed(number) to  remove:\n");
				scanf("%f", &speed);
				getchar(); //to flush '\n'
				if (removeComputer(memory, speed) >= 0)
				{
					printf("Computer was removed\n");
				}
				else
				{
					printf("Computer with the memory and speed was not found\n");
				}
				break;
			case 'S':
				printf("Please enter a memory(number) to search:\n");
				scanf("%f", &memory);
				printf("Please enter a speed(number) to search:\n");
				scanf("%f", &speed);
				getchar(); //to flush '\n'
				struct Computer * matching_computer = searchComputer(memory, speed);
				if (matching_computer == NULL)
				{
					printf("The computer with the memory and speed was not found\n");
				}
				else
				{
					printf("\tThe computer's brand name is %s\n\tThe computer's memory is %.3fGB\n\tThe computer's speed is  %.3fGHz\n\tThe computer's price is $ %.2f\n\n", 
						matching_computer->brand, 
						matching_computer->memory, 
						matching_computer->speed, 
						matching_computer->price);
				}
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
}

//////////////////////////////////////////////////////////////////////////////
void printMenu()
{
        printf("Choice\t\tAction\n");
        printf("------\t\t------\n");
        printf("A\t\tAdd Computer\n");
        printf("D\t\tDisplay List Size\n");
        printf("P\t\tPrint List Elements\n");
        printf("R\t\tRemove Computer\n");
        printf("S\t\tSearch Computer\n");
        printf("Q\t\tQuit\n");
        printf("?\t\tDisplay Help\n\n");

        return;
}