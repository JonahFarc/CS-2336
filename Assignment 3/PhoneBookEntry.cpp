/*
 * PhoneBookEntry.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Korbo
 *
#include "PhoneBookEntry.h"
#include <iostream>
#include <iomanip>
std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry)
{
	out << "Name: " << std::setw(15) << entry.name();
	out << ", Number: " << std::setw(12) << entry.phoneNumber();
	out << ", Email: " << std::setw(15) << entry.email() <<"\n";
	return out;
}



*/
