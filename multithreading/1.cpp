/*
 * @file	threading_1.cpp
 * @author	Eshan Shafeeq
 * @compile	g++ 1.cpp -o 1 --std=c++11 -pthread
 **/

#include <iostream>
#include <thread>
#include <string>

using namespace std;


void function_1(){
	cout << "Beauty is only skin deep" << endl;
}
int main(){

	thread t1(function_1); // t1 starts

	//t1.join();
	t1.detach();

	if( t1.joinable() ){
		cout << "joinable" << endl;
		t1.join(); //crash
	}
	return 0;
}
