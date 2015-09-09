#ifndef PROJECT2_H
#define PROJECT2_H

/**
 * Basic c++ program for parsing file data.
 * Attempts to open a pre-defined file, on fail,
 * asks user for custom filename. If found, all words
 * are read from the file, counted, saved as a list
 * in a file 'OutputArray.txt', alphabetized, and saved
 * to a second file 'OutputResults.txt'
 *
 * @author juanvallejo
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

const std::string DEFAULT_FILENAME = "TestData.txt";

struct word {
	std::string word;
	int count;
};

/**
 * Asks user for custom filename, reads file
 */
bool check_user_file();

/**
 * Default file to be parsed by the program
 */
bool check_default_file();

/**
 * Parses file using fsream
 */
bool parse_file(const std::string& filename);

/**
 * Split a string by a specified delimeter and only
 * return the amount of words found. Useful for counting
 */
int str_split(std::string& string, const char& delim);

/**
 * Split string by a specified delimtere and parse each word
 * into a passed word struct array
 */
int str_split_parse(std::string& string, const char& delim, struct word *WORDS, int array_size);

/**
 * Puts each word into a passed struct array if the word
 * is new. Returns true if word doesn't exist, false otherwise.
 */
bool parse_word(std::string& word, struct word *WORDS, int array_size);

#endif