#pragma once

#include <iostream>
#include <limits>

short menu(char* text);
// Menu is used to navigate the program

int SafeIntegerEnter(const int low, const int up);
// Function for number validation

char toUppercase(const char letter);
void capital(char* text, short length);
// Makes the letters capital

char toLowercase(const char letter);
void lowercase(char* text, const short length);
// Makes the letters lowercase

const char error = 7; 
// error signal in ASCII (used during valiation)

void wordlookup(char* text, const short length);

short findLength(char* text);

short lookup(char* text, const short textLength, char* word, const short wordLength);

void worddeletion(char* text, const short textLength);

void displayCurrentText(char* text);

void wordreplace(char* text, const short textLength);

void textaddition(char* text, const short textLength);

void run(char* text);