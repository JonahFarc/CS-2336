// Assignment 2 for CS 2336.002
// Programmer: Dylan Yu
// Description:
// <Comments here to describe what the application does>

#include "receipt.h"
Receipt::Receipt()
{
	state = "insufficient";
	change = 0.0;
}
Receipt::Receipt(std::string state)
{
	this->state=state;
	change=0.0;
}
Receipt::Receipt(double change)
{
	state = "Success";
	this->change=change;
}
bool Receipt::success() const
{
	return state=="Success";
}
bool Receipt::insufficient() const
{
	return state=="Insufficient";
}
bool Receipt::empty() const
{
	return state=="Empty";
}
double Receipt::getChange() const
{\
	return change;
}

