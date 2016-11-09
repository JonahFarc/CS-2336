/*
 * test.cpp
 *
 *  Created on: Oct 25, 2016
 *      Author: Tiffany
 */

#include "DoubleLinkedList.h"
#include "OrderedDoubleLinkedList.h"
#include "PhoneBook.h"
#include <iostream>
int main()
{
	/*
	std::cout<<"what am i doing\n";
	DoubleLinkedList<int> list = DoubleLinkedList<int>();
	//list.insert(5);
	list.push_front(2);
	list.push_back(8);
	//list.insert(7);
	//list.insert(9);
	list.insert_before(list.find(8),7);
	list.insert_after(list.find(8),9);
	list.print();
	list.erase(8);
	//list.insert(7);
	std::cout<<"no crash\n";
	list.debug(std::cout);
	auto list2(list);
	list2.debug(std::cout);*/
	PhoneBookEntry entry = PhoneBookEntry("Bob Joe","123-456-7890","asadf@gmail.com");
	PhoneBookEntry entry2 = PhoneBookEntry("Joey","122-455-7777","asdf@gmail.com");
	PhoneBookEntry entry3 = PhoneBookEntry("Billy","111-888-1234","ihatewritingtestcases@gmail.com");
	PhoneBookEntry entry4 = PhoneBookEntry("Jack","124-234-2344","thelastcase@hotmail.com");
	std::cout<<entry<<"\n";
	std::cout<<entry2<<"\n";
	std::cout<<entry3<<"\n";
	std::cout<<entry4<<"\n";
	PhoneBookEntry entry5 = PhoneBookEntry(entry4);
	std::cout<<entry5<<"\n";
	entry4.phoneNumber("111-111-1111");
	std::cout<<entry4<<"\n";
	std::cout<<entry5<<"\n";
	PhoneBook phoneBook;
	DoubleLinkedList<PhoneBookEntry> book = DoubleLinkedList<PhoneBookEntry>();
	book.push_front(entry);
	book.push_front(entry2);
	book.push_front(entry3);
	book.push_front(entry4);
	book.debug(std::cout);
	DoubleLinkedList<PhoneBookEntry> book2(book);
	book2.debug(std::cout);

}
