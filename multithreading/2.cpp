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

class Fctor{
	public:
		void operator()(  ){
			cout << "t1 : " <<  endl;
			//s = "lololol";
		}
};

int main(){

	string s = "Where there is no trust. there is no love";
	thread t1( (Fctor() ) ); // t1 starts


	t1.join();

	cout << "from main : " << s << endl;

	return 0;
}
