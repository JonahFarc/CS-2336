// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates a DrinkItem class. This will be used to store drinks and monitor
// their sales, prices, names, and quantity. This class will be able to return the variables and
// change some of them. It can also purchase a drink.

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
		//default constructor for a drinkitem.
		DrinkItem();
		//constructs a drink item with the given name, price and quantity
		DrinkItem(std::string name, double price, unsigned int quantity);
		//copy constructor
		DrinkItem(const DrinkItem& drinkItem);
		//returns the name of the drink
		std::string getName() const;
		//changes the name of the drink to the new name provided
		void setName(std::string newName);
		//returns the price of the drink
		double getPrice() const;
		//changes the price of the drink to the new price provided
		void setPrice(double newPrice);
		//gets the quantity of the drink
		unsigned int getQuantity() const;
		//gets the amount of that drink purchased
		unsigned int getPurchased() const;
		//gets the total sales of that drink
		double getSales() const;
		//adds the specified amount of drinks to the quantity
		void addDrinks(unsigned int amount);
		//purchases a drink if the quantity is greater than 0.
		//Reduces quantity, increases purchased and sales
		bool purchase();
};

#endif /* DRINKITEM_H_ */
