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
public:
	Node(NodeType stuff)
	{
		info = stuff;
		next = nullptr;
	}
	void AGH(NodeType other)
	{
		cout<<(info+other);
	}
};
template <class NodeType> class linkedList{
	Node *first;
	Node *last;
	Node *current;
};
int main()
{
	int i = 5;
	int* p = &i;
	Node<int> nod = Node<int>(i);
	nod.AGH(8);
	Node<int*> nood = Node<int*>(p);
	nood.AGH(p);
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
