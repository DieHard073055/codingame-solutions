/**
 * @file	vector.cpp
 * @author	Eshan Shafeeq
 * @version	v0.1
 * @date	21 May	2016
 * @brief	Demonstrating all the operations
 * 			on a vector.
 **/

#include <iostream>//std::cout
#include <vector>  //Duh?!
#include <stdexcept> //std::out_of_range
#include <algorithm> //find()

/**
 *
 * @method 	Print Vector Details
 * @param	std::vector< int > vec		The vector to be printed out
 * @param	std::string name			The identifier for the vector
 *
 * @brief	This function will print out the details about the
 * 			vector.
 * 			details : size, capacity, elements
 *
 **/
void print_vec_details( std::vector<int> vec, std::string name ){
	std::cout << "Vector - " << name << ": " << std::endl;
   	std::cout << "size : " << vec.size() << std::endl;
   	std::cout << "capacity : " << vec.capacity() << std::endl;

	if( vec.empty() ){
		std::cout << "This vector is empty" ;
	}else{
		//std c++11 iteration
		//const iterator since we will not be
		//modifying the contents of the vector
		for( std::vector< int >::const_iterator 	it=vec.begin();
											it != vec.end();
											++it
		){
			std::cout << *it << " ";
		}
	}

	std::cout << std::endl << "------------" << std::endl << std::endl;
}

/**
 *
 * @method 	Main
 * @brief	This program will test some of the methods which can be
 * 			used on/with vectors for the purpose of demonstration.
 **/
int main( void ){

	std::vector< int > vec; //empty vector
	std::vector< int > vec2 = { 1, 2, 3, 4 }; //vector with predefined elements
	std::vector< int > vec3( 10 ); //vector of size ten
	std::vector< int > vec4( vec2.begin(), vec2.end()-1 ); // vector 2 without the last element
	std::vector< int > vec5( vec2 ); // a full copy of vector 2 ( calls the copy ctor )
	std::vector< int > vec6; //empty vector


	vec6.push_back(15); // add 15 to the list
	//emplace back can also be used
	//but usually used in cases where to call the ctor of the
	//vector< type >

	//use of the back() method
	while( vec6.back() > 0 ){
		vec6.push_back( vec6.back() - 3 );
	}

	//print the details about the vector
	print_vec_details( vec, "vec" );
	print_vec_details( vec2, "vec2" );
	print_vec_details( vec3, "vec3" );
	print_vec_details( vec4, "vec4" );
	print_vec_details( vec5, "vec5" );
	print_vec_details( vec6, "vec6" );

	std::cout << "Cooler method of iteration (C++14)" << std::endl << std::endl;

	//Just as cool as the const_iterator but
	//this produces cleaner and nicer code.
	for( const auto& it : vec2 ){
		std::cout << it << " ";
	}
	std::cout << std::endl << "--------------" << std::endl << std::endl;

	//Modifying the contents
	for( auto& it : vec5 ){
		it *= 10;
	}

	print_vec_details( vec5, "vec5" );

	//Accessing elements via [] operator
	std::cout << "vec2[2] : " << vec2[2] << std::endl;

	//Via the at() method
	//throws out_of_range exception
	std::cout << "vec2.at( 100 ) = 42" << std::endl;
	try{
		vec2.at(100) = 42;
	}catch( const std::out_of_range& e ){
		std::cerr << "Trying to access the array from outside its range" << std::endl
			<< e.what() << std::endl << std::endl;
	}

	//this is also possible
	int* vec_pointer = &vec5[0];

	std::cout << "Using a pointer with the vec5 " << std::endl;
	std::cout << "First element : " << vec_pointer[0] << std::endl;
	std::cout << "Second element : " << vec_pointer[1] << std::endl;

	//Using the swap method
	std::cout << "Swapping the vec2 with vec5" << std::endl << std::endl;
	vec2.swap( vec5 );


	print_vec_details( vec2, "vec2" );
	print_vec_details( vec5, "vec5" );


	for( const auto& it : vec2 ){
		//Fast insertion at the back
		vec.push_back( it/2 );
	}

	const auto it = find( vec.begin(), vec.end(), 10 );
	vec.erase( it );

	print_vec_details( vec, "vec" );

	//Fast removal at the back
	vec.pop_back();

	print_vec_details( vec, "vec" );

	std::cout << "Clearing vec2 " << std::endl;
	//clear the vector
	vec2.clear();


	print_vec_details( vec2, "vec2" );

	return 0;
}
/*
 * Some noteable propertise with vectors
 * --------------------------------
 *  -Fast operations at the end of the vector O(1)
 *  i.e. push_back(), pop_back()
 *
 *  -Slow operations at the begining.. O(N)
 *  -And at last, Slow Search.. O(N)
 */
