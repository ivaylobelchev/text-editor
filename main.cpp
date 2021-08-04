#include "header.h"

int main()
{
	system("chcp 1251");
	// This is used to make Cyrilic usable in the program even though
	// Cyrilic letters cannot be capitalized or lowercased

	system("cls");
	// Clears the message prompted by the previous command

	std::cout << "Please enter initial text:\n\n";

	const int maxNumberOfCharacters = 5001;
	// I declare the array to be more than 1000 characters 
	// since those can be added additionally within the program.
	// 5000 is 5 times bigger than 1000 so enough characters can be added within the run of the code.

	char* text = new char[maxNumberOfCharacters]; 
	// The array where text will be added and worked with

	std::cin.getline(text, 1001); // Text can be input only on 1 line
	system("cls");

	run(text);

	delete[] text;
	return 0;
}