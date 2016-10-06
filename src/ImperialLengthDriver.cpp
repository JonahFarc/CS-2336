/*
 * ImperialLengthDriver.cpp
 *
 *      Author: dgv130030
 */

#include <iostream>
#include <iomanip>

#include "ImperialLength.h"

using namespace std;

int main()
{
	ImperialLength length1(146.0), length2(2,5.25);

	cout << "length1 (default precision)" << endl;
	cout << length1 << endl;
	cout << endl << "length2 (precision of 3)" << endl;
	cout << fixed << setprecision(3) << length2 << endl;
	cout << endl << "length1 + length2 (precision of 2)" << endl;
	cout << fixed << setprecision(2) << (length1+length2) << endl;
	cout << endl << "length1 - length2 (precision of 2)" << endl;
	cout << fixed << setprecision(2) << (length1-length2) << endl;
	cout << endl << "length1 - length2 (precision of 3) as inches" << endl;
	ImperialLength length3 = length1 - length2;
	cout << fixed << setprecision(3) << length3.getTotalInches() << "\"" << endl;
	cout << endl << "length4 (precision of 3)" << endl;

	ImperialLength length4(6.7);
	cout << length4 << endl;

	ImperialLength length5(204.3), length6(4, 2.6);
	length5 += length4;

	cout << setprecision(2);
	cout << endl << "length5 (precision of 2)" << endl;
	cout << length5 << endl;

	cout << endl << "length6 (precision of 2)" << endl;
	length6 -= length4;
	cout << length6 << endl;

	return 0;
}
