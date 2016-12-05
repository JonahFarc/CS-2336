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
	std::ofstream debug("debug_output.txt");
	std::string in;
	while(input>>in)
	{
		dictionary.insert(Word(in), update);
	}
	if(!input.eof())
	{
		std::cout<<"Error occurred while reading file.\n";
		return 1;
	}
	else
		std::cout<<"Successfully added all items.\n";
	dictionary.debug(debug);
	while(true)
	{
		std::cout<<"Input a scrambled word: ";
		std::cin>>in;
		if(!std::cin.good())
		{
			std::cout<<"Invalid Input\n";
			continue;
		}
		if(in == "adumbz")
			return 0;
		if(!dictionary.find(Word(in), output))
			std::cout<<"Word not found!\n";
		std::cout<<"\n";
	}\
}
