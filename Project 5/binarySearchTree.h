// Project 5 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the BinarySearchTree and TreeNode classes. TreeNode holds a left and
// right link as well as some data. The BinarySearchTree takes these nodes and updates, finds,
// traverses, erases, and copies the nodes.

#ifndef PROJECT_5_BINARYSEARCHTREE_H_
#define PROJECT_5_BINARYSEARCHTREE_H_

#include <iomanip>
#include <iostream>

// forward declaration of the template class BinarySearchTree
template<class DataType>
class BinarySearchTree;

//TreeNode class
template<class DataType>
class TreeNode
{
	friend class BinarySearchTree<DataType>;
public:
	DataType info;
	TreeNode<DataType> *lLink;
	TreeNode<DataType> *rLink;
	//Default constructor
	TreeNode(){lLink = nullptr; rLink = nullptr;}
	//Constructor given a certain item. Sets info to the item
	TreeNode(DataType item){info = item; lLink = nullptr; rLink = nullptr;}
	//the update function will update the found item with the new item.
	template<typename type> friend void update(type &existingItem, const type &newItem);
	//outputs the data given
	template<typename type> friend void output(type x);
	//prints out the node in a given format
	template<typename type> friend void printNode(const TreeNode<type>* node, std::ostream &out);
};

//the update function will update the found item with the new item.
template <typename type>
void update(type &existingItem, const type &newItem)
{
	existingItem.update(newItem);
}

//outputs the data given
template <typename type>
void output(type x)
{
	std::cout<<x<<"\n";
}

//prints out the node in a given format
template <typename type>
void printNode(const TreeNode<type>* node, std::ostream &out)
{
	const unsigned int ADDRWIDTH = 10;
	out << "node " << "=" << std::setw(ADDRWIDTH) << node;
	out << ", left=" << std::setw(ADDRWIDTH)<< node->lLink;
	out << ", right=" << std::setw(ADDRWIDTH)<< node->rLink;
	out << ", value= " << node->info << std::endl;
}

//BinarySearchTree class
template<class DataType>
class BinarySearchTree
{
public:
	TreeNode<DataType> *root;
	int treesize;
	//Default Constructor
	BinarySearchTree(){root = nullptr; treesize = 0;}
	//Copy Constructor: makes a deep copy of the binary search tree
	BinarySearchTree(const BinarySearchTree<DataType>& other);
	//Destructor, deletes all the nodes from the tree
	~BinarySearchTree();
	//The empty member function will return true if the binary tree is empty.
	bool empty() const {return (treesize == 0);}
	//Returns the number of items in the binary tree.
	std::size_t size() const {return treesize;}
	//Display the contents of the binary tree in order by key (inorder traversal).
	void print() const{traverse(output);}
	//Display the contents of the binary tree for debugging purposes
	void debug(std::ostream &out) const;
	//If the item is found, the function is called, and the find member function will return true.
	//If the item is not found, the function is not called, and find returns false.
	bool find(const DataType &searchItem, void (*foundNode)(const DataType& item));
	//The erase member function will remove the specified item from the binary tree
	bool erase(const DataType &deleteItem);
	//Insert the item into the binary tree. If the entry already exists it should be replaced by the new one.
	void insert(const DataType &newItem);
	//Insert the item into the binary tree. If the item already exists the duplicateItemFound function will be called.
	void insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem));
	//The traverse function will do an inorder traversal of the binary tree.
	void traverse(void (*itemFound)(const DataType& foundItem)) const;

	//used for inorder traversal
	void inorder(TreeNode<DataType>* p, void (*visit) (const DataType& item)) const;
	//inorder transversal for output
	void inorder(TreeNode<DataType>* p, std::ostream &outstream, void (*visit) (const TreeNode<DataType>* node, std::ostream &out)) const;
	//deletes given node from tree
	void deleteFromTree(TreeNode<DataType>* &p);
	//deep copies a given node and all of its children
	void copyTree(TreeNode<DataType>* &copiedTreeRoot, TreeNode<DataType>* otherTreeRoot);
};

//Copy Constructor: makes a deep copy of the binary search tree
template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree(const BinarySearchTree<DataType>& other)
{
	//if the other tree is empty, leave this tree empty
	if(other.root == nullptr)
		root = nullptr;
	//otherwise call the copytree method from the root
	else
		copyTree(root, other.root);
}

