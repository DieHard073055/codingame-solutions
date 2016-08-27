
/**
 *	@file		list.cpp
 *	@author		Eshan Shafeeq
 *	@date		3 Jun 2016
 *	@version	v0.1
 *	@brief		Implementation of the STL list container
 *				using C++14
 *				Also demonstrates the splice function.
 *
 **/

#include <iostream>
#include <list>
#include <vector>

/**
 * @method 	Get Catalan Numbers
 * @brief	Returns a vectors of catalan numbers based on the size
 * @param	size	The number of catalan numbers to be returned.
 **/

std::vector< unsigned long long > get_catalan_numbers( size_t size ){
	std::vector< unsigned long long > catalan( size+1 );

	catalan[0] = catalan[1] = 1;

	for( int i=2; i<size+1; i++ ){
		catalan[i]=0;
		for( int j=0; j<i; j++ ){
			catalan[i] += catalan[j] * catalan[ i - j - 1 ];
		}
	}
	return catalan;

}

/**
 *
 * @method	main
 * @brief	Generates 25 Catalan numbers, splits the numbers into 2 lists.
 * 			splice the first list in the middle to insert list 2.
 *
 **/

int main( void ){

	std::list< unsigned long long > catalan_1;
	std::list< unsigned long long > catalan_2;

	std::vector< unsigned long long > catalan = get_catalan_numbers( 25 );

	std::cout << "Generating the first 25 Catalan Numbers" << std::endl;

	for( std::vector< unsigned long long >::const_iterator it = catalan.begin();
	 		it != ( catalan.begin() + ( catalan.size()/2 )  );
	 		it++  ){
		std::cout << *it << " ";
		catalan_1.push_back( *it );
	}

	for( std::vector< unsigned long long >::const_iterator it = ( catalan.begin()+catalan.size()/2);
	  		it != catalan.end();
	  		it++ ){
		std::cout << *it << " ";
		catalan_2.push_back( *it );
	}
	std::cout << std::endl;

	std::cout << "Splicing catalan_1 in the middle" << std::endl;
	std::list< unsigned long long >::iterator it;
	it = catalan_1.begin();
	for( int i=0; i<( catalan_1.size()/2 ); i++ )
		++it;

	//The main use of lists.
	catalan_1.splice( it, catalan_2 );

	for( auto& c : catalan_1 )
		std::cout << c << " ";
	std::cout << std::endl;

}
