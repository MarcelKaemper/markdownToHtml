#include <iostream>
#include <fstream>
#include <string>
#include "Parser.cpp"

int main() {
	
	Parser p;

	std::cout << "Name of input file: ";
	std::string inputFile;
	std::cin >> inputFile;

	std::cout << "Name of output file: ";
	std::string outputFile;
	std::cin >> outputFile;

	std::fstream f(inputFile);
	f << "    #Tes t\n    ####  Sec ond Line";
	// Reset cursor
	f.seekg(0);

	// line buffer
	std::string line;
	// Each line of input file
	while(std::getline(f, line)) {
		// If a character has occured
		bool hitChar = false;
		// Cursor for the process of overwriting the input line
		int newLineIndex = 0;
		// Each char
		for(std::string::size_type i = 0; i<line.size(); i++) {
			// If char is not a whitespace
			if(line.at(i) != ' ') {
				line.at(newLineIndex) = line.at(i);
				newLineIndex++;
				hitChar = true;
			// If char is a whitespace and a char occured in the line
			// before
			}else if(hitChar){
				line.at(newLineIndex) = line.at(i);
				newLineIndex++;
			}
		}
		line.erase(newLineIndex);
		std::cout << p.parseLine(line);
		std::cout << std::endl;
	}

	f.close();

	return 0;

}
