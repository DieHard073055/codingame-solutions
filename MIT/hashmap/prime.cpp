/**
 * Implementation of the fastest prime number generation algorithm from 2 to N
 *
 * @author	Eshan Shafeeq
 * @version v0.1
 * @date 25 April 2016
 *
 * took the prime number code from
 * @url 	http://code.runnable.com/UpR6JF-VugtJAAEg/print-first-n-prime-numbers-using-for-loop-for-c%2B%2B
 **/

#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> get_primes( int num_primes ){

	int status=1, num = 3, count_, c;
	std::vector<int> primes;

	for( count_ = 2; count_ <= num_primes; ){
		for( c=2; c<=(int)sqrt(num); c++ ){
			if( num%c == 0 ){
				status = 0;
				break;
			}
		}
		if( status != 0 ){
			primes.push_back(num);
			count_++;
		}
		status = 1;
		num++;
	}

	return primes;

}

int main( void ){

	std::vector<int> primes = get_primes( 1000000 );

	std::cout << "number of primes : " << primes.size() << std::endl;

	std::cout << "last prime : " << primes[ primes.size()-1 ] << std::endl;

	return 0;
}
