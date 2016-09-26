// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: This is the header file for Receipt. This creates the variables and future methods used.

#ifndef RECEIPT_H_
#define RECEIPT_H_

#include "drinkitem.h"

class Receipt
{
	//initialize variables for the receipt
	private:
		std::string state;
		double change;
	//prototype methods to be used later
	public:
		Receipt();
		Receipt(std::string state);
		Receipt(double change);
		bool success() const;
		bool insufficient() const;
		bool empty() const;
		double getChange() const;
};

#endif /* RECEIPT_H_ */
