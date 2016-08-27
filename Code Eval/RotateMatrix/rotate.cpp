/**
 * @file 	rotate.cpp
 * @version v0.1
 * @author	Eshan Shafeeq
 * @date 	2 May 2016
 * @brief	Rotates a 2D matrix 90deg using this magic number
 * 			technique i found, fiddling with the forloops.
 **/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

void rotate( std::string line ){


	std::vector<char> data;
	std::stringstream lines(line);
	char n;

	while(lines >> n )
		if( n != ' ' )
			data.push_back(n);


	int seg = sqrt( data.size() );


	for( int i=seg-1; i>-1; i-- ){
		for( int j=seg-1; j>-1; j-- ){

			int magic_number =  ((1*j) * (i+1)) + ((seg-1-i) * (j+1)) ;

			std::cout << data[magic_number] << " ";

		}
	}
	std:: cout << std::endl;



}
int main( int argc, char * argv[]  ){

	std::ifstream stream( argv[1] );
	std::string line;

	while( std::getline( stream, line ) ){
		rotate(line);

	}
}
