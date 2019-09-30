/*
 * drink_machine.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Mohax
 */

#ifndef DRINK_MACHINE_H_
#define DRINK_MACHINE_H_

#include "drink_item.h"
#include "DrinkAvailabilityEnum.h"
#include "PurchaseEnum.h"
#include <stdio.h>
#include <stdlib.h>


struct drink_machine
{
	int version;
	int numberOfDrinkItems;
	// Debug: see what type the array should be
	DrinkItem * drinksArray;
	int currentItem;

} typedef DrinkMachine;


// Functions for this struct

//Creates and initializes the machine with data from an input file
DrinkMachine * createMachine();

//Frees the memory allocated to the drinks in it and then to the machine itself
void destroyMachine(DrinkMachine * targetMachine);

//Returns address of the first drink. Returns null if zero drinks.
DrinkItem * firstDrink(DrinkMachine *);

//Returns the address of the next drink and returns null when there is no next item.
DrinkItem * nextDrink(DrinkMachine *);

//Returns the number of drink types in the machine
int items(DrinkMachine *);

//Checks if a drink is available, returns -2 and prints message if some error happens
int available(DrinkMachine *, int);

//Returns price of the drink, or -1 if drink ID is invalid
float cost(DrinkMachine *, int);

// Arguments (drinkMachine *, itemID, moneyInputed, change/itemPrice(if insufficient funds) passed by ref), also defaults changeOrCost to 0
// Returns -2 if some error happens
int purchase(DrinkMachine *, int, float, float *);

//Displays the contents of the drinks in the machine
void dumpDrinkMachine(DrinkMachine *);


#endif /* DRINK_MACHINE_H_ */
