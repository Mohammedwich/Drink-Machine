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

	if(theMachine == NULL)
	{
		printf("The machine was not created properly. Program will exit now...");
		return EXIT_FAILURE;
	}

	destroyMachine(theMachine);


	return EXIT_SUCCESS;

	// free machine memory allocation, and the array in it
}

