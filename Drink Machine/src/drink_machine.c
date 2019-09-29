/*
 * drink_machine.c
 *
 *  Created on: Sep 29, 2019
 *      Author: Mohax
 */

#include "drink_machine.h"
#include <stdio.h>
#include <stdlib.h>

const int INVALID_INDEX = -1;
int numberOfDrinkOptions = 0;

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
		fscanf(inputFile, "%s %f %d", (theMachine->drinksArray[i].name), &(theMachine->drinksArray[i].price),
				&(theMachine->drinksArray[i].cansRemaining) );

	}

	fclose(inputFile);

	printf("The machine was successfully created \n");
	fflush(stdout);
	return theMachine;
}

void destroyMachine(DrinkMachine * targetMachine)
{
	//freeing all the poor drinks before destroying the machine
	for(int i = 0; i < targetMachine->numberOfDrinkItems; ++i)
	{
		free(targetMachine->drinksArray[i].name);
	}

	free(targetMachine);
	printf("The machine was successfully destroyed \n");
	fflush(stdout);
}

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
		printf("No more items for next() to return\n");
		fflush(stdout);
		return NULL;
	}
}

