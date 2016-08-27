
/**
 * @file 	stack_implementation.cpp
 * @author	Eshan Shafeeq
 * @date	3rd May 2016
 * @brief	Implementation of stack prints out the alternating integer
 *
 **/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void process_data( std::string line ){
	std::string delimiter = " ";
	std::vector<std::string> out;
	bool bout = false;

	size_t pos = 0;
	std::string token;
	while ((pos = line.find(delimiter)) != std::string::npos) {
			    token = line.substr(0, pos);
			//	std::cout << token << " ";
				if( bout ){
					bout = false;
					out.push_back(token);

				}else{
					bout = true;
				}
			line.erase(0, pos + delimiter.length());

	}
//	std::cout << line[line.length()-1] << std::endl;
	out.push_back( line );
	for( int i=0; i<out.size(); i++ )
		std::cout << out[ out.size()-1 - i]  << " ";
	std:: cout << std::endl;
	//out = out.substr(1, out.length());
	//std::cout << out << std::endl;
	//std::cout << line << std::endl;
}
int main( int argc, char * argv[] ){

	std::ifstream datafile(argv[1]);

	std::string line;

	while( std::getline( datafile, line ) ){

		process_data( line );
	}

	return 0;
}
