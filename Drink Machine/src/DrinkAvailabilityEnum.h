//============================================================================
// Name			: DrinkAvailabilityEnum.h
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

#ifndef DRINKAVAILABILITYENUM_H_
#define DRINKAVAILABILITYENUM_H_

#include <stdio.h>
#include <stdlib.h>

enum DrinkAvailability
{
	INVALID_SELECTION = 1, AVAILABLE = 2, VALID_SELECTION_BUT_OUT = 3
};

#endif /* DRINKAVAILABILITYENUM_H_ */
