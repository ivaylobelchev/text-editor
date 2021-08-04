#include "header.h"

void run(char* text)
{
	// Calculating text length
	short textLength = findLength(text);

	short function_number = menu(text);
	
	switch (function_number)
	{
	case 1:
		capital(text, textLength);
		break;
	case 2:
		lowercase(text, textLength);
		break;
	case 3:
		wordlookup(text, textLength);
		break;
	case 4:
		worddeletion(text, textLength);
		break;
	case 5:
		wordreplace(text, textLength);
		break;
	case 6:
		textaddition(text, textLength);
		break;

	default:
		break;
	}

	std::cout << "Current text is:\n\n" << text << "\n\n";

	std::cout << "Do you want to continue? [Y/N] ";

	char answer = 0;
	std::cin >> answer;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// clears buffer memory if there have been entered more than 1 character

	if (answer == 'Y' || answer == 'y')
	{
		system("cls");
		run(text); // Recursion
	}
	// If anything different than 'Y' or 'y' is entered, the program ends.
}

short menu(char* text)
{
	displayCurrentText(text);

	std::cout << "\n1) Make all letters CAPITAL (upper case).\n";
	std::cout << "\n2) Make all letters lower case.\n";
	std::cout << "\n3) Word lookup\n";
	std::cout << "\n4) Word deletion\n";
	std::cout << "\n5) Word replace\n";
	std::cout << "\n6) Text addition\n";

	std::cout << "\nPlease choose one of the previously listed indexes of a function: ";

	short ans = -1;
	ans = SafeIntegerEnter(1, 6);

	system("cls");

	return ans;
}

int SafeIntegerEnter(const int low, const int up)
{
	int input;
	bool successful;
	short counter = 0;

	do {
		if (counter) std::cout << error << "Wrong input! \n";
		std::cin >> input;
		counter++;
		//std::cout << std::endl << intNumber << std::endl;

		successful = !std::cin.fail();

		if (!successful)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!successful || (input < low) || (input > up));

	return input;
}

char toUppercase(const char letter)
{
	if (letter >= 'a' && letter <= 'z')
	{
		return letter - ('a' - 'A');
	}
	return letter;
}
void capital(char* text, const short length)
{
	std::cout << "\n1) Make all letters CAPITAL (upper case).\n\n";

	for (short i = 0; i <= length; i++)
	{
		text[i] = toUppercase(text[i]);
		// Makes individual letter (after checking whether it's a letter or not) capital.
	}
}

char toLowercase(const char letter)
{
	if (letter >= 'A' && letter <= 'Z')
	{
		return letter + ('a' - 'A');
	}
	return letter;
}
void lowercase(char* text, const short length)
{
	std::cout << "\n2) Make all letters lower case.\n\n";

	for (short i = 0; i <= length; i++)
	{
		text[i] = toLowercase(text[i]);
		// Makes individual letter (after checking whether it's a letter or not) lower case.
	}
}

short findLength(char* text)
{
	short counter = 0;
	for (short i = 0; text[i] != 0; i++)
	{
		counter++;
		// Counts until a \0 is reached.
	}
	return counter;
}

void wordlookup(char* text, const short length)
{
	displayCurrentText(text);

	std::cout << "\n3) Word lookup\n\n";

	char* word = new char[1001];
	std::cout << "Enter the word you want to find: ";

	std::cin >> word;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// clears buffer memory if there have been entered more than 1 word

	short wordLength = findLength(word);

	short foundWordLocation = lookup(text, length, word, wordLength);
	// This is the location of the word that was input.

	if (foundWordLocation == -1)
	{
		std::cout << "\nThe word is not contained in the text!\n\n";
	}
	else
	{
		std::cout << "\nThe location of the word is " << foundWordLocation << "\n\n";
	}

	delete[] word;
}

short lookup(char* text, const short textLength, char* word, const short wordLength)
{
	short wordLocation = -1;
	for (short i = 0; i < textLength; i++)
	{
		wordLocation = i;
		for (short j = 0; j < wordLength; j++)
		{
			if (text[i + j] == word[j]);
			else
			{
				wordLocation = -1;
				break;
			}
		}
		if (wordLocation != -1)
		{
			break;
		}
	}
	return wordLocation;

	/*
	Starts by comparing each letter of the text to the first letter of the word.
	If a match is found at letter with index k in the text, then the letter from the text
	with index k + 1 and the next letter (second, in this case) in the word are compared.
	If they match, this continues to be repeated until the word ends or
	non-matching letters are found. If non-matching letters are found, we return
	to the initial loop that compares each letter of the text to the 1st letter of the word.
	If the word is not contained anywhere in the text, value of -1 is returned.
	*/
}

