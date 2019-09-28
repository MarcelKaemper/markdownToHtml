#include <string>
#include <iostream>


class Parser {
	
	public:
		std::string parseLine(std::string line) {
			return "Headerlevel: "+std::to_string(getHeaderLevel(line));
		}


	private:
		int getHeaderLevel(std::string line) {
			int headerLevel = 0;
			std::cout << line << std::endl;
			for(std::string::size_type i = 0; i<line.size(); i++) {
				if(line.at(i) == '#') {
					headerLevel+=1;			
				} else if (line.at(i) != '#'){
					return headerLevel;	
				}
			}

			return headerLevel;	
		}
};
