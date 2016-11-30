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
	DataType info;
	TreeNode<DataType> *lLink;
	TreeNode<DataType> *rLink;
};

//BinarySearchTree class
template<class DataType>
class BinarySearchTree
{
protected:
	TreeNode<DataType> *root;
public:
	BinarySearchTree();
	BinarySearchTree(other);
	~BinarySearchTree();
	//The empty member function will return true if the binary tree is empty.
	bool empty() const
	//Returns the number of items in the binary tree.
	std::size_t size() const
	//Display the contents of the binary tree in order by key (inorder traversal).
	void print() const;
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
	void update(DataType &exsitingItem, const DataType &newItem);
	//The traverse function will do an inorder traversal of the binary tree.
	void traverse(void (*itemFound)(const DataType& foundItem)) const;


};


#endif /* PROJECT_5_BINARYSEARCHTREE_H_ */
