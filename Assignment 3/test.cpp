/*
 * test.cpp
 *
 *  Created on: Oct 25, 2016
 *      Author: Tiffany
 */

#include "DoubleLinkedList.h"
#include "OrderedDoubleLinkedList.h"
#include <iostream>
int main()
{
	std::cout<<"what am i doing\n";
	OrderedDoubleLinkedList<int> list = OrderedDoubleLinkedList<int>();
	list.insert(5);
	list.insert(2);
	//list.pop_front();
	list.insert(8);
	list.insert(7);
	list.insert(9);
	//list.insert_before(list.find(8),7);
	//list.insert_after(list.find(8),9);
	list.print();
	list.erase(8);
	list.insert(7);
	std::cout<<"no crash\n";
	list.debug(std::cout);
}
