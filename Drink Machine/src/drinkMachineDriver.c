//============================================================================
// Name			: drinkMachineDriver.c
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

#include "drink_item.h"
#include "drink_machine.h"
#include "DrinkAvailabilityEnum.h"
#include "PurchaseEnum.h"
#include <stdio.h>
#include <stdlib.h>


//Output buffers get flushed every time for finding crash location
int main(void)
{
	DrinkMachine * theMachine = createMachine();

	// Quit if the machine was not built properly
	if(theMachine == NULL)
	{
		printf("The machine was not created properly. Program will exit now...");
		fflush(stdout);
		return EXIT_FAILURE;
	}


	//End condition for menu loop. If set to 1, loop ends
	int quitFlag = 0;

	dumpDrinkMachine(theMachine);

	do
	{
		int choice = -1;
		double userMoney = 0;
		double changeOrCost = 0.00;

		printf("Enter a drink id for the drink you want to purchase or 0 to quit: ");
		fflush(stdout);
		scanf("%d", &choice);
		//printf("\n");	//May not need this line on eclipse atleast because scanf is making a newline

		if(choice == 0)
		{
			quitFlag = 1;
			printf("Thank you for using the drink machine.\n\n");
			fflush(stdout);

		}
		else if( !(choice >= 1 && choice <= theMachine->numberOfDrinkItems) )
		{
			printf("The drink ID is not valid.\n");
			fflush(stdout);
			continue;
		}
		else if (choice >= 1 && choice <= theMachine->numberOfDrinkItems)
		{
			printf("Enter the amount for the purchase (up to $2.00): ");
			fflush(stdout);
			scanf("%lf", &userMoney);
			//printf("\n");	//May not need this line on eclipse atleast because scanf is making a newline
			fflush(stdout);

			while(userMoney > 2.00)
			{
				printf("The amount entered is not valid.\n");
				printf("Enter the amount for the purchase (up to $2.00): ");
				fflush(stdout);
				scanf("%lf", &userMoney);
				fflush(stdout);
			}

			int purchaseResult = purchase(theMachine, choice, userMoney, &changeOrCost);

			switch(purchaseResult)
			{
			//Invalid drink ID
			case INVALID:
				printf("The drink ID is not valid\n");
				fflush(stdout);
				continue;
				break;

			case PURCHASED:
				printf("Your drink has been purchased. Your change is $ %.2lf \n", changeOrCost);
				fflush(stdout);
				break;

			case NOT_AVAILABLE:
				printf("Sorry, we are out of your drink. Please select another drink. \n");
				fflush(stdout);
				break;

			case INSUFFICIENT_FUNDS:
				printf("The amount you entered is insufficient to purchase the drink. The price is $ %.2lf \n", changeOrCost);
				fflush(stdout);
				break;

			default:
				printf("An error was encountered in the menu's switch statement. Exiting program...");
				fflush(stdout);
				return EXIT_FAILURE;
				break;
			}//End switch

		}// End else if block
		else
		{
			printf("An error has been encountered in the menu loop. Exiting...");
			fflush(stdout);
			return EXIT_FAILURE;
		}

	}while(quitFlag != 1);



	destroyMachine(theMachine);

	//Reset flag just in case
	quitFlag = 0;

	return EXIT_SUCCESS;

}


