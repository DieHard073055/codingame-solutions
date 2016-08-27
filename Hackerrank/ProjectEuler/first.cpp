#include <iostream>

unsigned long sci( unsigned long n ){
	return (n * (n + 1)) / 2;
}
unsigned long sum( unsigned long n ){
	return sci( int((n-1)/3) ) * 3 + sci( int((n-1)/5) ) * 5 - sci( int((n-1)/15)) * 15;
}
int main(){

	long testcases;
	long n;

	std::cin >> testcases;
	for( size_t i=0; i<testcases; i++ ){
		std::cin >> n;
		std::cout << sum(n) << std::endl;
	}
}
