/*
 * Unscrambler.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: M3800
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Word.h"
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<Word> dictionary = BinarySearchTree<Word>();
	std::ifstream input("english_words.txt");
	std::string in;
	while(input.good())
	{
		input>>in;
		dictionary.insert(Word(in), update);
	}
	if(!input.eof())
		std::cout<<"Error occurred while reading file.\n";
	else
		std::cout<<"Successfully added all items\n";
	while(true)
	{
		std::cout<<"Input a scrambled word: ";
		input>>in;
		std::cout<<"\n";
		if(!input.good())
		{
			std::cout<<"Invalid Input";
			return 1;
		}
		if(input == "adumbz")
			return 0;
		if(dictionary.find(Word(in), output))
		{

		}
	}

}
