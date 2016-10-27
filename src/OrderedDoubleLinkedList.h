/*
 * OrderedDoubleLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

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
		virtual ~OrderedDoubleLinkedList();
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

// Your implementation code goes here
// default constructor
template <class DataType>
OrderedDoubleLinkedList<DataType>::OrderedDoubleLinkedList()
{
	list = DoubleLinkedList<DataType>();
}

// destructor
template <class DataType>
OrderedDoubleLinkedList<DataType>::~OrderedDoubleLinkedList(){}

template <class DataType>
void OrderedDoubleLinkedList<DataType>::insert(const DataType &newItem)
{
	if(list.empty())
	{
		std::cout<<"ADDING "<<newItem<<" TO the FRONT OF the LIST\n";
		list.push_front(newItem);
		return;
	}
	ListNode<DataType> *ptr = list.first();
	while(ptr != nullptr)
	{
		if(ptr->data() == newItem)
		{
			std::cout<<"ITEM ALREADY EXISTS IN LIST. UPDATING DATA.\n";
			ptr->data() = newItem;
			return;
		}
		if(ptr->data() > newItem)
		{
			std::cout<<"ORDERED INSERT DATA < NEW ITEM " << ptr->data()<<" "<<newItem<<"\n";
			if(ptr == list.first())
			{
				std::cout<<"ADDING "<<newItem<<" TO FRONT OF LIST\n";
				list.push_front(newItem);
				return;
			}
			std::cout<<"ADDING "<<newItem<<" TO LIST\n";
			list.insert_before(ptr,newItem);
			return;
		}
		ptr = ptr->next();
	}
	std::cout<<"ADDING "<<newItem<<" TO END OF LIST\n";
	list.push_back(newItem);
}
#endif /* ORDEREDDOUBLELINKEDLIST_H_ */
