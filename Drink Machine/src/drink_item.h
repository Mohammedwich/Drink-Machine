/*
 * drink_item.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Mohax
 */

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

} typedef DrinkItem;

#endif /* DRINK_ITEM_H_ */
