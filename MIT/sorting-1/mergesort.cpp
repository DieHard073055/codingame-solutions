/**
 * @file	mergesort.cpp
 * @author	Eshan Shafeeq
 * @version	v0.1
 * @date	5 April 2016
 * @brief	Implementation of merge sort.
 *
 * */

#include <iostream>
#include <vector>

/**
 * Print All
 *
 * This function will print all the values in
 * the vector passed into this function.
 *
 * @param	out		The vector which will be printed
 * 					out to the screen.
 *
 * */
void print_all( std::vector<int> out ){
	for( size_t i=0; i<out.size(); i++ ){
		std::cout << out[i] << " ";
	}
	std::cout << std::endl;
}

/**
 * Merge
 *
 * This function will merge the 2 lists thats been passed
 * into this function. In the following manner.
 * list-1 = 4 6 8
 * list-2 = 1 2 9
 * return vector = 1 2 4 6 8 9
 *
 * As this is a required operation on the merge sort.
 *
 * @param	left_prime	The left side of the unsorted list
 * @param	right_prime	The right side of the unsorted list
 *
 **/

std::vector<int> merge( std::vector<int> left_prime,
						std::vector<int> right_prime ){
	size_t i=0;
	size_t j=0;
	std::vector<int> new_vec;
	bool sorted = false;

	while( sorted != true ){
		if( left_prime[i] < right_prime[j] ){
			new_vec.push_back( left_prime[i++] );
		}else{
			new_vec.push_back( right_prime[j++] );
		}
		if( i==left_prime.size() ){
			while( j!=right_prime.size() ){
				new_vec.push_back( right_prime[j++] );
			}
		}
		if( j==right_prime.size() ){
			while( i!=left_prime.size() ){
				new_vec.push_back( left_prime[i++] );
			}
		}
		if( i==left_prime.size() && j==right_prime.size()){
			sorted = true;
		}
	}

	return new_vec;
}

/**
 * Merge Sort
 *
 * This function will perform a merge sort on the vector
 * passed into the function.
 *
 * @param	v	vector of numbers which will be sorted.
 *
 **/

std::vector<int> merge_sort( std::vector<int> v ){

	if( v.size()>2 ){
		std::size_t const divide = v.size()/2;
		std::vector<int> left( v.begin(), v.begin() + divide );
		std::vector<int> right( v.begin() + divide, v.end() );

		std::vector<int> left_prime = merge_sort(left);
		std::vector<int> right_prime = merge_sort(right);

		std::vector<int> new_vec = merge(left_prime, right_prime);

		return new_vec;

	}else if( v.size() == 2 ){
		int temp;
		if(v[0] < v[1]) return v;
		else{
			temp = v[0];
			v[0] = v[1];
			v[1] = temp;
			return v;
		}
	}else{
		return v;
	}

}

/**
 * Main
 *
 * This program will take in positive integers and sort them
 * in accending order using merge sort.
 * The program will accept testcase as follows
 * N
 * N numbers
 *
 * eg:
 *
 * 10
 * 9 7 8 4 5 6 1 2 3 10
 *
 * The output will be
 * 1 2 3 4 5 6 7 8 9 10
 *
 **/
int main( void ){

	std::vector<int> data;
	size_t nums;

	std::cin >> nums;
	for( size_t i=0; i<nums; i++ ){
		int x;
		std::cin >> x;

		data.push_back(x);
	}


	data = merge_sort(data);

	print_all(data);
}

