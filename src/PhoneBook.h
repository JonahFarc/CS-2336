/*
 * PhoneBook.h
 *
 *  Created on: Oct 26, 2016
 *      Author: Korbo
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include "PhoneBookEntry.h"
#include "OrderedDoubleLinkedList.h"
class PhoneBook
{
private:
	OrderedDoubleLinkedList<PhoneBookEntry> phoneBook;
public:
	PhoneBook() {phoneBook = OrderedDoubleLinkedList<PhoneBookEntry>();}
	void insert(const PhoneBookEntry &entry);
	void insert(const std::string &name, const std::string &number, const std::string &email);
	void insert(const std::string &name, const std::string &number);
	bool erase(std::string name);
	bool find(std::string name);
	void print() const {phoneBook.print();}
	std::size_t size() const {return phoneBook.size();}
	ListNode<PhoneBookEntry>* first() const {return phoneBook.first();}
	ListNode<PhoneBookEntry>* last() const {return phoneBook.last();}
	void debug(std::ostream &out) const {phoneBook.debug(out);}
};
	void PhoneBook::insert(const PhoneBookEntry &entry)
	{
		phoneBook.insert(entry);
	}
	void PhoneBook::insert(const std::string &name, const std::string &number, const std::string &email)
	{
		PhoneBookEntry contact = PhoneBookEntry(name, number, email);
		phoneBook.insert(contact);
	}
	void PhoneBook::insert(const std::string &name, const std::string &number)
	{
		PhoneBookEntry contact = PhoneBookEntry(name, number);
		phoneBook.insert(contact);
	}
	bool PhoneBook::erase(std::string name)
	{
		if(find(name))
		{
			PhoneBookEntry temporaryContact = PhoneBookEntry(name,"");
			return phoneBook.erase(temporaryContact);
		}
		return false;
	}
	bool PhoneBook::find(std::string name)
	{
		PhoneBookEntry temporaryContact = PhoneBookEntry(name,"");
		return phoneBook.find(temporaryContact) != nullptr;
	}


#endif /* PHONEBOOK_H_ */
