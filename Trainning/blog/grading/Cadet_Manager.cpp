/**
 *
 * @file	Students.cpp
 * @author	Eshan Shafeeq
 * @date	19 June 2016
 * @version v0.1
 * @brief	A program to generate some common statistics from the
 * 			scores recieved to the cadets for different subjects.
 *
 **/
#include <sstream>
#include <fstream>
#include <cmath>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include "Cadet.h"

#define ALL_DATA		1
#define	SEARCH			2
#define FILE_N_FOUND	64
#define EXIT			128

//Get data from stdin and populate the cadets vector and the records table
int get_raw_data( std::vector<Cadet>& cadets,
		std::unordered_map<std::string, Cadet>& records,
		const char * filename ){

	std::ifstream inf (filename);
	int data_size=0;

	if( inf ){
		inf >> data_size;
		inf.ignore(1);

		for( int i=0; i<data_size; i++ ){
			std::string line;
			std::getline( inf, line );

			std::stringstream ss;
			Cadet c;
			ss << line;
			ss >> c;
			c.calculate_scores();
			c.calculate_grades();
			c.calculate_avg();
			c.calculate_minmax();
			c.calculate_median();

			cadets.push_back( c );
			records.insert(	std::make_pair( c.get_name(), c ) );
		}
	}else{
		std::cout << "failed to read data file " << std::endl;
		return 0;
	}
	return 1;
}
//Calculate the average of all the cadets average score
double get_avg_score( std::vector< Cadet >& cadets ){

	double sum = accumulate( cadets.begin(), cadets.end(), 0.0,
			[]( double a, Cadet c ){
				return a + c.get_avg();
			});
	return (double) ( sum / cadets.size() );
}
//Calculate the Minmax for the average for all the cadets
void get_minmax_score( std::vector< Cadet >& cadets, double& gmin, double& gmax ){

	std::pair< std::vector<Cadet>::iterator, std::vector<Cadet>::iterator > minnmax =
		std::minmax_element( cadets.begin(), cadets.end(),
			   []( Cadet a, Cadet b ){ return a.get_avg() < b.get_avg(); }	);

	gmin = (*minnmax.first).get_avg();
	gmax = (*minnmax.second).get_avg();

}
//Search for a specific cadet based on their id
void search_records( std::unordered_map< std::string, Cadet >& records, std::string s  ){
	std::unordered_map< std::string, Cadet >::iterator it = records.find( s );

	if( it != records.end() ){
		std::cout << it->second ;
	}else{
		std::cout << "Cannot find cadet with ID : " << s << std::endl;
	}

	std::cout << std::endl;

}
//Print out the details for the set of cadets
void show_records_details( std::vector<Cadet> cadets ){

	double gmin, gmax;

	get_minmax_score( cadets, gmin, gmax );
	std::cout << std::endl << "\t===== ALL CADETS =====" << std::endl;
	std::cout << "AVG : " << get_avg_score( cadets )
		<< "\tMIN : " << gmin
		<< "\tMAX : " << gmax
		<< std::endl << "\t=======================" << std::endl << std::endl;
}

void no_operations_specified(){
	std::cout << "error: no operations specified" << std::endl;
	std::cout << "use -h for help" << std::endl;
}

void wrong_command(){
	std::cout << "error : wrong command" << std::endl;
	std::cout << "use -h for help" << std::endl;
}

void show_all_records( std::vector<Cadet> cadets ){
	for( auto& c : cadets ){
		std::cout << c;
	}
	std::cout << std::endl;
}

void show_help_menu( const char* argv[]  ){
	std::cout << "usage: " << argv[0] << " <operation> [....]" << std::endl;
	std::cout << "operations: " << std::endl;
	std::cout << "\t" << argv[0] << " -h\t\t\t(for this help menu)" << std::endl;
	std::cout << "\t" << argv[0]
		<< " -f [records_file]\t(to specify the records file)"
		<< std::endl;
	std::cout << "\t" << argv[0]
		<< " -s [search_name]\t(to search for the details of a specific cadet)"
		<< std::endl;
	std::cout << std::endl
		<< "eg: use '" << argv[0] << " -f testcase'"
		<< std::endl;
}

int process_arguments(
		int argc,
		const char* argv[],
		std::vector<Cadet>& cadets,
		std::unordered_map< std::string, Cadet >& records,
		std::string& search_s
		){

	int ret = 0 ;
	std::cout << "argc : " << argc << std::endl << std::endl;
	if( argc < 2 ){
		no_operations_specified();
		ret|=EXIT;
	}else if( argc == 2 ){
		std::string arg1( argv[1] );
		if( arg1 == "-h" ){
			show_help_menu( argv );
		}else
			no_operations_specified();

		ret|=EXIT;

	}else if( ( (argc-1) % 2 ) == 0 ){
		for( int i=1; i<argc; i+=2 ){
			std::string argi(argv[i]);
			if( argi == "-f" ){
				int f_ret = get_raw_data( cadets, records, argv[i+1] );
				if( f_ret == 0 ){
					std::cout << "File not found" << std::endl;
					ret|=EXIT;
				}
			}else if( argi == "-s" ){
				search_s.assign( argv[i+1] );
				if( search_s == "-all-data" ) ret|=ALL_DATA;
				else ret|=SEARCH;

			}else{
				wrong_command();
				ret|=EXIT;
			}
		}
	}else{
		wrong_command();
		ret|=EXIT;
	}

	return ret;
}
int main( int argc, const char* argv[] ){

	std::vector<Cadet> cadets;
	std::unordered_map<std::string, Cadet> records;
	std::string search_s;

	int ret = process_arguments( argc, argv, cadets, records, search_s );
	if( (ret & EXIT) == EXIT )
		return 0;


	show_records_details(cadets);

	if( (ret & SEARCH) == SEARCH) search_records( records, search_s );
	if( (ret & ALL_DATA) == ALL_DATA ) show_all_records( cadets );



	return 0;
}
