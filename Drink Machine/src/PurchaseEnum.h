//============================================================================
// Name			: PurchaseEnum
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

#ifndef PURCHASEENUM_H_
#define PURCHASEENUM_H_

#include <stdio.h>
#include <stdlib.h>

enum Purchase
{
	INVALID = 1, PURCHASED = 2, NOT_AVAILABLE = 3, INSUFFICIENT_FUNDS = 4
};

#endif /* PURCHASEENUM_H_ */
