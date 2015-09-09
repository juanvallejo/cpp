/**
 * Project2 - Computer Science 427
 */

#include "project2.h"

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

	std::string line;
	std::fstream file(filename);

	for(;std::getline(file, line);) {
		std::cout << line << std::endl;
	}

	return true;
}

int main() {
	check_default_file();
	return 0;
}