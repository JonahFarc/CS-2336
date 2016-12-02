/*
 * Unscrambler.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: M3800
 */

#include <iostream>
#include <string>
#include <fstream>

#include "BinarySearchTree.h"
#include "Word.h"

int main()
{
	BinarySearchTree<Word> dictionary = BinarySearchTree<Word>();
	std::ifstream input("english_words.txt");
	std::ofstream debug("WHYDOYOUSUCK.txt");
	std::string in;
	std::string x;
	while(input>>in)
	{
		dictionary.insert(Word(in), update);
		if(!input.good())
			std::cout<<in;
	}
	if(!input.eof())
		std::cout<<"Error occurred while reading file.\n";
	else
		std::cout<<"Successfully added all items.\n";
	dictionary.print();
	dictionary.debug(debug);
	while(true)
	{
		std::cout<<"Input a scrambled word: ";
		std::cin>>in;
		std::cout<<"\n";
		if(!std::cin.good())
		{
			std::cout<<"Invalid Input\n";
			continue;
		}
		if(in == "adumbz")
			return 0;
		if(!dictionary.find(Word(in), output))
			std::cout<<"Word not found!\n";
	}

}
