// Project 3 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the PhoneBook class. The phone book holds a list of phone book entries
// and can insert, erase, and find elements of the list and print them. It has some accessors
// such as the size and the first and last node.

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include "PhoneBookEntry.h"
#include "OrderedDoubleLinkedList.h"

class PhoneBook
{
private:
	OrderedDoubleLinkedList<PhoneBookEntry> phoneBook;
public:
	//default constructor
	PhoneBook() {phoneBook = OrderedDoubleLinkedList<PhoneBookEntry>();}
	//inserts the given entry into the list
	void insert(const PhoneBookEntry &entry);
	//insert a phone book entry into the list with the name, number, and email given
	void insert(const std::string &name, const std::string &number, const std::string &email);
	//insert a phone book entry into the list with the name and number given
	void insert(const std::string &name, const std::string &number);
	//erase a phone book entry from the phone book with the given name
	bool erase(std::string name);
	//find a phone book entry from the phone book with the given name
	bool find(std::string name);
	//output the phone book
	void print() const {phoneBook.print();}
	//return the size of the phone book
	std::size_t size() const {return phoneBook.size();}
	//returns the first entry in the list
	ListNode<PhoneBookEntry>* first() const {return phoneBook.first();}
	//returns the last entry in the list
	ListNode<PhoneBookEntry>* last() const {return phoneBook.last();}
	//display a debug version of the list
	void debug(std::ostream &out) const {phoneBook.debug(out);}
};

//inserts the given entry into the list
void PhoneBook::insert(const PhoneBookEntry &entry)
{
	//add the contact to the phone book
	phoneBook.insert(entry);
}

//insert a phone book entry into the list with the name, number, and email given
void PhoneBook::insert(const std::string &name, const std::string &number, const std::string &email)
{
	//create the contact and add it to the phone book
	PhoneBookEntry contact = PhoneBookEntry(name, number, email);
	phoneBook.insert(contact);
}

//insert a phone book entry into the list with the name and number given
void PhoneBook::insert(const std::string &name, const std::string &number)
{
	//create the contact and add it to the phone book
	PhoneBookEntry contact = PhoneBookEntry(name, number);
	phoneBook.insert(contact);
}

//erase a phone book entry from the phone book with the given name
bool PhoneBook::erase(std::string name)
{
	//check if the item exists in the list
	if(find(name))
	{
		//create an entry data type to erase from the phone book
		PhoneBookEntry temporaryContact = PhoneBookEntry(name,"");
		return phoneBook.erase(temporaryContact);
	}
	//the item is not in the list, nothing to erase
	return false;
}

//find a phone book entry from the phone book with the given name
bool PhoneBook::find(std::string name)
{
	//create a contact with the given name and search for the contact
	PhoneBookEntry temporaryContact = PhoneBookEntry(name,"");
	return phoneBook.find(temporaryContact) != nullptr;
}

#endif /* PHONEBOOK_H_ */
