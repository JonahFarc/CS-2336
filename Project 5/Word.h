// Project 5 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates the Word class. The Word class stores a key and some values. The
// values are retrieved by key and the Word class is compared by key.

#ifndef PROJECT_5_WORD_H_
#define PROJECT_5_WORD_H_
#include <algorithm>
#include <vector>
#include <string>

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



#endif /* PROJECT_5_WORD_H_ */
