// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates a DrinkMachine class. This stores a version, the current number of drinks,
// the maximum number of drinks, and all the drinks in the machine. It reads its data from a file
// and rewrites the file when it's closed. It also creates a backup file. This machine can return
// values such as the total sales, and individual aspects of the drinks.

#ifndef DRINKMACHINE_H_
#define DRINKMACHINE_H_
#include "drinkitem.h"
#include "receipt.h"

class DrinkMachine
{
	//initialize variables for the class
	private:
		unsigned int version;
		unsigned int numDrinks;
		DrinkItem drinks[25];
		unsigned int maxDrinks;
	//prototype methods to be instantiated later
	public:
		//constructor for drink machine. Reads in data from a file and creates a backup.
		//creates an array of drinks from these and stores them
		DrinkMachine();
		//saves current state into the file to be read from later.
		~DrinkMachine();
		//returns the number of drinks stored in the machine
		unsigned int size() const;
		//returns the maximum drinks that can be stored in the machine
		unsigned int max_size() const;
		//returns the drink item at the given index
		DrinkItem& at(unsigned int index);
		//returns a const version of the drink item at the given index
		const DrinkItem& at(unsigned int index) const;
		//checks to ensure that the drink item with the given id has a quantity greater than 0
		bool available(unsigned int drinkId) const;
		//returns the price of the drink with the given id
		double getPrice(unsigned int drinkId) const;
		//returns a receipt telling if the drink item was successfully purchased and your change
		Receipt purchase(unsigned int drinkId, double amount);
		//adds the specified amount of the drink with specified id to the machine
		void addDrinks(unsigned int drinkId, unsigned int amount);
		//outputs the properties of the drinks in the drink machine to the given output stream in a particular format
		void print(std::ostream& outStream) const;
		//returns the total number of sales from the machine
		double sales() const;
		//returns sales of the drink with the specified id in the machine
		double sales(unsigned int drinkId) const;
};

#endif /* DRINKMACHINE_H_ */
