/*
 * binarySearchTree.h
 *
 *  Created on: Nov 16, 2016
 *      Author: Korbo
 */

#ifndef PROJECT_5_BINARYSEARCHTREE_H_
#define PROJECT_5_BINARYSEARCHTREE_H_

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
	TreeNode(){lLink = nullptr; rLink = nullptr;}
	TreeNode(DataType item){info = item; lLink = nullptr; rLink = nullptr;}
};

//BinarySearchTree class
template<class DataType>
class BinarySearchTree
{
public:
	TreeNode<DataType> *root;
	int treesize;
	BinarySearchTree(){root = nullptr; treesize = 0;}
	BinarySearchTree(const BinarySearchTree<DataType>& other);
	~BinarySearchTree();
	//The empty member function will return true if the binary tree is empty.
	bool empty() const {return (treesize == 0);}
	//Returns the number of items in the binary tree.
	std::size_t size() const {return treesize;}
	//Display the contents of the binary tree in order by key (inorder traversal).
	void print() const{traverse(out);}
	//Display the contents of the binary tree for debugging purposes
	void debug(std::ostream &out) const;
	// If the item is found, the function is called, and the find member function will return true.
	//If the item is not found, the function is not called, and find returns false.
	bool find(const DataType &searchItem, void (*foundNode)(const DataType&));
	//The erase member function will remove the specified item from the binary tree
	bool erase(const DataType &deleteItem);
	//Insert the item into the binary tree. If the entry already exists it should be replaced by the new one.
	void insert(const DataType &newItem);
	//Insert the item into the binary tree. If the item already exists the duplicateItemFound function will be called.
	void insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem));
	//the update function will update the found item with the new item.
	void update(DataType &existingItem, const DataType &newItem);
	//The traverse function will do an inorder traversal of the binary tree.
	void traverse(void (*itemFound)(const DataType& foundItem)) const;

	//used for inorder traversal
	void inorder(TreeNode<DataType>* p, void (*visit) (DataType& item));
	//deletes given node from tree
	void deleteFromTree(TreeNode<DataType>* &p);
	void out(DataType x){std::cout<<x;}

};

template <class DataType>
void BinarySearchTree<DataType>::traverse(void (*itemFound)(const DataType& foundItem)) const
{
	inorder(root, *itemFound);
}

template <class DataType>
void BinarySearchTree<DataType>::inorder(TreeNode<DataType>* p, void (*visit) (DataType& item))
{
	if (p!= nullptr)
	{
		inorder(p->lLink, *visit);
		(*visit)(p->info);
		inorder(p->rLink, *visit);
	}
}
template <class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem)
{
	TreeNode<DataType> *p = root;
	while(p!= nullptr)
	{
		if(newItem > p->info)
		{
			if(p->rLink == nullptr)
			{
				p->rLink = new TreeNode<DataType>(newItem);
				break;
			}
			p = p->rLink;
		}
		else if(newItem < p->info)
		{
			if(p->lLink == nullptr)
			{
				p->lLink = new TreeNode<DataType>(newItem);
				break;
			}
			p = p->lLink;
		}
		else if (newItem == p->info)
		{
			p->info = newItem;
			break;
		}
	}
}

template <class DataType>
void BinarySearchTree<DataType>::insert(const DataType &newItem, void (*duplicateItemFound)(DataType &existingItem, const DataType &newItem))
{
	TreeNode<DataType> *p = root;
	while(p!= nullptr)
	{
		if(newItem > p->info)
		{
			if(p->rLink == nullptr)
			{
				p->rLink = new TreeNode<DataType>(newItem);
				break;
			}
			p = p->rLink;
		}
		else if(newItem < p->info)
		{
			if(p->lLink == nullptr)
			{
				p->lLink = new TreeNode<DataType>(newItem);
				break;
			}
			p = p->lLink;
		}
		else if (newItem == p->info)
		{
			(*duplicateItemFound)(p->info, newItem);
			break;
		}
	}
}

template <class DataType>
void update(DataType &existingItem, const DataType &newItem)
{
	//existingItem.update(newItem);
	existingItem = newItem;
}

template <class DataType>
bool BinarySearchTree<DataType>::find(const DataType &searchItem, void (*foundNode)(const DataType& item))
{
	TreeNode<DataType> *p = root;
	while(p != nullptr){
		if(searchItem > p->info)
		{
			if(p->rLink == nullptr)
				return false;
			p = p->rLink;
		}
		else if (searchItem < p->info)
		{
			if(p->lLink == nullptr)
				return false;
			p = p->lLink;
		}
		else
		{
			(*foundNode)(p -> info);
			return true;
		}
	}
}
template <class DataType>
bool BinarySearchTree<DataType>::erase(const DataType &deleteItem)
{
	TreeNode<DataType> *current;
	TreeNode<DataType> *trailCurrent;
	bool found = false;

	if(empty())
	{
		std::cout<<"literally autistic";
	}
	else
	{
		current = root;
		trailCurrent = root;
		while(current != nullptr && !found)
		{
			if(current->info == deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				if(current->info > deleteItem)
					current = current->lLink;
				else
					current = current->rLink;
			}
		}
		if(current == nullptr)
		{
			std::cout<<"item not in tree";
		}
		else if (found)
		{
			if(current == root)
				deleteFromTree(root);
			else if(trailCurrent -> info > deleteItem)
				deleteFromTree(trailCurrent->lLink);
			else
				deleteFromTree(trailCurrent->rLink);
		}
		else
			std::cout<<"not in tree";

	}
}

template <class DataType>
void BinarySearchTree<DataType>::deleteFromTree(TreeNode<DataType>* &p)
{
	TreeNode<DataType> *current;
	TreeNode<DataType> *trailCurrent;
	TreeNode<DataType> *temp;

	if(p == nullptr)
		std::cout<<"NO NODE TO DELETE";
	else if(p->lLink == nullptr && p->rLink == nullptr)
	{
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if(p->lLink == nullptr)
	{
		temp = p;
		p = p->rLink;
		delete temp;
	}
	else if(p->rLink == nullptr)
	{
		temp = p;
		p = p->lLink;
		delete temp;
	}
	else
	{
		current = p->lLink;
		trailCurrent = nullptr;
		while(current->rLink != nullptr)
		{
			trailCurrent = current;
			current = current->rLink;
		}
		p->info = current->info;
		if(trailCurrent == nullptr)
			p->lLink = current->lLink;
		else
			trailCurrent->rLink = current->lLink;

		delete current;
	}
}


#endif /* PROJECT_5_BINARYSEARCHTREE_H_ */