void worddeletion(char* text, const short textLength)
{
	displayCurrentText(text);
	// It is important that the current text is displayed for the convenience of the user.

	std::cout << "\n4) Word deletion\n\n";

	char* word = new char[1001];
	std::cout << "Enter the word you want to delete: ";
	std::cin >> word;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// clears buffer memory if there have been entered more than 1 word

	short wordLength = findLength(word);

	short foundWordLocation = lookup(text, textLength, word, wordLength);

	if (foundWordLocation == -1)
	{
		std::cout << "\nThe word is not contained in the text!\n\n";
	}
	else
	{
		for (short i = foundWordLocation; i < textLength; i++)
		{
			text[i] = text[i + wordLength];
		}
		// Moves the letters to the left by the same number of characters 
		// as is the length of the word.
	}

	delete[] word;
}

void displayCurrentText(char* text)
{
	std::cout << "Current text is:\n\n" << text << "\n";
	// Function used for the convenience of not typing that in.
}

void wordreplace(char* text, const short textLength)
{
	displayCurrentText(text);

	std::cout << "\n5) Word replace\n\n";

	char* word_delete = new char[1001];
	char* word_replacement = new char[1001];

	std::cout << "Enter the word you want to be replaced and enter the word you want it replaced with:\n";
	std::cin >> word_delete >> word_replacement;
	// I use cin and not cin.getline since words are not supposed to have spaces in them.

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// clears buffer memory if there have been entered more than 2 words

	short word_delete_Length = findLength(word_delete);
	short word_replacement_Length = findLength(word_replacement);

	short foundWordLocation = lookup(text, textLength, word_delete, word_delete_Length);

	if (foundWordLocation == -1)
	{
		std::cout << "\nThe word is not contained in the text!\n\n";
	}
	else
	{
		if (word_replacement_Length > word_delete_Length)
		{
			for (short i = textLength - 1; i > foundWordLocation; i--)
			{
				text[i - word_delete_Length + word_replacement_Length] = text[i];
			}
		}
		else if (word_delete_Length > word_replacement_Length)
		{
			for (short i = foundWordLocation + 1; i < textLength; i++)
			{
				text[i - word_delete_Length + word_replacement_Length] = text[i];
			}
		}
		/*
			I need to use an if statement to choose a method of moving the letters
			because the method used for moving letter left or right is different.
			If the lenght of the new and the old word match, then this is skipped.
		*/

		for (short i = 0; i < word_replacement_Length; i++)
		{
			text[i + foundWordLocation] = word_replacement[i];
			// I'm assigning the values of the parts of the array of the word
			// that is to be in the place of the replaced word.
		}
		text[textLength - word_delete_Length + word_replacement_Length] = 0;
		// Just in case I add a \0 since if the replacement is in the end
		// it sometimes goes missing.
	}

	delete[] word_delete;
	delete[] word_replacement;
}

void textaddition(char* text, const short textLength)
{
	displayCurrentText(text);

	std::cout << "\n6) Text addition\n\n";

	char* textadd = new char[1002];
	short positionToAddTheTextIn = -1;

	std::cout << "Enter a number, pointing to the place where you want to input your text.\n";
	std::cout << "Input a number between 0 and " << textLength << ": ";
	positionToAddTheTextIn = SafeIntegerEnter(0, textLength);

	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	// Without this there are problems with cin.getline

	std::cout << "\nEnter the text you want to add:\n";
	std::cin.getline(textadd, 1001);

	std::cout << std::endl;

	short addLength = findLength(textadd);

	for (short i = textLength; i >= positionToAddTheTextIn; i--)
	{
		text[i + addLength] = text[i];
		// Moves the text to the right by addLength positions.
	}
	for (short i = 0; i < addLength; i++)
	{
		text[i + positionToAddTheTextIn] = textadd[i];
		// Assigns the additional text to its place.
	}
	text[textLength + addLength] = 0;

	delete[] textadd;
}