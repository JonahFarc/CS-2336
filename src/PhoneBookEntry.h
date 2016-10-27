/*
 * PhoneBookEntry.h
 *
 *  Created on: Oct 26, 2016
 *      Author: Korbo
 */

#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_
#include <string>
#include <iostream>

class PhoneBookEntry{
	std::string sName, number, mail;
public:
	PhoneBookEntry() {sName = ""; number = ""; mail = "";}
	PhoneBookEntry(const std::string &name, const std::string &number) {this->number = number; sName = name;}
	PhoneBookEntry(const std::string &name, const std::string &number, const std::string &email){this->number = number; this->sName = name; mail = email;}
	PhoneBookEntry(const PhoneBookEntry &copyFrom) {}//name = copyFrom.name; number = copyFrom.number; mail = copyFrom.mail;}
	std::string name() const {return sName;}
	std::string phoneNumber() const {return number;}
	std::string email() const {return mail;}
	void phoneNumber(const std::string &newNumber) {number = newNumber;}
	void email(const std::string &newEmail) {mail = newEmail;}
	bool operator==(const PhoneBookEntry& other)
	{
		std::cout<<"ENTRY COMPARE == " << other<<"\n"<<sName<<" "<<number<<" "<<mail<<"\n";
		std::cout<<sName<<" "<<other.name()<<" compared "<<(sName<other.name())<<" "<<sName.compare(other.name())<<"\n";
		return sName.compare(other.name()) == 0;
	}
	bool operator!=(const PhoneBookEntry& other)
	{
		std::cout<<"ENTRY COMPARE != " << other<<"\n"<<sName<<" "<<number<<" "<<mail<<"\n";
		std::cout<<sName<<" "<<other.name()<<" compared "<<(sName<other.name())<<" "<<sName.compare(other.name())<<"\n";
		return sName.compare(other.sName) != 0;
	}
	bool operator<(const PhoneBookEntry& other)
	{
		std::cout<<"ENTRY COMPARE < " << other<<"\n"<<sName<<" "<<number<<" "<<mail<<"\n";
		std::cout<<sName<<" "<<other.name()<<" compared "<<(sName<other.name())<<" "<<sName.compare(other.name())<<"\n";
		return sName.compare(other.sName) < 0;
	}
	bool operator<=(const PhoneBookEntry& other) {return sName.compare(other.sName) <= 0;}
	bool operator>(const PhoneBookEntry& other)
	{
		std::cout<<"ENTRY COMPARE > " << other<<"\n"<<sName<<" "<<number<<" "<<mail<<"\n";
		std::cout<<sName<<" "<<other.name()<<" compared "<<(sName<other.name())<<" "<<sName.compare(other.name())<<"\n";
		return sName.compare(other.sName) > 0;
	}
	bool operator>=(const PhoneBookEntry& other) {return sName.compare(other.sName) >= 0;}
	friend std::ostream& operator<<(std::ostream &out, const PhoneBookEntry &entry);
};

#endif /* PHONEBOOKENTRY_H_ */
