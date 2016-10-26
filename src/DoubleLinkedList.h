/*
 * BaseDoubleLinkedList.h
 *
 * Implementation of a double linked list.
 *
 * We have the ability to get the first and last entries and navigate
 * through the entries in the linked list.
 *
 * There are actually two classes here:
 *
 * ListNode<DataType>
 *
 * and
 *
 * DoubleLinkedList<DataType>
 *
 */

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
		ListNode(const DataType &newItem){dataType = newItem;};
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
		DoubleLinkedList(const DoubleLinkedList &other)
		{
			numberNodes = other.numberNodes;
			firstNode = other.firstNode;
			lastNode = other.lastNode;
		};
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

// your implementation code goes here

		// display the contents of the list to std::cout
		template<class DataType>
		void DoubleLinkedList<DataType>::print() const
		{
			ListNode<DataType>* ptr = firstNode;
			while(ptr != nullptr)
			{
				std::cout << ptr->dataType << "\n";
				ptr = ptr->pNext;
			}
		}

		// add an item to the front of the list
		template<class DataType>
		void DoubleLinkedList<DataType>::push_front(const DataType &newItem)
		{
			/*
			ListNode<DataType> newNode = ListNode<DataType>(newItem);
			if(numberNodes==0)
			{
				firstNode = &newNode;
				lastNode = &newNode;
			}
			else
			{
				newNode.pNext = firstNode;
				newNode.pPrevious = firstNode->pPrevious;
				firstNode->pPrevious = &newNode;
				firstNode = &newNode;
			}
			*/
			ListNode<DataType> *newNode;
			newNode->dataType = newItem;
			firstNode->pPrevious = newNode;
			newNode ->pNext = firstNode;
			newNode->pPrevious=nullptr;
			firstNode = newNode;
			numberNodes++;
		}
		// add an item to the back of the list
		template<class DataType>
		void DoubleLinkedList<DataType>::push_back(const DataType &newItem)
		{
			ListNode<DataType> newNode = ListNode<DataType>(newItem);
			if(numberNodes==0)
			{
				firstNode = &newNode;
				lastNode = &newNode;
			}
			else
			{
				newNode.pPrevious = lastNode;
				newNode.pNext = lastNode->pNext;
				lastNode->pNext = &newNode;
				lastNode = &newNode;
			}
			numberNodes++;
		}
		// remove an item from the front of the list
		template<class DataType>
		void DoubleLinkedList<DataType>::pop_front()
		{
			firstNode = firstNode->pNext;
			firstNode->pPrevious = nullptr;
		}
		// remove an item from the back of the list
		template<class DataType>
		void DoubleLinkedList<DataType>::pop_back()
		{
			if(numberNodes != 0)
			{
				if(numberNodes == 1)
				{

				}
				else
				{
				lastNode = lastNode->pPrevious;
				lastNode->pNext = nullptr;
				}
			}
		}
		// insert newItem before the existingNode
		template<class DataType>
		void DoubleLinkedList<DataType>::insert_before (ListNode<DataType>* existingNode, const DataType &newItem)
		{
			ListNode<DataType> newNode = ListNode<DataType>(newItem);
			newNode.pPrevious = existingNode->pPrevious;
			newNode.pNext = existingNode;
			existingNode->pPrevious = &newNode;
		}
		// insert newItem after the existingNode
		template<class DataType>
		void DoubleLinkedList<DataType>::insert_after (ListNode<DataType>* existingNode, const DataType &newItem)
		{
			ListNode<DataType> newNode = ListNode<DataType>(newItem);
			newNode.pNext = existingNode->pNext;
			newNode.pPrevious = existingNode;
			existingNode->pNext= &newNode;
		}
		// find the node and return the address to the node. Return
		// nullptr if not found
		template<class DataType>
		ListNode<DataType>* DoubleLinkedList<DataType>::find(const DataType &existingItem)
		{
			ListNode<DataType> *ptr = firstNode;
			while(ptr != nullptr)
			{
				if(ptr->dataType == existingItem)
					return ptr;
				ptr = ptr->pNext;
			}
			return nullptr;
		}
		// remove the node equal to currentItem
		template<class DataType>
		bool DoubleLinkedList<DataType>::erase(const DataType &currentItem)
		{
			ListNode<DataType> *ptr = firstNode;
			while(ptr != nullptr)
			{
				if(ptr->dataType == currentItem)
					return ptr;
				ptr = ptr->pNext;
			}
			return nullptr;
		}
		// remove the node by address existingNode
		template<class DataType>
		bool DoubleLinkedList<DataType>::erase(ListNode<DataType> *existingNode);

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
