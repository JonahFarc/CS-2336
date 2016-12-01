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

void lower(std::string x)
{
	std::transform(x.begin(), x.end(), x.begin(), ::tolower);
}
void sort(std::string x)
{
	std::sort(x.begin(), x.end());
}
bool inray(std::vector<std::string> v, std::string x)
{
	return (std::find(v.begin(), v.end(), x) != v.end());
}

class Word
{
public:
	std::string key;
	std::vector<std::string> values;
	Word(){key = ""; values = std::vector<std::string>();}
	Word(std::string value);
	std::string keygen(std::string word){lower(word); sort(word); return word;}
	bool operator<(const Word other) const {return key < other.key;}
	bool operator>(const Word other) const {return key > other.key;}
	bool operator==(const Word other)const{return key == other.key;}
	friend std::ostream& operator<<(std::ostream &out, const Word &outputWord);
	void update(const Word other);
};

Word::Word(std::string value)
{
	key = keygen(value);
	values = std::vector<std::string>();
	values.push_back(value);
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
