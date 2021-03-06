// Project 4 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the Queue class. The Queue stores a DoubleLinkedList with access only to
// the adding to the end, and removing from the front. It has access to the
// front and back of the list

#ifndef QUEUE_H_
#define QUEUE_H_

#include "DoubleLinkedList.h"

template<class DataType>
class Queue
{
	DoubleLinkedList<DataType> list;
public:
	//Default Constructor
	Queue() {list = DoubleLinkedList<DataType>();}
	//Copy Constructor
	Queue(const Queue &copy);
	//Destructor
	~Queue() {list.~DoubleLinkedList();}
	//The empty member function will return true if the queue is empty.
	bool empty() const {return list.empty();}
	//Returns the number of items in the queue.
	std::size_t size() const {return list.size();}
	//Returns a modifiable reference to the first item in the queue. Note, your member function can assume the queue has at least one item or you can throw an exception, the choice is yours.
	DataType& front() {return list.first()->data();}
	//Returns a const reference to the first item in the queue. Note, your member function can assume the queue has at least one item or you can throw an exception, the choice is yours.
	const DataType& front() const {return list.first()->data();}
	//Returns a modifiable reference to the last item in the queue. Note, your member function can assume the queue has at least one item or you can throw an exception, the choice is yours.
	DataType& back() {return list.last()->data();}
	//Returns a const reference to the last item in the queue. Note, your member function can assume the queue has at least one item or you can throw an exception, the choice is yours.
	const DataType& back() const {return list.last()->data();}
	//Add a new item to the back of the queue.
	void push(const DataType& value) {list.push_back(value);}
	//Remove the first item from the queue.
	void pop() {list.pop_front();}
	void debug(std::ostream &out) const
	{
		list.debug(out);
	}
};

template <class DataType>
Queue<DataType>::Queue(const Queue &copy)
{
	list = DoubleLinkedList<DataType>();
	ListNode<DataType> *ptr = copy.list.first();

	//loop until the end of the list has been reached
	while(ptr != nullptr)
	{
		//pushing the data from the current element into the list
		list.push_back(ptr->data());
		//advancing the pointer
		ptr = ptr->next();
	}
}


#endif /* QUEUE_H_ */
