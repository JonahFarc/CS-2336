// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description:
// <Comments here to describe what the application does>

#ifndef RECEIPT_H_
#define RECEIPT_H_

#include "drinkitem.h"

class Receipt
{
private:
	std::string state;
	double change;
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
