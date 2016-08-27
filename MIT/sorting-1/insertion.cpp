 /**
  * @file 		insertion.cpp
  * @author		Eshan Shafeeq
  * @version	v0.1
  * @date		5 April 2016
  * @brief		The following code is demostrating
  * 			the insertion sorting algorithm.
  *
  * */
#include <iostream>
#include <vector>

/**
 * Print All
 *
 * Function to print all the values of the vector.
 *
 * @param 	data	The array that contains the values to be printed
 *
 * */

void print_all(std::vector<int> data){
	for( int i=0; i<data.size(); i++ ){
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

/**
 *
 * Swap
 *
 * This function will swap the given 2 indexes from the given
 * vector. O(1) constant time.
 *
 * @param	data	The vector on which the swap operation
 * 					will be performed on.
 * @param	a		The index of the first element to be swapped
 * @param	b		The index of the second element to be swapped
 *
 **/

void swap(std::vector<int> &data, size_t a, size_t b){
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

/**
 * Sort
 *
 * This function will perform the insertion sort in accending order
 * on the vector that is passed into the function.
 *
 * @param	data	The vector which the insertion sort will be done on.
 *
 * */

void sort(std::vector<int> &data){
	for( size_t i=1; i<data.size(); i++ ){
		if(data[i] < data[i-1]){
			bool sorted = false;
			int key = i;
			while( sorted != true ){
				if(key-1 != -1){
					if(data[key] < data[key-1]){
						swap(data, key, key-1);
						key--;
					}else{
						sorted = true;
					}
				}else{
					sorted = true;
				}
			}
		}
	}
}

/**
 * Main
 *
 * This program will take a bunch of numbers and sort them
 * in accending order using insertion sorting algorithm.
 * The testcases can look like as follows
 *
 * N
 * Random n numbers
 *
 * eg:
 * 5
 * 8 5 3 7 2
 *
 * And the output will be sorted.
 *
 **/

int main( void ){
	std::vector<int> v;
	size_t nums;

	std::cin >> nums;
	for( size_t i=0; i<nums; i++ ){
		int x;
		std::cin >> x;
		v.push_back(x);
	}
	sort(v);
	std::cout << "--Sorted--" << std::endl;
	print_all(v);


	return 0;
}

