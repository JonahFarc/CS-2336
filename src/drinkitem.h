// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: This is the header file of DrinkItem. This creates the variables and future methods used.

#ifndef DRINKITEM_H_
#define DRINKITEM_H_
#include <string>

class DrinkItem
{
	//initialize variables to be used in the class.
	private:
		std::string name;
		double price;
		unsigned int quantity;
		unsigned int purchased;
		double sales;
	//prototype methods to be instantiated later.
	public:
		DrinkItem();
		DrinkItem(std::string name, double price, unsigned int quantity);
		std::string getName() const;
		void setName(std::string newName);
		double getPrice() const;
		void setPrice(double newPrice);
		unsigned int getQuantity() const;
		unsigned int getPurchased() const;
		double getSales() const;
		void addDrinks(unsigned int amount);
		bool purchase();
};

#endif /* DRINKITEM_H_ */
