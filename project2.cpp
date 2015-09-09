/**
 * Project2 - Computer Science 427
 */

#include "project2.h"

word WORDS[100];
int words_added = 0;

// ask user for filename and parse
bool check_user_file() {

	std::cout << "Please enter a filename: ";

	std::string filename = "";
	std::cin >> filename;

	// determine if user input is valid
	if(filename == "X") {
		exit(0);
	} 

	FILE *file = fopen(filename.c_str(), "r");

	if(filename == "" || !file) {
		fclose(file);
		return check_user_file();
	} else if(filename == "X") {
		fclose(file);
		exit(0);
	}

	const std::string FILENAME = filename;

	// assume input was valid, attempt to parse file
	return parse_file(FILENAME);

}

bool check_default_file() {

	// open default file for reading
	FILE *file = fopen(DEFAULT_FILENAME.c_str(), "r");

	// determine if default file exists
	if(!file) {
		fclose(file);
		return check_user_file();
	}

	// assume file exists beyond this line
	// read file contents line by line
	fclose(file);
	return parse_file(DEFAULT_FILENAME);

}

// called once file exists
bool parse_file(const std::string& filename) {

	int wcount = 0;

	std::string line;
	std::fstream file(filename);

	for(;std::getline(file, line);) {
		wcount += str_split(line, ' ');
	}

	// open file for writing
	std::ofstream fOutputArray(OUTPUTARRAY_FILENAME);
	int fcount = 0;

	// write contents of our array to file
	for(fcount = 0; fcount < words_added; fcount++) {
		fOutputArray << WORDS[fcount].word << ": " << WORDS[fcount].count << std::endl;
	}

	std::cout << wcount << " words found; " << words_added << " words added" << std::endl;
	return true;
}

// split string
int str_split(std::string& string, const char& delim) {

	int wcount = 0;

	std::string word;
	std::stringstream stream(string);

	for(;std::getline(stream, word, delim);) {
		parse_word(word);
		wcount++;
	}

	return wcount;
}

// count each word
bool parse_word(std::string& word) {

	int count = 0;
	int arr_size = sizeof(WORDS) / sizeof(WORDS[0]);

	bool init = false;

	for(;count < arr_size; count++) {
		if(WORDS[count].word == word) {
			WORDS[count].count++;
			init = true;
		}
	}

	if(!init) {
		WORDS[words_added].word = word;
		WORDS[words_added++].count = 1;
	}

	return true;

}

int main() {
	check_default_file();
	return 0;
}