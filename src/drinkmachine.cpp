// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description:
// <Comments here to describe what the application does>

#include "drinkmachine.h"
#include "receipt.h"
#include <iostream>
#include <fstream>
#include <iomanip>
DrinkMachine::DrinkMachine()
{
	std::ifstream inFile("drink.txt");
	std::ofstream outFile("drink_backup.txt");
	maxDrinks = 25;
	version = 1;
	numDrinks = 0;
	inFile >> numDrinks;
	outFile << numDrinks << "\n";
	for (unsigned int i = 0; i < numDrinks; i++)
	{
		std::string name;
		double price;
		unsigned int quantity;
		inFile >> name >> price >> quantity;
		drinks[i] = DrinkItem(name, price, quantity);
		outFile << std::setw(20) << std::left << name << std::right;
		outFile << std::setw(7) << std::fixed << std::setprecision(2) << price << std::setprecision(std::cout.precision());
		outFile << std::setw(7) << quantity << "\n";
	}
	inFile.close();
	outFile.close();
}
DrinkMachine::~DrinkMachine()
{
	std::ofstream outFile("drink.txt");
	outFile << numDrinks << "\n";
	for (unsigned int i = 0; i < numDrinks; i++)
	{
		outFile << std::setw(20) << std::left << drinks[i].getName() << std::right;
		outFile << std::setw(7) << std::fixed << std::setprecision(2) << drinks[i].getPrice() << std::setprecision(std::cout.precision());
		outFile << std::setw(7) << drinks[i].getQuantity() << "\n";
	}
}
unsigned int DrinkMachine::size() const
{
	return numDrinks;
}
unsigned int DrinkMachine::max_size() const
{
	return maxDrinks;
}
DrinkItem& DrinkMachine::at(unsigned int index)
{
	return drinks[index];
}
const DrinkItem& DrinkMachine::at(unsigned int index) const
{
	return drinks[index];
}
bool DrinkMachine::available(unsigned int drinkId) const
{
	return drinks[drinkId].getQuantity() > 0;
}
double DrinkMachine::getPrice(unsigned int drinkId) const
{
	return drinks[drinkId].getPrice();
}
Receipt DrinkMachine::purchase(unsigned int drinkId, double amount)
{
	DrinkItem drink = drinks[drinkId];
	if (amount >= drink.getPrice())
	{
		if (drink.getQuantity() > 0)
		{
			drinks[drinkId].purchase();
			return Receipt(amount - drink.getPrice());
		}
		return Receipt("Empty");
	}
	return Receipt("Insufficient");
}
void DrinkMachine::addDrinks(unsigned int drinkId, unsigned int amount)
{
	drinks[drinkId].addDrinks(amount);
}
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
	for (unsigned int i = 0; i < numDrinks; i++)
	{
		outStream << std::setw(6) << i;
		outStream << " " << std::setw(27) << std::left << drinks[i].getName()
				<< std::right;
		outStream << std::setw(7) << drinks[i].getPrice();
		outStream << std::setw(7) << drinks[i].getQuantity();
		outStream << std::setw(7) << drinks[i].getPurchased();
		outStream << std::setw(9) << drinks[i].getSales() << "\n";
	}
}
double DrinkMachine::sales() const
{
	double sum = 0;
	for (unsigned int i = 0; i < numDrinks; i++)
		sum += drinks[i].getSales();
	return sum;
}
double DrinkMachine::sales(unsigned int drinkId) const
{
	return drinks[drinkId].getSales();
}
