/**
 * @file	message_decoding.cpp
 * @author	Eshan Shafeeq
 * @date	May 5 2016
 * @version	v0.1
 * @brief	:
 *
 * Some message encoding schemes require that an encoded message be sent
 * in two parts. The first part, called the header, contains the characters
 * of the message. The second part contains a pattern that represents the message.
 * You must write a program that can decode messages under such a scheme.
 *
 * The heart of the encoding scheme for your program is a sequence of "key"
 * strings of 0's and 1's as follows:
 * 0,00,01,10,000,001,010,011,100,101,110,0000,0001,. . .,1011,1110,00000, . . .
 *
 * The first key in the sequence is of length 1, the next 3 are of length 2, the
 * next 7 of length 3, the next 15 of length 4, etc. If two adjacent keys have the
 *  same length, the second can be obtained from the first by adding 1 (base 2).
 *  Notice that there are no keys in the sequence that consist only of 1's.
 *
 * The keys are mapped to the characters in the header in order. That is, the first key (0)
 * is mapped to the first character in the header, the second key (00) to the second character
 * in the header, the kth key is mapped to the kth character in the header. For example,
 * suppose the header is:
 *
 * AB#TANCnrtXc
 * Then 0 is mapped to A, 00 to B, 01 to #, 10 to T, 000 to A, ..., 110 to X, and 0000 to c.
 *
 * The encoded message contains only 0's and 1's and possibly carriage returns, which are to
 * be ignored. The message is divided into segments. The first 3 digits of a segment give the
 * binary representation of the length of the keys in the segment. For example, if the first 3
 * digits are 010, then the remainder of the segment consists of keys of length 2 (00, 01, or 10).
 * The end of the segment is a string of 1's which is the same length as the length of the
 * keys in the segment. So a segment of keys of length 2 is terminated by 11. The entire
 * encoded message is terminated by 000 (which would signify a segment in which the keys
 * have length 0). The message is decoded by translating the keys in the segments one-at-a-time
 * into the header characters to which they have been mapped.
 *
 * INPUT SAMPLE:
 *
 * The input file contains several data sets. Each data set consists of a header and a message.
 * These will all be on one line. The length of the header is limited only by the fact that key
 * strings have a maximum length of 7 (111 in binary). If there are multiple copies of a character
 * in a header, then several keys will map to that character. The encoded message contains only 0's
 * and 1's, and it is a legitimate encoding according to the described scheme. That is, the message
 * segments begin with the 3-digit length sequence and end with the appropriate sequence of 1's.
 * The keys in any given segment are all of the same length, and they all correspond to characters
 * in the header. The message is terminated by 000. Your program should accept the first argument as
 * the filename and read the contents of this file as the test data, according to the conditions
 * above. E.g.
 *
 * $#**\0100000101101100011100101000
 * OUTPUT SAMPLE:
 *
 * For each data set, your program must write its decoded message on a separate line. There
 * should not be blank lines between messages. E.g.
 *
 * ##*\$
 *
 **/

#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

#define MAX_BITS 64
int max_bit( int i ){
	return ( 1 << i ) -1;
}

std::vector< std::string > get_keys( int numbits ){

	std::vector<std::string> data;
	std::bitset<MAX_BITS> max( max_bit( numbits ) );
	int z=0;

	for( int i=0; i<MAX_BITS; i++ ){
		if( max.to_string()[i] == '0' ){
			z++;
		}else{
			break;
		}
	}
	for( int i=0; i<max_bit( numbits ); i++ ){
		std::bitset<MAX_BITS> out(i);
		std::string sout = out.to_string().substr( z, out.to_string().length() - z );
		data.push_back( sout );
	}

	return data;

}
std::unordered_map<std::string, char> get_dict( std::string cipher ){

	std::unordered_map<std::string, char> dict;
	std::vector< std::string > keylist;
//	std::cout << "=========================" << std::endl;

	int counter = 1;
	int cipher_len = cipher.length();

	//Calculate the number of bits required for the DICT.

	while( cipher_len > 0 ){

		if( counter == 1 ){

			cipher_len -= counter;

		}else{

			cipher_len -= ( counter * counter ) -1;

		}
		counter++;
	}
//	std::cout << counter-1 << std::endl;

	//Get a vector full of the keys we require
	for( int i=1; i<counter; i++ ){

		std::vector< std::string > keys;
		keys = get_keys( i );
		keylist.insert( keylist.end(), keys.begin(), keys.end() );
	}
//	for( int i=0; i<keylist.size(); i++ ){
//		std::cout << keylist[i] << " ";
//	}
//	std::cout << std::endl;

	//Fill up the hashtable with our keys
	for( int i=0; i< cipher.length(); i++  ){
		dict.insert( {keylist[i], cipher[i]} );
//		std::cout << keylist[i] << " : " << cipher[i] << std::endl;
	}


	return dict;
}

bool terminate_segment( std::string byte ){
	for( int i=0; i<byte.length(); i++ )
		if( byte[i] == '0' ) return false;
	return true;
}
char get( std::string key, std::unordered_map<std::string, char> dict ){

	std::unordered_map<std::string, char>::const_iterator search = dict.find( key );
	if( search != dict.end() ){
		return search->second;
	}else{
		return 0;
	}
}
bool get_data( const int len, int& cpos, std::string data, int i, std::unordered_map<std::string, char> dict ){

	std::string byte = data.substr( i, len );
	std::string p_data ="";
	if( terminate_segment( byte )){
		cpos = i + len;
		return false;

	}else{

		std::cout << get( data.substr( i, len ), dict );
	}	//std::cout << data.substr( i, len ) << " ";

	return true;

}
void process( std::string line ){

	std::string cipher="";
	int key_length=0;
	std::string data;
	bool running = true;
	std::unordered_map< std::string, char > dict;


//	std::cout << "raw : " << line << std::endl;

	for( int i=0; i<line.length(); i++ ){
		if( line[i] != '0' && line[i] != '1' ){
			cipher+=line[i];
		}else{
//			std::cout << "i : " << i << " len : " << line.length() << " c : " << line.length()-i << std::endl;
			data = line.substr( i, ( line.length() - i-1 ));
			break;
		}
	}


	dict = get_dict( cipher );

	int segment = 0;
	int cpos = 0;
	while( running ){
//		std::cout << "pr : " << data << std::endl;


		std::bitset<3> key_len(data.substr( cpos, 3));
		std::bitset<3> terminate_msg; terminate_msg.reset();

//		std::cout << "cpos : " << cpos << " data : " << data.substr( cpos, 3 ) << std::endl;

		if( key_len != terminate_msg ){
//			std::cout << "seg : " << segment++ << " keylen : " << key_len.to_ulong() << std::endl;

			for( int i = cpos+3; i<data.length(); i+=key_len.to_ulong() ){
				int len = (int) key_len.to_ulong();
				if( !get_data( len, cpos, data, i, dict ) ) break;
			}
		}else{
			running = false;
			break;
		}
//		std::cout << std::endl;
	}
	std::cout << std::endl;
//	std::cout << cipher << " ";
//	std::cout << data << std::endl << std::endl;



}


int main( int argc, char * argv[] ){

	std::ifstream stream( argv[1] );
	std::string line;

	while( std::getline( stream, line ) ){
		process( line );
	}

	return 0;
}
