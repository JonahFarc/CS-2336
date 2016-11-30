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

using namespace std;

void lower(string x)
{
	std::transform(x.begin(), x.end(), x.begin(), ::tolower);
}
void sort(string x)
{
	std::sort(x.begin(), x.end());
}
bool inray(vector<string> v, string x)
{
	(std::find(v.begin(), v.end(), x) != v.end());
}

class Word
{
public:
	std::string key;
	vector<string> values;
	Word(){key = ""; values = vector<string>();}
	Word(string value);
	string keygen(string word){lower(word); sort(word);}
	bool operator<(const Word other){return key < other.key;}
	bool operator>(const Word other){return key > other.key;}
	bool operator==(const Word other){return key == other.key;}
	friend std::ostream& operator<<(std::ostream &out, const Word &outputWord);
	void update(const Word other);
};

Word::Word(string value)
{
	key = keygen(value);
	values = vector<string>();
	values.push_back(value);
}

void Word::update(const Word other)
{
	for(string val : other.values)
	{
		if(!inray(values, val))
			values.push_back(val);
	}
	std::sort(values.begin(),values.end());
}

std::ostream& operator<<(std::ostream &out, const Word &outputWord)
{
	for(string val : outputWord.values)
		out<< val<<" ";
}


#endif /* PROJECT_5_WORD_H_ */
