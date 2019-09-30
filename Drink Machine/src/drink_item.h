//============================================================================
// Name			: drink_item.h
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

#ifndef DRINK_ITEM_H_
#define DRINK_ITEM_H_

#include <stdio.h>
#include <stdlib.h>

struct drink_item
{
	int id;
	char * name;
	double price;
	int cansRemaining;
	int purchaseCount;

} typedef DrinkItem;	// typedef to avoid having to use struct tag

#endif /* DRINK_ITEM_H_ */
