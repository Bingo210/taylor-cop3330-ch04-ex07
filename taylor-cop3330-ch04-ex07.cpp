/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Noah Taylor
 */

// Chapter 4 exercise 7

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Main function
int main()
{
	// Variable declaration
	vector<string> spelledNums = { "zero", "one", "two", "three", "four", 
		"five", "six", "seven", "eight", "nine" };
	string realNums[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string num1, num2;
	char operation;
	int num1int = 0, num2int = 0, flag1 = 0, flag2 = 0;

	// Displays title and input rules to user
	cout << "This program is a simple calculator (one operation, two operands)\n";
	cout << "Only +, -, *, and / are supported\n";
	cout << "Inputs are either integers or numbers spelled out in lowercase (zero - nine only)\n";
	cout << "Must be formatted 'operator' 'operation' 'operator' with spaces between each as shown\n";
	cout << "=====================================================================================\n\n";

	// Prompts user for expression, stores numbers as strings and operation as a character
	cout << "Enter an expression: ";
	cin >> num1 >> operation >> num2;

	// Traverses the length of the spelledNums vector until i>= the size of it
	// or the user's input matches a string inside of it
	// If a match is made, the numInt1 is given the int value in the realNums array at that increment i
	// A flag is also tripped so that numInt1 now knows its value came from a spelled number
	// This allows for numbers and spelled numbers to be used simultaneously
	// Process repeats for numInt2
	for (unsigned int i = 0; i < spelledNums.size(); i++) {
		if (num1 == spelledNums[i]) {
			num1int = stoi(realNums[i]);
			flag1 = 1;
		}
		if (num2 == spelledNums[i]) {
			num2int = stoi(realNums[i]);
			flag2 = 1;
		}
	}

	// If user doesn't input a spelled number, the corresponding numInt is given
	// the int value of user input 'num' via stoi() function
	if (flag1 == 0)
		num1int = stoi(num1);
	if (flag2 == 0)
		num2int = stoi(num2);

	// Switch case statement to calculate result for each operation
	// Prints appropriate response
	// Restricts invalid symbols
	switch (operation) {
	case '+': cout << "\nThe sum of " << num1int << " and " <<
		num2int << " is " << num1int + num2int << endl; break;
	case '-': cout << "\nThe difference between " << num1int <<
		" and " << num2int << " is " << num1int - num2int << endl; break;
	case '*': cout << "\nThe product of " << num1int << " and " <<
		num2int << " is " << num1int * num2int << endl; break;
	case '/': cout << "\nThe quotient of " << num1int << " and " <<
		num2int << " is " << num1int / num2int << endl; break;
	default: cout << "\nInvalid input. Check title for input constraints." << endl;
	}

	system("pause>0");
}
