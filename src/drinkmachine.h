// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: This is the header file for DrinkMachine. This creates the variables and future methods used.
// <Comments here to describe what the application does>

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
		DrinkMachine();
		~DrinkMachine();
		unsigned int size() const;
		unsigned int max_size() const;
		DrinkItem& at(unsigned int index);
		const DrinkItem& at(unsigned int index) const;
		bool available(unsigned int drinkId) const;
		double getPrice(unsigned int drinkId) const;
		Receipt purchase(unsigned int drinkId, double amount);
		void addDrinks(unsigned int drinkId, unsigned int amount);
		void print(std::ostream& outStream) const;
		double sales() const;
		double sales(unsigned int drinkId) const;
};

#endif /* DRINKMACHINE_H_ */
