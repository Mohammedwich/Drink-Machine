/*
 * drink_machine.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Mohax
 */

#ifndef DRINK_MACHINE_H_
#define DRINK_MACHINE_H_

#include "drink_item.h"
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






#endif /* DRINK_MACHINE_H_ */
