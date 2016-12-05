// Project 5 for CS 2336.002
// Programmer: Dylan Yu
// Description: Defines some of the methods of the Word class. Allows the updating of values,
// the generation of keys, and the output format.

#include <algorithm>
#include <iostream>
#include "Word.h"

//Constructor given a value. Adds value to the values vector
Word::Word(std::string value)
{
	//values = std::vector<std::string>();
	values.push_back(value);
	key = keygen(value);
}

//generates the key to use for the hashing
std::string Word::keygen(std::string word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	std::sort(word.begin(), word.end());
	return word;
}

//Searches a vector for the specified value:
//returns true if found otherwise false
bool inray(std::vector<std::string> v, std::string x)
{
	return (std::find(v.begin(), v.end(), x) != v.end());
}

//adds new value to the values vector if not already in the vector
void Word::update(const Word other)
{
	for(std::string val : other.values)
	{
		if(!inray(values, val))
			values.push_back(val);
	}
	std::sort(values.begin(),values.end());
}

//outputs the Word in the format specified
std::ostream& operator<<(std::ostream &out, const Word &outputWord)
{
	out << "Key: " << outputWord.key << " | Values: ";
	for(std::string val : outputWord.values)
		out << val << " ";
	return out;
}
