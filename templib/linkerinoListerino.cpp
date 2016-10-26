#include <string>
#include <iostream>
#include <fstream>
using namespace std;
template <class Type> Type larger(Type x, Type y);
template <class t1, class t2> bool compare(t1,t2);

/*struct Node
{
	string info;
	Node* next;
	Node(string thing) {
		info = thing;
		next = nullptr;
	}
	virtual ~Node() {
	}
};*/
template <class NodeType> class Node{
	NodeType info;
	Node* next;
	Node* back;
public:
	Node(NodeType stuff)
	{
		info = stuff;
		next = nullptr;
		back = nullptr;
	}
	void AGH()
	{
		cout<<(info);
	}
};
template <class NodeType> class linkedList{
	Node<NodeType> *first;
	Node<NodeType> *last;
	Node<NodeType> *current;
	int size = 0;
public:
	linkedList()
	{
		first = nullptr;
		last = nullptr;
		current = nullptr;
		size = 0;
	}
	void add(Node<NodeType> node)
	{
		if(first == nullptr)
		{
			first = &node;
			current = &node;
			last = &node;
			size = 1;
		}
		else
		{
			last->next = &node;
			last = &node;
			size++;
		}
	};
	void insert(Node<NodeType> node, int location=0)
	{
		if(location < size)
		{
			node->link = (first+location-1)->link;
			(first+location-1)->link = node;
		}
	};
	void remove(int location = 0)
	{
		if(location == 0)
		{
			Node<NodeType>* temp = first;
			first = first->next;
			delete temp;
		}
		else if(location < size-1)
		{
			Node<NodeType>* temp = (first+location-1)->link;
			(first+location-1)->link = temp->link;
			delete temp;
		}
	}
};

int main()
{
	int i = 5;
	Node<int> nod = Node<int>(i);
	nod.AGH();
	linkedList<int> list = linkedList<int>();
	string dogs[] = string[5];
	dogs[0] = "doggo";
	dogs[1] = "doggy";
	dogs[2] = "doggerino";
	dogs[3] = "doggerooni";
	dogs[4] = "dog";
}

template <class Type>
Type larger(Type x, Type y)
{
	if(x >= y)
		return x;
	return y;
}
template<class t1, class t2> bool compare(t1 one, t2 two)
{
	return one == two;

}
