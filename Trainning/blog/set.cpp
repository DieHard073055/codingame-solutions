
/**
 *	@file		set.cpp
 *	@author		Eshan Shafeeq
 *	@date		8 June 2016
 *	@version	v0.1
 *	@breif		Implementation of the set data structure in the STL.
 *				Remove duplicates from a list.
 *				Sorts the set according to the least significant bit
 *
 **/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

//functor to select the least significant bit
//when sorting the set

class lsb_less {
	public:
		bool operator()( int i, int j ){
			return ( i % 10 ) < ( j % 10 );
		}
};


int main( void ){

	std::set< int, lsb_less > data_out;
	std::vector< int > vec;
	std::pair< std::set< int, lsb_less >::iterator, bool > ret;

	//Initialization of random number generator
	std::default_random_engine gen( time(0) );
	std::uniform_int_distribution< int > dist( 0, 255 );

	//Store the number of times a duplicate entry was generated
	int fail_count = 0;

	for( int i=0; i<255; i++ ){
		ret = data_out.insert( dist( gen ) );
		if( ! ret.second )
			++fail_count;
	}

	//Fill up vec by multiplying the contents of data_out with 4
	std::transform( data_out.begin(), data_out.end(), back_inserter( vec ),
		   			std::bind( std::multiplies< int >(), std::placeholders::_1, 4 )	);

	//Show contents of data out
	std::cout << "Data out" << std::endl;
	for( const auto& i : data_out )
		std::cout << i << " ";
	std::cout << std::endl;

	//Show contents of vec
	std::cout << "Vec" << std::endl;
	for( const auto& i : vec )
		std::cout << i << " ";
	std::cout << std::endl;

	int lt = count_if( data_out.begin(), data_out.end(),
		   []( int val ){ return val < 127; }	);

	std::cout << "Less than 127 : " << lt << std::endl;
	std::cout << "Fail count : " << fail_count << std::endl;

}

