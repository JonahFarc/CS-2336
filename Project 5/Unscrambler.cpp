// Project 5 for CS 2336.002
// Programmer: Dylan Yu
// Description: Uses the BinarySearchTree and Word class to unscrambled words given to it. It takes in
// words from a text file and adds them to the binary search tree. They are stored as Words. Then, the
// user inputs a value and the program hashes it to get the values from the binary search tree.

#include <iostream>
#include <string>
#include <fstream>

#include "BinarySearchTree.h"
#include "Word.h"

int main()
{
	//creates binary search tree
	BinarySearchTree<Word> dictionary = BinarySearchTree<Word>();

	//opens files to read and write into
	std::ifstream input("english_words.txt");
	std::ofstream debug("debug_output.txt");
	std::string in;

	//reads in all the words in the dictionary provided
	while(input>>in)
	{
		//multi value version
		dictionary.insert(Word(in), update);
		//single value version
		//dictionary.insert(Word(in));
	}

	//if the file fails to be read for any reason, the program will end
	if(!input.eof())
	{
		std::cout<<"Error occurred while reading file.\n";
		return 1;
	}
	else
		std::cout<<"Successfully added all items.\n";

	//writes a debug log to the file provided
	dictionary.debug(debug);

	//loops until kill code is given
	while(true)
	{
		//get input
		std::cout<<"Input a scrambled word (Input 'adumbz' to end the program): ";
		std::cin>>in;

		//kill code
		if(in == "adumbz")
			return 0;

		//if word is found, output it
		//otherwise, print "Word not found"
		if(!dictionary.find(Word(in), output))
			std::cout<<"Word not found!\n";
		std::cout<<"\n";
	}
}
