/*
 * source.cpp
 *
 *  Created on: Aug 23, 2016
 *      Author: Dylan
 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//instantiate variables
	double number,numbers;
	char operate;
	double answer;
	bool output = true;
	//input numbers and operation
	cin >> number >> numbers >> operate;
	//set output to two decimal places
	cout << fixed << setprecision(2);
	//calculate based on operation
	switch(operate)
	{
		case '+': answer = number+numbers;break;
		case '-': answer = number-numbers;break;
		case '*': answer = number*numbers;break;
		case '/': if(numbers==0){cout<<"Division by zero is not valid"<<endl;output = false;break;}answer=number/numbers;break;
		default: cout<<"NOT A VALID OPERATOR"<<endl;output = false;
	}
	//print out answer if operation is valid
	if(output)
		cout<<number << " " << operate << " " << numbers << " = " << answer<<endl;
	return 0;
}



