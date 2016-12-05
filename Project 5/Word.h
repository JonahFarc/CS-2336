/*
 * Word.h
 *
 *  Created on: Nov 30, 2016
 *      Author: Korbo
 */

#ifndef PROJECT_5_WORD_H_
#define PROJECT_5_WORD_H_
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>

//Searches a vector for the specified value:
//returns true if found otherwise false
bool inray(std::vector<std::string> v, std::string x)
{
	return (std::find(v.begin(), v.end(), x) != v.end());
}

class Word
{
public:
	std::string key;
	std::vector<std::string> values;
	//Default Constructor
	Word(){key = ""; values = std::vector<std::string>();}
	//Constructor given a value. Adds value to the values vector
	Word(std::string value);
	//generates the key to use for the hashing
	std::string keygen(std::string word);
	//compares the Words by key, returns true if the key is less than the other key
	bool operator<(const Word other) const {return key < other.key;}
	//compares the Words by key, returns true if the key is greater than the other key
	bool operator>(const Word other) const {return key > other.key;}
	//compares the Words by key, returns true if the key is equal to the other key
	bool operator==(const Word other)const{return key == other.key;}
	//outputs the word in the format specified
	friend std::ostream& operator<<(std::ostream &out, const Word &outputWord);
	//adds new value to the values vector if not already in the vector
	void update(const Word other);
};

Word::Word(std::string value)
{
	values = std::vector<std::string>();
	values.push_back(value);
	key = keygen(value);
}

std::string Word::keygen(std::string word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	std::sort(word.begin(), word.end());
	return word;
}

void Word::update(const Word other)
{
	for(std::string val : other.values)
	{
		if(!inray(values, val))
			values.push_back(val);
	}
	std::sort(values.begin(),values.end());
}

std::ostream& operator<<(std::ostream &out, const Word &outputWord)
{
	out<<"Key: "<< outputWord.key << " | Values: ";
	for(std::string val : outputWord.values)
		out<< val << " ";
	return out;
}


#endif /* PROJECT_5_WORD_H_ */
