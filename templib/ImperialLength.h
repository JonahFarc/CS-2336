/*
 * ImperialLength.h
 *
 * This class implements imperial measurements (inches and feet).
 *
 * Currently the class allows you to create an imperial length object using
 *  either feet and inches, or total inches.
 *
 *  You will be adding support for the operators +, =+, -, and =-
 *
 *  You will also be adding support for the << operator.
 *
 *      Author: dgv130030
 */

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
		// you need to implement these
		ImperialLength& operator+=(const ImperialLength &otherLength);
		const ImperialLength operator+(const ImperialLength &otherLength) const;
		// you need to add prototypes for operators -= and -. 
		ImperialLength& operator-=(const ImperialLength &otherLength);
		const ImperialLength operator-(const ImperialLength &otherLength) const;

};

// you need to impement this overloaded operator<< function. It is a global function
// (not part of a class)
std::ostream& operator<<(std::ostream &outputStream, const ImperialLength& length);

#endif /* IMPERIALLENGTH_H_ */
