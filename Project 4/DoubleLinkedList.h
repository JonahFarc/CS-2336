// Project 4 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the DoubleLinkedList and ListNode classes. ListNode holds a previous and
// next element as well as some data. The DoubleLinkedList takes these list nodes and has methods
// to traverse the nodes and make a list with them.

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <iostream>
#include <iomanip>
#include <cstddef>

// forward declaration of the template class DoubleLinkedList
template<class DataType>
class DoubleLinkedList;

// ListNode class
template<class DataType>
class ListNode
{
	// make DoubleLinkedList<DataType> a friend class
	friend class DoubleLinkedList<DataType>;
	private:
		// contains the actual data
		DataType dataType;
		// pointer to the next item in the list or nullptr 
		// if at the end
		ListNode<DataType>* pNext;
		// pointer to the previous item in the list or nullptr 
		// if at the start
		ListNode<DataType>* pPrevious;
	public:
		// default constructor
		ListNode(){pNext = nullptr; pPrevious = nullptr; dataType = NULL;};
		// copy constructor
		ListNode(const DataType &newItem){pNext = nullptr; pPrevious = nullptr; dataType = newItem;};
		// get the next node
		ListNode* next() const {return pNext;};
		// get the previous node
		ListNode* previous() const {return pPrevious;};
		// return the data stored in the node as a const
		const DataType& data() const {return dataType;};
		// return the data stored in the node
		DataType& data(){return dataType;};
	private:
		// update the next node
		void next(ListNode *nextNode){pNext = nextNode;}
		// update the previous node
		void previous(ListNode *previousNode){pPrevious = previousNode;}
};

// DoubleLinkedList class
template<class DataType>
class DoubleLinkedList
{
	private:
		// number of nodes in the list. Note that std::size_t
		// is defined in header file cstddef.
		std::size_t numberNodes;
		// point to the first node or nullptr for empty list
		ListNode<DataType>* firstNode;
		// point to the last node or nullptr for empty list
		ListNode<DataType>* lastNode;
	public:
		// default constructor
		DoubleLinkedList(){firstNode = nullptr; lastNode = nullptr; numberNodes = 0;};
		// copy constructor
		DoubleLinkedList(const DoubleLinkedList &other);
		// destructor
		virtual ~DoubleLinkedList();
		// return the number of nodes in the list
		std::size_t size() const {return numberNodes;};
		// return true if the list is empty
		bool empty() const {return numberNodes == 0;};
		// display the contents of the list to std::cout
		void print() const;
		// dump the contends in debug format to passed in 
		// ostream - usage to cout would be:
		//   list.debug(std::cout);
		void debug(std::ostream &out) const;
		// first node in the list (or nullptr for empty)
		virtual ListNode<DataType>* first() const {return firstNode;};
		// last node in the list (or nullptr for empty)
		virtual ListNode<DataType>* last() const {return lastNode;};
		// add an item to the front of the list
		virtual void push_front(const DataType &newItem);
		// add an item to the back of the list
		virtual void push_back(const DataType &newItem);
		// remove an item from the front of the list
		virtual void pop_front();
		// remove an item from the back of the list
		virtual void pop_back();
		// insert newItem before the existingNode
		virtual void insert_before (ListNode<DataType>* existingNode, 
			 const DataType &newItem);
		// insert newItem after the existingNode
		virtual void insert_after (ListNode<DataType>* existingNode, 
			 const DataType &newItem);
		// find the node and return the address to the node. Return
		// nullptr if not found
		virtual ListNode<DataType>* find(const DataType &existingItem);
		// remove the node equal to currentItem
		virtual bool erase(const DataType &currentItem);
		// remove the node by address existingNode
		virtual bool erase(ListNode<DataType> *existingNode);
};

//Copy constructor, makes a deep copy of the list
template<class DataType>
DoubleLinkedList<DataType>::DoubleLinkedList(const DoubleLinkedList &other)
{
	//instantiating variables for the empty list
	firstNode = nullptr;
	lastNode = nullptr;
	numberNodes = 0;

	//setting the pointer to start at the beginning of the other list
	ListNode<DataType> *ptr = other.firstNode;

	//loop until the end of the list has been reached
	while(ptr != nullptr)
	{
		//pushing the data from the current element into the list
		push_back(ptr->data());
		//advancing the pointer
		ptr = ptr->pNext;
	}
}
//destructor
template<class DataType>
DoubleLinkedList<DataType>::~DoubleLinkedList()
{
	//Sets number of loops to the size of the list
	int i = numberNodes;

	//Loops until the list is empty
	while(i --> 0)
	{
		//destroys the first element of the list
		pop_front();
	}
}

