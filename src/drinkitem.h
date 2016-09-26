// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description:
// <Comments here to describe what the application does>

#ifndef DRINKITEM_H_
#define DRINKITEM_H_
#include <string>

class DrinkItem
{
private:
	std::string name;
	double price;
	unsigned int quantity;
	unsigned int purchased;
	double sales;
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
