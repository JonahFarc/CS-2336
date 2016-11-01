// Project 3 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the OrderedDoubleLinkedList class that holds a DoubleLinkedList.
// It contains the ability to find and erase elements in the list and inserts in an ordered fashion.

#ifndef ORDEREDDOUBLELINKEDLIST_H_
#define ORDEREDDOUBLELINKEDLIST_H_

#include <cstddef>
#include "DoubleLinkedList.h"

template<class DataType>
class OrderedDoubleLinkedList
{
	private:
		// we are making use of the DoubleLinkedList class
		DoubleLinkedList<DataType> list;
	public:
		// default constructor
		OrderedDoubleLinkedList();
		// destructor
		virtual ~OrderedDoubleLinkedList(){}
		// number of items in the list
		std::size_t size() const {return list.size();};
		// is the list empty (true) or does it have entries (false)
		bool empty() const {return list.empty();};
		// print the items in the list
		void print() const {list.print();};
		// display debug information on the passed in ostream
		void debug(std::ostream &out) const {list.debug(out);};
		// get first node in the list (or nullptr)
		ListNode<DataType>* first() const {return list.first();};
		// get last node in the list (or nullptr)
		ListNode<DataType>* last() const {return list.last();};
		// find the entry and return its address 
		// (nullptr if not found)
		ListNode<DataType>* find(const DataType &existingItem) {return list.find(existingItem);};
		// erase the item by DataType value
		bool erase(const DataType &currentItem) {return list.erase(currentItem);};
		// insert the new item into the list (in sorted order)
		// a duplicate entry will be ignored
		void insert(const DataType &newItem);
};

// default constructor
template <class DataType>
OrderedDoubleLinkedList<DataType>::OrderedDoubleLinkedList()
{
	//instantiates the double linked list
	list = DoubleLinkedList<DataType>();
}

// insert the new item into the list (in sorted order)
// a duplicate entry will be ignored
template <class DataType>
void OrderedDoubleLinkedList<DataType>::insert(const DataType &newItem)
{
	//if the list is empty, add the item to the list using the push_front method
	if(list.empty())
	{
		std::cout<<"ADDING "<<newItem<<" TO the FRONT OF the LIST\n";
		list.push_front(newItem);
		return;
	}

	//set the pointer to the first node in the list
	ListNode<DataType> *ptr = list.first();
	//loop until the end of the list
	while(ptr != nullptr)
	{
		//if the item already exists in the list, update the data
		if(ptr->data() == newItem)
		{
			ptr->data() = newItem;
			return;
		}

		//if it doesn't exist in the list, find the first node greater than the data
		//and insert the data before that node
		if(ptr->data() > newItem)
		{
			list.insert_before(ptr,newItem);
			return;
		}

		//advance the pointer to the next item in the list
		ptr = ptr->next();
	}
	//add the item to the end of the list if nothing is greater than it
	list.push_back(newItem);
}
#endif /* ORDEREDDOUBLELINKEDLIST_H_ */
