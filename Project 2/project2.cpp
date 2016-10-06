/*
 * project2.cpp
 *
 * Drink machine simulator.
 *
 * This project uses two classes, DrinkMachine and DrinkItem
 * to simulate a drink machine.
 *
 *  Created on: Sep 20, 2016
 *      Author: dgv130030
 */

#include <iostream>
#include <iomanip>
#include <string>

// bring in the drink machine and associated classes
#include "drinkmachine.h"
#include "drinkitem.h"
#include "receipt.h"

class DrinkMachineApplication
{
	private:
		DrinkMachine drinkMachine;
	public:
		DrinkMachineApplication();
		void run();
	private:
		void displayMenu();
		unsigned int getMenuValue() const;
		void restock();
};

// driver for the application
int main()
{
	DrinkMachineApplication application;
	application.run();
	return 0;
}

DrinkMachineApplication::DrinkMachineApplication()
{
	// don't do anything
}

// run the application
void DrinkMachineApplication::run()
{
	if (drinkMachine.size() == 0)
	{
		std::cout << "The drink machine is empty" << std::endl;
		return;
	}

	// output money amounts in the format xxxx.xx
	std::cout << std::fixed << std::setprecision(2);

	unsigned int menuItem;

	// main processing loop
	do
	{
		// display the menu
		displayMenu();

		menuItem = getMenuValue();

		// process the menu item
		if (menuItem < drinkMachine.size())
		{
			// prompt for the amount
			double amount;
			std::cout << "Enter the amount of the purchase: ";
			std::cin >> amount;

			// try the purchase
			DrinkItem &item = drinkMachine.at(menuItem);
			Receipt receipt = drinkMachine.purchase(menuItem, amount);

			// check the results of the purchase
			if (receipt.success())
			{
				std::cout << "Your purchase of " << item.getName();
				std::cout << " succeeded. ";

				// get the change (if any)
				double change = receipt.getChange();
				if (change == 0.0)
				{
					std::cout << " There was no change" << std::endl;
				}
				else
				{
					std::cout << " Your change is $" << change << std::endl;
				}
			}
			else if (receipt.insufficient())
			{
				// insufficient funds
				std::cout << "You need additional money for the purchase" << std::endl;
			}
			else if (receipt.empty())
			{
				// there is no more of this drink in the machine
				std::cout << "Your selection is empty" << std::endl;
			}
			else
			{
				// if this happens you have logic errors in the Receipt class
				std::cout << "The receipt is invalid" << std::endl;
			}
		}

	} while (menuItem != drinkMachine.size());

	// display the output from the run
	std::cout << std::endl;
	drinkMachine.print(std::cout);
	std::cout << std::endl;

	std::cout << "The total sales is $" << drinkMachine.sales() << std::endl;

	// restock the drinks
	std::cout << std::endl;
	std::cout << "Now restock the drink machine" << std::endl;
	restock();

	// display the final output after restocking
	std::cout << std::endl;
	drinkMachine.print(std::cout);
	std::cout << std::endl;
}

// Display the drink machine menu
void DrinkMachineApplication::displayMenu()
{
	const int ID_WIDTH = 6;
	const int NAME_WIDTH = 25;
	const int PRICE_WIDTH = 10;
	const int QTY_WIDTH = 8;

	// make sure the price is output in the format xxxx.xx
	std::cout << std::fixed << std::setprecision(2);

	std::cout << std::endl;

	// output some headers
	std::cout << std::setw(ID_WIDTH) << "Menu #" << " ";
	std::cout << std::left << std::setw(NAME_WIDTH) << "Name" << std::right;
	std::cout << std::setw(PRICE_WIDTH) << "Price $";
	std::cout << std::setw(QTY_WIDTH) << "Qty";
	std::cout << std::endl;

	// for each drink type output the drink information
	for (unsigned int itemId=0; itemId<drinkMachine.size(); itemId++)
	{
		auto item = drinkMachine.at(itemId);
		std::cout << std::setw(ID_WIDTH) << itemId << " ";
		std::cout << std::left << std::setw(NAME_WIDTH) << item.getName();
		std::cout << std::right << std::setw(PRICE_WIDTH) << item.getPrice();
		std::cout << std::setw(QTY_WIDTH) << item.getQuantity();
		std::cout << std::endl;
	}

	// exit menu item
	std::cout << std::setw(ID_WIDTH) << drinkMachine.size() << " "
			  << std::left << std::setw(NAME_WIDTH) << "exit program"
			  << std::right << std::endl;

}

// read in and validate the menu item
unsigned int DrinkMachineApplication::getMenuValue() const
{
	// holds the menu item
	unsigned int menuItem;

	// keeps track of the validity of the input data
	bool valid;

	//  keep displaying the menu until we get a valid value
	do
	{
		std::cout << "Enter a menu item: ";
		std::cin >> menuItem;

		// check for errors
		if (std::cin.fail())
		{
			// we had an error
			valid = false;

			// the input is invalid, so we need to discard it and
			// clear out the error
			std::string invalidData;

			// clear out the error
			std::cin.clear();

			// read in the bad data
			std::getline(std::cin, invalidData);

			// output an error message
			std::cout << "Invalid input \"" << invalidData
			          << "\" has been discarded"<< std::endl;
		}
		else if (menuItem > drinkMachine.size())
		{
			// the menu selection is out of range
			valid = false;
			std::cout << "The menu item is not valid" << std::endl;
		}
		else
		{
			// the menu value is valid
			valid = true;
		}

	} while ( !valid );

	return menuItem;
}

// go through all of the items and restock any that are 0
void DrinkMachineApplication::restock()
{
	const unsigned int amount = 5;

	// go through all of the drink items and see if any are 0
	for (unsigned int itemId=0; itemId < drinkMachine.size(); itemId++)
	{
		auto drinkItem = drinkMachine.at(itemId);

		if (drinkItem.getQuantity() == 0)
		{
			// output a message saying we are out of drinks
			std::cout << "Drink " << drinkItem.getName()
					  << " is out of stock. Restocking with "
					  << amount << " drinks." << std::endl;

			// add the drinks to the machine
			drinkMachine.addDrinks(itemId, amount);
		}
	}
}
