//============================================================================
// Name			: drink_machine.c
// Author		: Mohammed Ahmed
// Course		: UTDallas CS 1337.502 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
// A program that simulates a soft-drink machine. fflush(stdout) calls were placed all around to find invisible crash causes.
// Return code -2 usually means a function faced some kind of error. Functions are declared in the drink_machine.h file
// since they operate on DrinkMachine objects. They are defined in the drink_machine.c file.
//
//============================================================================

#include "drink_item.h"
#include "drink_machine.h"
#include "DrinkAvailabilityEnum.h"
#include "PurchaseEnum.h"
#include <stdio.h>
#include <stdlib.h>

const int INVALID_INDEX = -1;	//Used to set currentItem
int numberOfDrinkOptions = 0;	//Used to hold the number of items after reading it from file, in case it is needed.

//Creates and initializes the machine with data from an input file
DrinkMachine * createMachine()
{
	//Allocating the DrinkMachine struct
	DrinkMachine * theMachine = (DrinkMachine *) malloc(sizeof(DrinkMachine));

	// Initializing version and current item
	theMachine->version = 1;
	theMachine->currentItem = INVALID_INDEX;
	theMachine->numberOfDrinkItems = 0;

	// Opening a file to read from and initialize numberOfdrinks and create the drinksArray
	char * fileName = (char *) malloc(50);

	printf("Enter the file name of the file with drinks data: \n");
	fflush(stdout);
	scanf("%s", fileName);

	FILE * inputFile;
	inputFile = fopen(fileName, "r");

	if(inputFile == NULL)
	{
		printf("failed to open input file \n");
		fflush(stdout);
		free(theMachine);

		return NULL;
	}
	else
	{
		printf("succeeded to open input file \n");
		fflush(stdout);
	}


	//Creating and initializing drink array and the drinks in it
	fscanf(inputFile, "%d", &numberOfDrinkOptions);
	theMachine->numberOfDrinkItems = numberOfDrinkOptions;

	//Set drinksArray to NULL to check if it is empty later
	if(numberOfDrinkOptions < 1)
	{
		theMachine->drinksArray = NULL;
	}
	else
	{
		theMachine->drinksArray = (DrinkItem *) malloc((theMachine->numberOfDrinkItems) * sizeof(DrinkItem));
	}

	//Drink initialization loop
	for(int i = 0; i < theMachine->numberOfDrinkItems; ++i)
	{
		theMachine->drinksArray[i].id = (i+1);
		theMachine->drinksArray[i].purchaseCount = 0;

		//Debug: see if the name was properly set. Try to malloc then realloc
		theMachine->drinksArray[i].name = (char *) malloc(100);
		fscanf(inputFile, "%s %lf %d", (theMachine->drinksArray[i].name), &(theMachine->drinksArray[i].price),
				&(theMachine->drinksArray[i].cansRemaining) );

	}

	//Done with the file
	fclose(inputFile);

	//Success message to indicate the machine was created
	printf("The machine was successfully created \n\n");
	fflush(stdout);
	return theMachine;
}

//Frees allocated memory
void destroyMachine(DrinkMachine * targetMachine)
{
	//freeing all the poor drinks before freeing the machine's allocated memory
	for(int i = 0; i < targetMachine->numberOfDrinkItems; ++i)
	{
		free(targetMachine->drinksArray[i].name);
	}

	free(targetMachine);
	printf("The machine was successfully destroyed \n\n");
	fflush(stdout);
}

//Return the address of the first DrinkItem in the machine if the machine's drinkArray is not empty. If empty returns null.
DrinkItem * firstDrink(DrinkMachine * theMachine)
{
	if(theMachine->drinksArray == NULL)
	{
		theMachine->currentItem = INVALID_INDEX;
		return NULL;
	}
	else
	{
		theMachine->currentItem = 0;

		// Returning memory address of first byte of the array so we get first element. No subscript access
		return theMachine->drinksArray;
	}

}

