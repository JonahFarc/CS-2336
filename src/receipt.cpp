/*
 * receipt.cpp
 *
 *  Created on: Sep 25, 2016
 *      Author: Dylan Yu
 */
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

