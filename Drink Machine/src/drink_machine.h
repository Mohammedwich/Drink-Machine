//============================================================================
// Name			: drink_machine.h
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
	DrinkItem * drinksArray;
	int currentItem;

} typedef DrinkMachine;	// typedef to avoid having to use struct tag


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
double cost(DrinkMachine *, int);

// Arguments (drinkMachine *, itemID, moneyInputed, change/itemPrice(if insufficient funds) passed by ref)
//Returns -2 if some error happens
int purchase(DrinkMachine *, int, double, double *);

//Displays the contents of the drinks in the machine
void dumpDrinkMachine(DrinkMachine *);


#endif /* DRINK_MACHINE_H_ */
