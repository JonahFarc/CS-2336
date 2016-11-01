// Project 3 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates a PhoneBookEntry class. Holds a name, email, and phone number.
// The comparison operators have been overloaded in order to be able to compare this class
// with another of itself.

#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_
#include <string>
#include <iostream>

class PhoneBookEntry{
	std::string sName, number, mail;
public:
	//default constructor
	PhoneBookEntry();
	//constructor with name and number
	PhoneBookEntry(const std::string &name, const std::string &number);
	//constructor with name, number, and email
	PhoneBookEntry(const std::string &name, const std::string &number, const std::string &email);
	//copy constructor
	PhoneBookEntry(const PhoneBookEntry &copyFrom);
	//get the name of the phone book entry
	std::string name() const {return sName;}
	//get the number of the phone book entry
	std::string phoneNumber() const {return number;}
	//get the email of the phone book entry
	std::string email() const {return mail;}
	//set the phone number of the entry to the given number
	void phoneNumber(const std::string &newNumber) {number = newNumber;}
	//set the email of the entry to the given email
	void email(const std::string &newEmail) {mail = newEmail;}
	//returns true if the names are the same
	bool operator==(const PhoneBookEntry& other){return sName.compare(other.name()) == 0;}
	//returns true if the name are not the same
	bool operator!=(const PhoneBookEntry& other){return sName.compare(other.sName) != 0;}
	//returns true if the name is alphabetically before the other name
	bool operator<(const PhoneBookEntry& other){return sName.compare(other.sName) < 0;}
	//returns true if the name is alphabetically before or equal to the other name
	bool operator<=(const PhoneBookEntry& other) {return sName.compare(other.sName) <= 0;}
	//returns true if the name is alphabetically after the other name
	bool operator>(const PhoneBookEntry& other){return sName.compare(other.sName) > 0;}
	//returns true if the name is alphabetically after or equal to the other name
	bool operator>=(const PhoneBookEntry& other) {return sName.compare(other.sName) >= 0;}
	//outputs the formatted phone book entry
	friend std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry);
};

#endif /* PHONEBOOKENTRY_H_ */
