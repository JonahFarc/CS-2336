// Homework 2 for CS 2336.002
// Programmer: Dylan Yu
// Description: Creates an ImperialLength class. This stores a number of inches and can convert it
// to feet and inches. It has the operators overloaded so that it can add and subtract from itself.

#ifndef IMPERIALLENGTH_H_
#define IMPERIALLENGTH_H_

#include <string>
#include <iostream>

class ImperialLength
{
	private:
		double totalInches;

	public:
		ImperialLength(int feet, double inches);
		ImperialLength(double totalInches);
		~ImperialLength();
		std::string to_string(int precision = 6) const;
		int getFeet() const;
		double getInches() const;
		double getTotalInches() const;
		//Overloads the += operator
		ImperialLength& operator+=(const ImperialLength &otherLength);
		//Overloads the + operator
		const ImperialLength operator+(const ImperialLength &otherLength) const;
		//Overloads the -= operator
		ImperialLength& operator-=(const ImperialLength &otherLength);
		//Overloads the - operator
		const ImperialLength operator-(const ImperialLength &otherLength) const;

};

//Overloads the << operator
std::ostream& operator<<(std::ostream &outputStream, const ImperialLength& length);

#endif /* IMPERIALLENGTH_H_ */
