#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::ofstream f("test.md");
	f << "Test\n";
	f.close();

	std::ifstream f2("test.md");
	std::string line;

	while(std::getline(f2, line)) {
		std::cout << line << std::endl;
	}

	f.close();

	return 0;

}