//Destructor, deletes all the nodes from the tree
template <class DataType>
BinarySearchTree<DataType>::~BinarySearchTree()
{
	while(!empty())
		deleteFromTree(root);
}

//The traverse function will do an inorder traversal of the binary tree.
template <class DataType>
void BinarySearchTree<DataType>::traverse(void (*itemFound)(const DataType& foundItem)) const
{
	inorder(root, itemFound);
}

//used for inorder traversal
template <class DataType>
void BinarySearchTree<DataType>::inorder(TreeNode<DataType>* p, void (*visit) (const DataType& item)) const
{
	if (p!= nullptr)
	{
		inorder(p->lLink, *visit);
		(*visit)(p->info);
		inorder(p->rLink, *visit);
	}
}

//inorder traversal for output
template <class DataType>
void BinarySearchTree<DataType>::inorder(TreeNode<DataType>* p, std::ostream &outstream, void (*visit) (const TreeNode<DataType>* node, std::ostream &out)) const
{
	if (p!= nullptr)
	{
		inorder(p->lLink, outstream, *visit);
		(*visit)(p, outstream);
		inorder(p->rLink, outstream, *visit);
	}
}

//Display the contents of the binary tree for debugging purposes
template <class DataType>
void BinarySearchTree<DataType>::debug(std::ostream &out) const
{
	const unsigned int ADDRWIDTH = 10;
	out << "START DEBUG" << std::endl;
	out << "root =" << std::setw(ADDRWIDTH) << root;
	out << ", # nodes= " << size() << std::endl;

	inorder(root, out, printNode);
	out << "END DEBUG" << std::endl;
}

//Insert the item into the binary tree. If the entry already exists it should be replaced by the new one.
template <class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem)
{
	//if there is no root, make a Node out of newItem and set it as the root
	if(root == nullptr)
	{
		root = new TreeNode<DataType>(newItem);
		treesize++;
		return;
	}
	TreeNode<DataType> *p = root;
	//loop through the tree
	while(p!= nullptr)
	{
		//if newItem's value is greater than the current node, go right
		if(newItem > p->info)
		{
			//if the right link of the current node is empty, set it to a Node with newItem as the data
			if(p->rLink == nullptr)
			{
				p->rLink = new TreeNode<DataType>(newItem);
				treesize++;
				break;
			}
			//otherwise move to the right link and repeat
			p = p->rLink;
		}
		//if newItem's value is less than the current node, go left
		else if(newItem < p->info)
		{
			//if the left link of the current node is empty, set it to a Node with newItem as the data
			if(p->lLink == nullptr)
			{
				p->lLink = new TreeNode<DataType>(newItem);
				treesize++;
				break;
			}
			//otherwise move to the left link and repeat
			p = p->lLink;
		}
		//if newItem's value is equal to the current node, overwrite the node
		else if (newItem == p->info)
		{
			p->info = newItem;
			break;
		}
	}
}

//Insert the item into the binary tree. If the item already exists the duplicateItemFound function will be called.
template <class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem))
{
	//if there is no root, make a Node out of newItem and set it as the root
	if(root == nullptr)
	{
		root = new TreeNode<DataType>(newItem);
		treesize++;
		return;
	}
	TreeNode<DataType> *p = root;
	//loop through the tree
	while(p!= nullptr)
	{
		//if newItem's value is greater than the current node, go right
		if(newItem > p->info)
		{
			//if the right link of the current node is empty, set it to a Node with newItem as the data
			if(p->rLink == nullptr)
			{
				p->rLink = new TreeNode<DataType>(newItem);
				treesize++;
				break;
			}
			//otherwise move to the right link and repeat
			p = p->rLink;
		}
		//if newItem's value is less than the current node, go left
		else if(newItem < p->info)
		{
			//if the left link of the current node is empty, set it to a Node with newItem as the data
			if(p->lLink == nullptr)
			{
				p->lLink = new TreeNode<DataType>(newItem);
				treesize++;
				break;
			}
			//otherwise move to the left link and repeat
			p = p->lLink;
		}
		//if newItem's value is equal to the current node, call duplicateItemFound on the node
		else if (newItem == p->info)
		{
			(*duplicateItemFound)(p->info, newItem);
			break;
		}
	}
}

