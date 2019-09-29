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


// Functions for the struct
DrinkMachine * createMachine();

void destroyMachine(DrinkMachine * targetMachine);


#endif /* DRINK_MACHINE_H_ */
