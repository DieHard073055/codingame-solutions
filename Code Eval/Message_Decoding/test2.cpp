



#include <iostream>
#include <bitset>


int max_bit( int i ){
	return ( 1 << i ) -1;
}
int dict( int NUMBITS ){

	std::bitset<32> max( max_bit( NUMBITS ));
	int z=0;
	for( int i=0; i<32; i++ ){

		if( max.to_string()[i] == '0' ){
			z++;
		}else{
			break;
		}
	}
	std::cout << "max : " << max << " string : " << max.to_string() << std::endl;
	for( int i=0; i< max_bit(NUMBITS); i++ ){
		std::bitset<32> out(i);
		std::string sout = out.to_string().substr( z, out.to_string().length() - z );
		std::cout << sout << std::endl;
	}
}
int main( void ){

	for( int i =1; i<6; i++ ){
		dict(i);
	}
	return 0;
}
