/*
 * assignment1.cpp
 *
 * Created on: Sept 7, 2016
 * Author: Dylan Yu
 *
 * This program serves as a calculator with the 4 basic functions
 * as well as having square roots, exponents, and memory. It reads
 * its input from a file and does the calculations accordingly.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;
double add(double &a, double b);
double subtract(double &a, double b);
int main()
{
	//create variables
	ifstream inFile;
	double memory = 0;
	double accumulator = 0;
	double num;
	string operation;

	//open file
	inFile.open("input.txt");

	//output an error and end the program if the file cannot be found/opened
	if(!inFile)
		cout << "Error: File cannot be opened.\n";
	assert(inFile);

	//set output to return 5 decimal places
	cout << fixed << setprecision(5);

	//continue to do operations until the file ends
	while(inFile >> operation)
	{
		//performs specified operation
		if(operation == "#")
		{
		}
		else if(operation == "=")
		{
			inFile >> accumulator;
		}
		else if(operation == "->")
		{
			memory = accumulator;
		}
		else if(operation == "<-")
		{
			accumulator = memory;
		}
		else if(operation == "+")
		{
			if(inFile >> num)
				add(accumulator, num);
			else
				cout << "Invalid number!\n";
		}
		else if(operation == "-")
		{
			if(inFile >> num)
				subtract(accumulator, num);
			else
				cout << "Invalid number!\n";
		}
		else if(operation == "*")
		{
			if(inFile >> num)
				accumulator *= num;
			else
				cout << "Invalid number!\n";
		}
		else if(operation == "/")
		{
			if(inFile >> num){
				if(num == 0)
					cout<<"ERROR: CANNOT DIVIDE BY ZERO";
				else
					accumulator /= num;
			}
			else
				cout << "Invalid number!\n";
		}
		else if(operation == "<<")
		{
			cout << "Result is " << accumulator << endl;
		}
		else if(operation == "s" || operation == "S")
		{
			accumulator = sqrt(accumulator);
		}
		else if(operation == "p" || operation == "P")
		{
			if(inFile >> num)
				accumulator = pow(accumulator, num);
			else
				cout << "Invalid number!\n";
		}
		else if(operation == "+m" || operation == "+M")
		{
			accumulator += memory;
		}
		else if(operation == "-m" || operation == "-M")
		{
			accumulator -= memory;
		}
		else if(operation == "*m" || operation == "*M")
		{
			accumulator *= memory;
		}
		else if(operation == "/m" || operation == "/M")
		{
			if(memory == 0)
				cout<< "ERROR: CANNOT DIVIDE BY ZERO";
			else
				accumulator /= memory;
		}
		else
		{
			cout << "ERROR: Operation " << operation << " is invalid!\n";
		}
		//ignores the rest of the line after the operation
		getline(inFile, operation);
	}

	//close file
	inFile.close();
	
	return 0;
}
//adds two numbers together and increments the first
double add(double &a, double b)
{
	return a += b;
}
//subtracts the second number from the first
double subtract(double &a, double b)
{
	return a -= b;
}