// display the contents of the list to std::cout
template<class DataType>
void DoubleLinkedList<DataType>::print() const
{
	//Sets the current value to the beginning of the list
	ListNode<DataType>* ptr = firstNode;

	//loops until the end of the list
	while(ptr != nullptr)
	{
		//outputs each node's data
		std::cout<<ptr->dataType<<"\n";
		//moves on to the next pointer
		ptr = ptr->pNext;
	}
}

// add an item to the front of the list
template<class DataType>
void DoubleLinkedList<DataType>::push_front(const DataType &newItem)
{
	//creates a node type of the item given
	ListNode<DataType> *newNode = new ListNode<DataType>(newItem);

	//if the list is empty, then set the beginning and end of the list
	//to the only item in the list
	if(empty())
	{
		firstNode = newNode;
		lastNode = newNode;
	}
	//if the list is not empty, point the new node's next to the first node in the list
	//point the first node's previous to the new node,
	//and set the new node as the first node in the list
	else
	{

		newNode->pNext = firstNode;
		newNode->pPrevious = nullptr;
		firstNode->pPrevious = newNode;
		firstNode = newNode;
	}
	//increment the number of nodes
	numberNodes++;
}

// add an item to the back of the list
template<class DataType>
void DoubleLinkedList<DataType>::push_back(const DataType &newItem)
{
	//creates a node type of the item given
	ListNode<DataType> *newNode = new ListNode<DataType>(newItem);

	//if the list is empty, then set the beginning and end of the list
	//to the only item in the list
	if(empty())
	{
		firstNode = newNode;
		lastNode = newNode;
	}
	//if the list is not empty, point the new node's previous to the last node in the list
	//point the last node's next to the new node,
	//and set the new node as the last node in the list
	else
	{
		newNode->pPrevious = lastNode;
		newNode->pNext = nullptr;
		lastNode->pNext = newNode;
		lastNode = newNode;
	}
	//increment the number of nodes
	numberNodes++;
}

// remove an item from the front of the list
template<class DataType>
void DoubleLinkedList<DataType>::pop_front()
{
	//ensures the list is not removing from an empty list
	if(!empty())
	{
		//sets the pointer to the first node in the list
		ListNode<DataType> *ptr = firstNode;
		//sets the first node to the second node
		firstNode = firstNode->pNext;
		//IF there is more than one item in the list, remove
		//the connection between the second node and the first node
		//IF there is only one item in the list, set the last node to null
		//since the list is now empty
		if(firstNode != nullptr)
			firstNode->pPrevious = nullptr;
		else
			lastNode = nullptr;
		//decrement the number of nodes
		numberNodes--;
		//delete the first node of the list
		delete ptr;
	}
}

// remove an item from the back of the list
template<class DataType>
void DoubleLinkedList<DataType>::pop_back()
{
	//ensures the list is not removing from an empty list
	if(!empty())
	{
		//sets the pointer to the last node in the list
		ListNode<DataType> *ptr = lastNode;
		//sets the last node to the second to last node
		lastNode = lastNode->pPrevious;
		//IF there is more than one item in the list, remove
		//the connection between the second to last node and the last node
		//IF there is only one item in the list, set the first node to null
		//since the list is now empty
		if(lastNode != nullptr)
			lastNode->pNext= nullptr;
		else
			firstNode = nullptr;
		//decrement the number of nodes
		numberNodes--;
		//remove the last item of the list
		delete ptr;
	}
}

// insert newItem before the existingNode
template<class DataType>
void DoubleLinkedList<DataType>::insert_before (ListNode<DataType>* existingNode, const DataType &newItem)
{
	//if the existing node is the first node, use the push_front method already written
	if(existingNode == firstNode){
		push_front(newItem);
		return;
	}
	//checks to see if the existing node is in the list.
	if(find(existingNode->data()) != nullptr)
	{
		//creates a node using the data given
		ListNode<DataType> *newNode = new ListNode<DataType>(newItem);

		//adds the node into the list before the existing node
		newNode->pPrevious = existingNode->pPrevious;
		newNode->pNext = existingNode;
		existingNode->pPrevious->pNext = newNode;
		existingNode->pPrevious = newNode;

		//increment the number of nodes
		numberNodes++;
	}
}

