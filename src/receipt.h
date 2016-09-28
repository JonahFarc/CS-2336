// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the receipt class. The receipt class has a state and change. If the state
// is a success state, then the change will be relevant. otherwise, the change will be set to 0.
// The states are an enumerator which hold insufficient, empty, and success.

#ifndef RECEIPT_H_
#define RECEIPT_H_

#include "drinkitem.h"

//creates an enum to store the possible states of the receipt
enum states{INSUFFICIENT, SUCCESS, EMPTY};

class Receipt
{
	//initialize variables for the receipt
	private:
		states state;
		double change;
	//prototype methods to be used later
	public:
		//creates a receipt defaulting to the insufficient funds state
		Receipt();
		//creates a receipt with the given state and no change
		Receipt(states state);
		//creates a successful receipt with the given change
		Receipt(double change);
		//creates a receipt with the given state and change;
		Receipt(states state, double change);
		//returns true if the receipt is in the success state
		bool success() const;
		//returns true if the receipt is in the insufficient funds state
		bool insufficient() const;
		//returns true if the receipt is in the empty state
		bool empty() const;
		//returns the amount of change in the receipt
		double getChange() const;
};

#endif /* RECEIPT_H_ */