//If the item is found, the function is called, and the find member function will return true.
//If the item is not found, the function is not called, and find returns false.
template <class DataType>
bool BinarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType& item))
{
	TreeNode<DataType> *p = root;
	while(p != nullptr){
		//if the searchItem's value is greater than the current node, go right
		if(searchItem > p->info)
		{
			//if there is no right link, the item couldn't be find
			if(p->rLink == nullptr)
				return false;
			//move to the right link
			p = p->rLink;
		}
		//if the searchItem's value is less than the current node, go left
		else if (searchItem < p->info)
		{
			//if there is no left link, the item couldn't be found
			if(p->lLink == nullptr)
				return false;
			//move to the left link
			p = p->lLink;
		}
		//if the searchItem's value is equal to the given node, call the foundNode method
		else
		{
			(*foundNode)(p->info);
			return true;
		}
	}
	return false;
}

//The erase member function will remove the specified item from the binary tree
template <class DataType>
bool BinarySearchTree<DataType>::erase(const DataType &deleteItem)
{
	TreeNode<DataType> *current;
	bool found = false;

	//if the tree is empty, there's nothing to erase
	if(empty())
	{
		return false;
	}
	else
	{
		//start at the root
		current = root;

		//loop until reaching the end of the tree or finding the item,
		while(current != nullptr && !found)
		{
			//if the data at the current node is equal to the item, we have found it
			if(current->info == deleteItem)
				found = true;
			else
			{
				//if the current node is greater than the item, go to the left link
				if(current->info > deleteItem)
					current = current->lLink;
				//if the current node is less than the item, go to the right link
				else
					current = current->rLink;
			}
		}
		//if we reached the end of the tree, the item was not found
		if(current == nullptr)
		{
			return false;
		}
		else if (found)
		{
			//delete where current is pointing to
			if(current == root)
				deleteFromTree(root);
			else
				deleteFromTree(current);
			return true;
		}
		return false;
	}
}

//deletes given node from tree
template <class DataType>
void BinarySearchTree<DataType>::deleteFromTree(TreeNode<DataType>* &p)
{
	TreeNode<DataType> *current;
	TreeNode<DataType> *trailCurrent;
	TreeNode<DataType> *temp;

	if(p == nullptr);
	//if the left and right link of the node are empty
	else if(p->lLink == nullptr && p->rLink == nullptr)
	{
		//delete the node and decrement the size
		temp = p;
		p = nullptr;
		delete temp;
		treesize--;
	}
	//if only the left link is empty
	else if(p->lLink == nullptr)
	{
		//move the right link to the current position, delete the node
		//and decrement the tree size
		temp = p;
		p = p->rLink;
		delete temp;
		treesize--;
	}
	//if only the right link is empty
	else if(p->rLink == nullptr)
	{
		//move the left link to the current position, delete the node
		//and decrement the tree size
		temp = p;
		p = p->lLink;
		delete temp;
		treesize--;
	}
	//if no links are empty
	else
	{
		//go one link to the left
		current = p->lLink;
		trailCurrent = nullptr;
		//find the furthest right node possible
		while(current->rLink != nullptr)
		{
			trailCurrent = current;
			current = current->rLink;
		}
		//replace the data with the node found
		p->info = current->info;
		//if there was no right link initially, set the node's left link
		//to the left link of the node's left link
		if(trailCurrent == nullptr)
			p->lLink = current->lLink;
		//otherwise, set the node before the node found's right link
		//to the left link of the node founds
		else
			trailCurrent->rLink = current->lLink;
		//delete the node found
		delete current;
		//decrement the size of the tree
		treesize--;
	}
}

//deep copies a given node and all of its children
template <class DataType>
void BinarySearchTree<DataType>::copyTree(TreeNode<DataType>* &copiedTreeRoot, TreeNode<DataType>* otherTreeRoot)
{
	//if the other tree is empty, don't copy anything
	if(otherTreeRoot == nullptr)
		copiedTreeRoot = nullptr;
	//otherwise copy the current info, then copy the left and right link
	else
	{
		copiedTreeRoot = new TreeNode<DataType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
		copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
	}
}

#endif /* PROJECT_5_BINARYSEARCHTREE_H_ */