//Assumes back to back storage locations in memory
DrinkItem * nextDrink(DrinkMachine * theMachine)
{
	//Needs firstDrink() to set the firstItem before this can iterate
	if(theMachine->currentItem == INVALID_INDEX)
	{
		printf("firstDrink() was not called to reset the current drink \n");
		fflush(stdout);
		return NULL;
	}
	//currentItem starts at 0, numberOfDrinkItems starts at 1, so I put (currentItem + 1) to test it properly
	else if( (theMachine->currentItem + 1) < (theMachine->numberOfDrinkItems) )
	{
		// Returns current drink item using pointer arithmetics to avoid using subscripts in case container type changes
		++(theMachine->currentItem);
		return ( (theMachine->drinksArray) + (theMachine->currentItem) );
	}
	else
	{
		theMachine->currentItem = INVALID_INDEX;
		//printf("End of item list\n\n"); //Debug test code
		fflush(stdout);
		return NULL;
	}
}



//Returns the number of drink types in the machine
int items(DrinkMachine * theMachine)
{
	return theMachine->numberOfDrinkItems;
}

//Checks if a drink is available, returns -2 and prints message if some error happens
int available(DrinkMachine * theMachine, int id)
{
	if( (id < 1) || (id > theMachine->numberOfDrinkItems) )
	{
		return INVALID_SELECTION;
	}
	else if(theMachine->drinksArray[id - 1].cansRemaining == 0)
	{
		return VALID_SELECTION_BUT_OUT;
	}
	else if(theMachine->drinksArray[id - 1].cansRemaining > 0)
	{
		return AVAILABLE;
	}
	else
	{
		printf("function available() encountered an error");
		fflush(stdout);
		return -2;
	}
}

//Returns price of the drink, or -1 if drink ID is invalid. Returns -2 if an error happens
double cost(DrinkMachine * theMachine, int id)
{
	if( (id < 1) || (id > theMachine->numberOfDrinkItems) )	//Invalid ID
	{
		return -1;
	}
	else if( (id >= 1) && (id <= theMachine->numberOfDrinkItems) )
	{
		return theMachine->drinksArray[id - 1].price;
	}
	else
	{
		printf("function cost() encountered an error");
		fflush(stdout);
		return -2;
	}
}

// Arguments (drinkMachine *, itemID, moneyInputed, change/itemPrice(if insufficient funds))
// Returns -2 if some error happens
int purchase(DrinkMachine * theMachine, int id, double money, double * changeOrCost)
{
	if( (id < 1) || (id > theMachine->numberOfDrinkItems) )	//Invalid ID
	{
		return INVALID;
	}
	else if(theMachine->drinksArray[id - 1].cansRemaining == 0)
	{
		return NOT_AVAILABLE;
	}
	else if(money < theMachine->drinksArray[id - 1].price)
	{
		(*changeOrCost) = theMachine->drinksArray[id - 1].price;
		return INSUFFICIENT_FUNDS;
	}
	else if(money >= theMachine->drinksArray[id - 1].price)
	{
		(*changeOrCost) = money - theMachine->drinksArray[id - 1].price;
		--(theMachine->drinksArray[id - 1].cansRemaining);
		++(theMachine->drinksArray[id - 1].purchaseCount);
		return PURCHASED;
	}
	else
	{
		printf("function purchase() encountered an error");
		fflush(stdout);
		return -2;
	}

}

//Displays the contents of the drinks in the machine
void dumpDrinkMachine(DrinkMachine * theMachine)
{
	printf("%3s\t%12s\t%5s\t%4s\t%4s\n","ID", "Name", "Price", "Qty", "Sold");
	fflush(stdout);

	for ( DrinkItem * drinkPointer = firstDrink(theMachine); drinkPointer != NULL; drinkPointer = nextDrink(theMachine) )
		{
			int drinkID = drinkPointer->id;
			char * name = drinkPointer->name;
			double price = drinkPointer->price;
			int cansRemaining = drinkPointer->cansRemaining;
			int purchaseCount = drinkPointer->purchaseCount;

			printf("%3d\t%12s\t%5.2lf\t%4d\t%4d\n", drinkID, name, price, cansRemaining, purchaseCount);
			fflush(stdout);
		}
	printf("\n");
	fflush(stdout);
}




/*
 ( (id >= 1) && (id <= theMachine->numberOfDrinkItems) && (money >= theMachine->drinksArray[id - 1]->price)
			&& (money <= 2.00) )
 */
