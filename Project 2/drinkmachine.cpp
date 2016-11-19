// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: Defines the methods for the drink machine. It stores a number of drinks up to a max value, and has a version number as well.
// This machine reads in drinks through a file called "drink.txt" and stores a backup of the file. It saves the new data
// when it is destroyed. It allows purchasing of drinks and accessing of each drink. It can also output a menu and the total sales.

#include "drinkmachine.h"
#include "receipt.h"
#include <iostream>
#include <fstream>
#include <iomanip>

//default constructor of a drink machine.
//Reads in values of drinks from a file and creates a backup of the file
//creates drinks based on input
DrinkMachine::DrinkMachine()
{
	//read in files
	std::ifstream inFile("drink.txt");
	std::ofstream outFile("drink_backup.txt");
	//set default values for variables
	maxDrinks = 25;
	version = 1;
	numDrinks = 0;
	//read in number of drinks to loop through
	inFile >> numDrinks;
	outFile << numDrinks << "\n";
	//loop through drinks
	for(unsigned int i = 0; i < numDrinks; i++)
	{
		//read in values for the drink
		std::string name;
		double price;
		unsigned int quantity;
		inFile >> name >> price >> quantity;
		//create the drink
		drinks[i] = DrinkItem(name, price, quantity);
		//create backup file for the drink
		outFile << std::setw(20) << std::left << name << std::right;
		outFile << std::setw(7) << std::fixed << std::setprecision(2) << price << std::setprecision(std::cout.precision());
		outFile << std::setw(7) << quantity << "\n";
	}
	inFile.close();
	outFile.close();
}

//destructor saves current drink machine to the file
DrinkMachine::~DrinkMachine()
{
	//opens the file to write to
	std::ofstream outFile("drink.txt");
	//reads nubmer of drinks in the machine
	outFile << numDrinks << "\n";
	//loops through the number of drinks in the machine
	for(unsigned int i = 0; i < numDrinks; i++)
	{
		//stores the drinks in the file
		outFile << std::setw(20) << std::left << drinks[i].getName() << std::right;
		outFile << std::setw(7) << std::fixed << std::setprecision(2) << drinks[i].getPrice() << std::setprecision(std::cout.precision());
		outFile << std::setw(7) << drinks[i].getQuantity() << "\n";
	}
}
DrinkItem* DrinkMachine::begin(){
	return (drinks);
	//return &(drinks[0]);
}
DrinkItem* DrinkMachine::end(){
	return (drinks+numDrinks);
	//return &(drinks[numDrinks]);
}
//return the number of drinks being stored in the machine
unsigned int DrinkMachine::size() const
{
	return numDrinks;
}

//return the max number of drinks that can be held by the drink machine
unsigned int DrinkMachine::max_size() const
{
	return maxDrinks;
}

//gets the drink item at the given index of the machine
DrinkItem& DrinkMachine::at(unsigned int index)
{
	return drinks[index];
}

//gets a const version of the drink item at the given index of the machine
const DrinkItem& DrinkMachine::at(unsigned int index) const
{
	return drinks[index];
}

//returns whether or not the drink with the given drink id is available
bool DrinkMachine::available(unsigned int drinkId) const
{
	return drinks[drinkId].getQuantity() > 0;
}

//returns the price of the drink with the given drink id
double DrinkMachine::getPrice(unsigned int drinkId) const
{
	return drinks[drinkId].getPrice();
}

//checks to see if the drink can be purchased with the given amount of money
//if it can, returns a receipt with the proper amount of change
//otherwise returns a receipt holding an error state
Receipt DrinkMachine::purchase(unsigned int drinkId, double amount)
{
	//gets the drink at the current ID
	DrinkItem drink = drinks[drinkId];
	//makes sure the amount paid is enough for the drink
	if(amount >= drink.getPrice())
	{
		//makes sure the drink is still available
		if(drink.getQuantity() > 0)
		{
			//purchases the drink and returns the change
			drinks[drinkId].purchase();
			return Receipt(SUCCESS, amount - drink.getPrice());
		}
		//sets the receipt to the "empty" state
		return Receipt(EMPTY);
	}
	//sets the receipt to the insufficient funds state
	return Receipt(INSUFFICIENT);
}

//adds the amount of drinks with the given drink id
void DrinkMachine::addDrinks(unsigned int drinkId, unsigned int amount)
{
	drinks[drinkId].addDrinks(amount);
}

//outputs the drink machine version, the number of entries, and
//the id, name, price,, quantity, number sold, and sales from each drink in the machine
void DrinkMachine::print(std::ostream& outStream) const
{
	outStream << "Drink Machine Version " << version << "\n";
	outStream << "Number of entries: " << numDrinks << "\n\n";
	outStream << std::setw(6) << "Id";
	outStream << std::setw(27) << std::left << " Name " << std::right;
	outStream << std::setw(7) << " Price $ ";
	outStream << std::setw(7) << "Qty ";
	outStream << std::setw(7) << "Sold ";
	outStream << std::setw(9) << "Sales $\n";
	for(unsigned int i = 0; i < numDrinks; i++)
	{
		outStream << std::setw(6) << i;
		outStream << " " << std::setw(27) << std::left << drinks[i].getName() << std::right;
		outStream << std::setw(7) << drinks[i].getPrice();
		outStream << std::setw(7) << drinks[i].getQuantity();
		outStream << std::setw(7) << drinks[i].getPurchased();
		outStream << std::setw(9) << drinks[i].getSales() << "\n";
	}
}

//gets the total sales from the drink machine
double DrinkMachine::sales() const
{
	double sum = 0;
	//sums all of the drinks in the array
	for(unsigned int i = 0; i < numDrinks; i++)
		sum += drinks[i].getSales();
	//returns the sum
	return sum;
}

//gets the sales from the drink with the given drink id in the drink machine
double DrinkMachine::sales(unsigned int drinkId) const
{
	return drinks[drinkId].getSales();
}
