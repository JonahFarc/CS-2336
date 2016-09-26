/*
 * drinkmachine.h
 *
 *  Created on: Sep 24, 2016
 *      Author: Dylan Yu
 */

#ifndef DRINKMACHINE_H_
#define DRINKMACHINE_H_
#include "drinkitem.h"
#include "receipt.h"
class DrinkMachine
{
private:
	unsigned int version;
	unsigned int numDrinks;
	DrinkItem drinks[25];
	unsigned int maxDrinks;
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
