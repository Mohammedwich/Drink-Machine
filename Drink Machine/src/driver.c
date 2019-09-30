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



int main(void)
{
	printf("We are at the start of driver now \n");
	fflush(stdout);

	DrinkMachine * theMachine = createMachine();

	// Just quit if the machine was not built properly
	if(theMachine == NULL)
	{
		printf("The machine was not created properly. Program will exit now...");
		return EXIT_FAILURE;
	}


	// Calling nextDrink without having called firstDrink. Pointer will be nulled by nextDrink() so no need to free it
	// Ignore "unused variable" warning. This only exists to catch the return from nextDrink.
	DrinkItem * nextWithoutFirst = nextDrink(theMachine);

	//nextDrink is called at the end of the loop after last entry has been retrieved. It should return null and display a
	// message stating there are no more items.
	for ( DrinkItem * drinkPointer = firstDrink(theMachine); drinkPointer != NULL; drinkPointer = nextDrink(theMachine) )
	{
		int drinkID = drinkPointer->id;
		char * name = drinkPointer->name;
		float price = drinkPointer->price;
		int cansRemaining = drinkPointer->cansRemaining;
		int purchaseCount = drinkPointer->purchaseCount;

		printf("DrinkID: %d\tName: %s\tPrice: %.2f\tCans Remaining: %d\t Amount Purchased: %d\n", drinkID, name, price,
				cansRemaining, purchaseCount);
		fflush(stdout);
	}


	//Test the function. Should return a success message if it worked.
	destroyMachine(theMachine);


	return EXIT_SUCCESS;

	// free machine memory allocation, and the array in it
}

