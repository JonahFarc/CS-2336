// Project 3 for CS 2336.002
// Programmer: Dylan Yu
// Description: Instantiates the methods for the phone book entry class. The output operator
// was overloaded in order to output the phone book entry in a formatted fashion.

#include "PhoneBookEntry.h"
#include <iostream>
#include <iomanip>

//default constructor
PhoneBookEntry::PhoneBookEntry()
{
	//instantiate all values as empty
	sName = "";
	number = "";
	mail = "";
}

//constructor for name and number
PhoneBookEntry::PhoneBookEntry(const std::string &name, const std::string &number)
{
	//set values to values given. set email to empty string
	this->number = number;
	sName = name;
	mail = "";
}

//constructor for name, number and email
PhoneBookEntry::PhoneBookEntry(const std::string &name, const std::string &number, const std::string &email)
{
	//set values to values given
	this->number = number;
	sName = name;
	mail = email;
}

//copy constructor
PhoneBookEntry::PhoneBookEntry(const PhoneBookEntry &copyFrom)
{
	//copies values from the other phone book entry
	sName = copyFrom.name();
	number = copyFrom.phoneNumber();
	mail = copyFrom.email();
}

//outputs the formatted phone book entry
std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry)
{
	out << "[[Name: " << std::setw(15) << std::left << entry.name();
	out << "], [Number: " << std::setw(12) << std::right << entry.phoneNumber() << "]";
	if(entry.email() != "")
		out << ", [Email: " << entry.email()<<"]";
	out << "]";
	return out;
}
