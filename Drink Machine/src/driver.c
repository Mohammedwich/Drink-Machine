//============================================================================
// Name			: driver.c
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

/*
#include "drink_item.h"
#include "drink_machine.h"
#include <stdio.h>
#include <stdlib.h>




int main(void)
{
	//Debug statement
	printf("We are at the start of driver.c now \n");
	fflush(stdout);

	DrinkMachine * theMachine = createMachine();

	// Just quit if the machine was not built properly
	if(theMachine == NULL)
	{
		printf("The machine was not created properly. Program will exit now...");
		return EXIT_FAILURE;
	}




	// Calling nextDrink without having called firstDrink. Pointer will be nulled by nextDrink() so no need to free it
	nextDrink(theMachine);
	DrinkItem * nextOnLastItem = NULL;


	//nextDrink is called at the end of the loop after last entry has been retrieved. It should return null and display a
	// message stating there are no more items.
	for ( DrinkItem * drinkPointer = firstDrink(theMachine); drinkPointer != NULL; drinkPointer = nextDrink(theMachine) )
	{
		int drinkID = drinkPointer->id;
		char * name = drinkPointer->name;
		double price = drinkPointer->price;
		int cansRemaining = drinkPointer->cansRemaining;
		int purchaseCount = drinkPointer->purchaseCount;

		printf("DrinkID: %d\tName: %s\tPrice: %.2lf\tCans Remaining: %d\t Amount Purchased: %d\n", drinkID, name, price,
				cansRemaining, purchaseCount);
		fflush(stdout);

		nextOnLastItem = drinkPointer;
	}

	printf("This is the address of a pointer on the last DrinkItem: %p \n", nextOnLastItem);
	nextDrink(theMachine);
	if(theMachine->currentItem == -1)
	{
		nextOnLastItem = NULL;
	}
	printf("This is its address after calling nextDrink() when there is no next item. Should be NULL: %p\n\n", nextOnLastItem);

*/


	//Testing the rest of the functions
/*
	dumpDrinkMachine(theMachine);
	int choices = items(theMachine);
	int isAvailable = available(theMachine, 7); // value 2 if available
	double price = cost(theMachine, 7);
	//should output "8  2  1.30"
	printf("\n%d  %d  %.2lf \n", choices, isAvailable, price);
	fflush(stdout);
*/



/*

	//Test this function. Should return a success message if it worked.

	destroyMachine(theMachine);



	return EXIT_SUCCESS;

}
*/
