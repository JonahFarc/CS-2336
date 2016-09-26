// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: DrinkItem represents a drink. It stores the name, price, quantity, number of times purchased, and total sales of a drink.
// It has accessors for all of its variables and mutators for the name and price. The quantity can also be incremented.
// It can purchase a drink, changing the quantity, number of times purchased, and total sales.

#include "drinkitem.h"
#include <iostream>
//default constructor
DrinkItem::DrinkItem()
{
	//instantiates variables to default values
	name = "";
	price = 0.0;
	quantity = 0;
	purchased = 0;
	sales = 0;
}
//constructor given name, price, and quantity of the drink
DrinkItem::DrinkItem(std::string name, double price, unsigned int quantity)
{
	//instantiates variables to the given values
	this->name = name;
	this->price = price;
	this->quantity = quantity;
	purchased = 0;
	sales = 0;
}
//gets the name of the drink
std::string DrinkItem::getName() const
{
	return name;
}
//sets the name of the drink to the name specified
void DrinkItem::setName(std::string newName)
{
	name = newName;
}
//gets the price of the drink
double DrinkItem::getPrice() const
{
	return price;
}
//set the price of the drink to the price specified
void DrinkItem::setPrice(double newPrice)
{
	price = newPrice;
}
//gets the quantity of the drink
unsigned int DrinkItem::getQuantity() const
{
	return quantity;
}
//gets the number of purchased drinks of this type
unsigned int DrinkItem::getPurchased() const
{
	return purchased;
}
//gets the amount of money earned by the purchases
double DrinkItem::getSales() const
{
	return sales;
}
//increases the quantity by the given amount
void DrinkItem::addDrinks(unsigned int amount)
{
	quantity += amount;
}
//checks if the drink has quantity, then purchases it.
bool DrinkItem::purchase()
{
	//check quantity
	if(!quantity > 0)
		return false;
	//update values
	quantity--;
	purchased++;
	sales += price;
	return true;
}

