/**
 *
 *
 * @file	threading_3.cpp
 * @author	Eshan Shafeeq
 * @date	3 May	2016
 * @breif	Data Race and Mutex
 *
 **/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>

std::mutex mu;

using namespace std;


void shared_print( string msg, int id ){
	std::lock_guard<std::mutex> guard(mu); //RAII
	cout << msg << " : " << id << "\n";
}
void function_1( string msg ){
	for( int i=0; i>-50; i-- )
		shared_print(msg, i);

}

int main( void ){


	vector<thread> ts;
	for( int i=0; i<10; i++ )
		ts.push_back( thread( function_1, std::to_string(i) ) );

	for( int i=0; i<100; i++ )
		shared_print("main", i);

	for( int i=0; i<10; i++ )
		ts[i].join();

	return 0;
}
