
/**
 *	@file		deque.cpp
 *	@author		Eshan Shafeeq
 *	@date		25 May 2016
 *	@version	v0.1
 *	@brief		Demonstration code for the C++ STL
 *				container Deque.
 *
 **/

#include <iostream> //input output
#include <deque>
#include <algorithm>

/**
 * Print Deque Details
 * -------------------
 *  Functions accepts a deque and a string.
 *  Will print out the size of the deque and the contents.
 *
 *  @param	dec		The dec which will be printed to std out
 *  @param	name	The name of the dec variable
 *
 **/
void print_dec_details( const std::deque<int>& dec, const std::string& name ){

	std::cout << "Deque : " << name << std::endl;
	std::cout << "Size : " << dec.size() << std::endl;

	if( dec.empty() ){
		std::cout << "The deque is empty";
	}else{

		for( const auto& d : dec ){
			std::cout << d << " " ;
		}
	}

	std::cout << std::endl << std::endl;
}
/**
 * Main
 * ----
 *  Demonstration of some uses possible with deque.
 *
 *  @return  0	Returns 0 when the program is done.
 *
 **/
int main( void ){

	//Initializing Variables
	//----------------------
	std::deque<int> dec;
	std::deque<int> dec2 = { 9, 2, 4, 5, 7, 3 };
	std::deque<int> dec3( 9, 20 );
	std::deque<int> dec4( dec2.begin(), dec2.begin()+3 );
	std::deque<int> dec5;
	std::deque<int> dec6;


	//Assigning values to dec from dec2
	//---------------------------------
	//- Demonstrates the use of push_front ( O(1) )
	//- Demonstrates the use of push_back ( O(1) )
	//

	for( const auto& d : dec2 ){
		dec.push_front( d/2 );
		dec.push_back( d * 2 );
	}

	//Assiging values to dec6 from pre-determined values
	//--------------------------------------------------
	//- Demonstrates the assign( x, y ) works just like the deque constructor
	//- Demonstrates how to assign values from an array
	//
	//* Assign will clear the previously allocated values and put in the new ones.
	//


	int catalan[] = { 1, 2, 5, 14, 42, 132, 429, 1430 };
	dec6.assign( 3, 400 );
	dec6.assign( catalan, catalan+6 );


	//Print the initial states of the variables
	//-----------------------------------------
	print_dec_details( dec, "dec" );
	print_dec_details( dec2, "dec2" );
	print_dec_details( dec3, "dec3" );
	print_dec_details( dec4, "dec4" );
	print_dec_details( dec5, "dec5" );
	print_dec_details( dec6, "dec6" );

	//Find 132 from dec6
	//------------------

	if( std::binary_search(
		dec6.begin(), dec6.end(), 132
		)
	)
		std::cout << "found 132 in dec6" << std::endl;
	else
		std::cout << "cannot find 132 in dec6" << std::endl;


	return 0;
}
/**
 *
 * Some Notes on Deque
 * -------------------
 * -Fast operations at the begining and the end of the deque ( O(1) )
 * -Slow if insertion and removal happens at the middle
 * -Slow Search
 * -Fast access using [] or at() O(1)
 *
 **/
