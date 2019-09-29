/*
 ============================================================================
 Name        : Drink.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "drink_item.h"
#include "drink_machine.h"
#include <stdio.h>
#include <stdlib.h>


const int INVALID_INDEX = 1;
int numberOfDrinkOptions = 0;

DrinkMachine * createMachine()
{
	//Allocating the DrinkMachine struct
	DrinkMachine * theMachine = malloc(sizeof(DrinkMachine));

	// Initializing version and current item
	theMachine->version = 1;
	theMachine->currentItem = INVALID_INDEX;

	// Opening a file to read from and initialize numberOfdrinks and create the drinksArray
	char * fileName;

	printf("Enter the file name of the file with drinks data: ");
	scanf("%s", fileName);

	FILE * inputFile;
	inputFile = fopen(fileName, "r");

	if(inputFile == NULL)
	{
		printf("failed to open input file");
		free(theMachine);

		return NULL;
	}


	//Creating and initializing drink array and the drinks in it
	fscanf("%d", theMachine->numberOfDrinkItems);
	numberOfDrinkOptions = theMachine->numberOfDrinkItems;

	theMachine->drinksArray = malloc(theMachine->numberOfDrinkItems);

	for(int i = 0; i < theMachine->numberOfDrinkItems; ++i)
	{
		theMachine->drinksArray[i] = malloc(sizeof(DrinkItem));

		theMachine->drinksArray[i]->id = (i+1);
		theMachine->drinksArray[i]->purchaseCount = 0;

		//Initializing drinks
		fscanf("%s %.2f %d", theMachine->drinksArray[i]->name, theMachine->drinksArray[i]->price,
				theMachine->drinksArray[i]->cansRemaining);
	}

	fclose(inputFile);

	return theMachine;
}

void destroyMachine(DrinkMachine * targetMachine)
{
	//freeing all the poor drinks before destroying the machine
	for(int i = 0; i < targetMachine->numberOfDrinkItems; ++i)
	{
		free(targetMachine->drinksArray[i]);
	}

	free(targetMachine);
}



int main(void)
{
	DrinkMachine * theMachine = createMachine();


	return EXIT_SUCCESS;

	// free machine memory allocation, and the array in it
}
