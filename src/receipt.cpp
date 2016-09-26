// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: Receipt has a state and change. If the state is in the success state, the change is
// the amount of change given from purchasing the drink. Otherwise, the receipt will tell the error
// and offer no change

#include "receipt.h"
//creates a default constructor, giving it the insufficient funds state with no change
Receipt::Receipt()
{
	state = "Insufficient";
	change = 0.0;
}
//sets the receipt state to the state given and sets the change to 0
Receipt::Receipt(std::string state)
{
	this->state = state;
	change = 0.0;
}
//sets the change to the amount given and sets the receipt to the success state
Receipt::Receipt(double change)
{
	state = "Success";
	this->change = change;
}
//returns true if the receipt is in the success state
bool Receipt::success() const
{
	return state == "Success";
}
//returns true if the receipt is in the insufficient funds state
bool Receipt::insufficient() const
{
	return state == "Insufficient";
}
//returns true if the receipt is in the empty state
bool Receipt::empty() const
{
	return state == "Empty";
}
//returns the amount of change in the receipt
double Receipt::getChange() const
{
	return change;
}