// insert newItem after the existingNode
template<class DataType>
void DoubleLinkedList<DataType>::insert_after (ListNode<DataType>* existingNode, const DataType &newItem)
{
	//if the existing node is the first node, use the push_front method already written
	if(existingNode == lastNode){
		push_back(newItem);
		return;
	}
	//if(existingNode != nullptr)
	//checks to see if the existing node is in the list
	if(find(existingNode->data()) != nullptr)
	{
		//creates a node using the data given
		ListNode<DataType> *newNode = new ListNode<DataType>(newItem);

		//adds the node into the list before the existing node
		newNode->pNext = existingNode->pNext;
		newNode->pPrevious = existingNode;
		existingNode->pNext= newNode;

		//increment the number of nodes
		numberNodes++;
	}
}

// find the node and return the address to the node. Return
// nullptr if not found
template<class DataType>
ListNode<DataType>* DoubleLinkedList<DataType>::find(const DataType &existingItem)
{
	//set the pointer to the first node
	ListNode<DataType> *ptr = firstNode;

	//loop until pointer has gone through the whole list
	while(ptr != nullptr)
	{
		//if the provided data has been found, return the address
		if(ptr->dataType == existingItem)
			return ptr;

		//move the pointer to the next item in the list
		ptr = ptr->pNext;
	}
	//if the item hasn't been found, it isn't in the list.
	return nullptr;
}

// remove the node equal to currentItem
template<class DataType>
bool DoubleLinkedList<DataType>::erase(const DataType &currentItem)
{
	//set the pointer to the first node
	ListNode<DataType> *ptr = firstNode;

	//loop through the list
	while(ptr != nullptr)
	{
		//checks to see if the item in the list is equal to the search item
		if(ptr->dataType == currentItem)
		{
			//if the item is the first node in the list, then use the
			//pop_front method already written
			if(ptr == firstNode)
			{
				pop_front();
				return true;
			}
			//if the item is the last node in the list, then use the
			//pop_back method already written
			if(ptr == lastNode)
			{
				pop_back();
				return true;
			}
			//delete the item from the list
			ptr->pPrevious->pNext = ptr->pNext;
			ptr->pNext->pPrevious = ptr->pPrevious;
			delete ptr;

			//decrement the number of pointers
			numberNodes--;
			return true;
		}

		//move the pointer to the next item in the list
		ptr = ptr->pNext;
	}

	//the item is not in the list, nothing to erase
	return false;
}

// remove the node by address existingNode
template<class DataType>
bool DoubleLinkedList<DataType>::erase(ListNode<DataType> *existingNode)
{
	//set the pointer to the first node
	ListNode<DataType> *ptr = firstNode;

	//loop through the list
	while(ptr != nullptr)
	{
		//checks to see if the item in the list is equal to the search item
		if(ptr == existingNode)
		{
			//if the item is the first node in the list, then use the
			//pop_front method already written
			if(ptr == firstNode)
			{
				pop_front();
				return true;
			}
			//if the item is the last node in the list, then use the
			//pop_back method already written
			if(ptr == lastNode)
			{
				pop_back();
				return true;
			}
			//delete the item from the list
			ptr->pPrevious->pNext = ptr->pNext;
			ptr->pNext->pPrevious = ptr->pPrevious;
			delete ptr;

			//decrement the number of pointers
			numberNodes--;
			return true;
		}

		//move the pointer to the next item in the list
		ptr = ptr->pNext;
	}

	//the item is not in the list, nothing to erase
	return false;
}

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void DoubleLinkedList<DataType>::debug(std::ostream &out) const
{
	const unsigned int ADDRWIDTH = 10;
	out << "START DEBUG" << std::endl;
	out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
	out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
	out << ", # nodes=" << size() << std::endl;
	unsigned int count = 1;

	for (auto current=firstNode; current!= nullptr; current=current->next())
	{
		out << "node " << std::setw(2) << count;
		out << "=" << std::setw(ADDRWIDTH) << current;
		out << ", next=" << std::setw(ADDRWIDTH) 
			<< current->next();
		out << ", previous=" << std::setw(ADDRWIDTH) 
			<< current->previous();
		out << ", value=" << current->data() << std::endl;
		count++;
	}
	out << "END DEBUG" << std::endl;
}

#endif /* DOUBLELINKEDLIST_H_ */
