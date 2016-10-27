/*
 * PhoneBookEntry.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: Korbo
 */
#include "PhoneBookEntry.h"
#include <iostream>
#include <iomanip>
std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry)
{
	out << "Name: " << std::setw(15) << std::left << entry.name();
	out << ", Number: " << std::setw(12) << std::right << entry.phoneNumber();
	if(entry.email() != "")
		out << ", Email: " << entry.email();
	return out;
}




