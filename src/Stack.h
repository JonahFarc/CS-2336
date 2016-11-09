// Project 4 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the Stack class. The Stack stores a DoubleLinkedList with access only to
// the first item of the list. It adds to and removes from the front of the list


#ifndef STACK_H_
#define STACK_H_

#include "DoubleLinkedList.h"

template<class DataType>
class Stack
{
	DoubleLinkedList<DataType> list;
public:
	//Default constructor
	Stack(){list = DoubleLinkedList<DataType>();}
	//Copy Constructor
	Stack(const Stack &other){list = DoubleLinkedList<DataType>(other.list);}
	//Destructor
	~Stack(){list.~DoubleLinkedList();}
	//The empty member function will return true if the stack is empty.
	bool empty() const {return list.empty();}
	//Returns the number of items in the stack.
	std::size_t size() const {return list.size();}
	//Returns a modifiable reference to the top item in the stack. Note, your member function can assume the stack has at least one item or you can throw an exception, the choice is yours.
	DataType& top() {return &(list.first().dataType());}
	//Returns a const reference to the top item in the stack. Note, your member function can assume the stack has at least one item or you can throw an exception, the choice is yours.
	const DataType& top() const {return &(list.first().dataType());}
	//Add a new item to the stack.
	void push(const DataType& value) {list.push_front(value);}
	//Remove the top item from the stack.
	void pop() {list.pop_front();}
};



#endif /* STACK_H_ */
