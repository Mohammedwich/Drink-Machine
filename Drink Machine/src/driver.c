/*
 ============================================================================
 Name        : Drink.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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
		float price = drinkPointer->price;
		int cansRemaining = drinkPointer->cansRemaining;
		int purchaseCount = drinkPointer->purchaseCount;

		printf("DrinkID: %d\tName: %s\tPrice: %.2f\tCans Remaining: %d\t Amount Purchased: %d\n", drinkID, name, price,
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
	float price = cost(theMachine, 7);
	//should output "8  2  1.30"
	printf("\n%d  %d  %.2f \n", choices, isAvailable, price);
	fflush(stdout);
*/



/*

	//Test this function. Should return a success message if it worked.

	destroyMachine(theMachine);



	return EXIT_SUCCESS;

}
*/
