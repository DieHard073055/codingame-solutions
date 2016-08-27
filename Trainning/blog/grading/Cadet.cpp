/**
 *
 * @file		Cadet.cpp
 * @author		Eshan Shafeeq
 * @date		19 June 2016
 * @version		v0.1
 * @brief		Implementation of the calculations for the
 * 				Cadet.h class. Calculates scores, Grades,
 * 				Averages, Minmax and Median.
 *
 **/
#include "Cadet.h"

const int Cadet::MAX_SCORES[] = { 275, 940, 55, 39, 67, 42, 98, 444  };

void Cadet::insert_data( std::string name, const std::vector<int>& raw_scores ){
	this->name = name;
	this->raw_scores.resize(8);
	copy( raw_scores.begin(), raw_scores.end(), this->raw_scores.begin() );

}
//==================Calculations=================================
void Cadet::calculate_scores(){
	this->scores.resize(8);
	transform(
			this->raw_scores.begin(), this->raw_scores.end(),
			MAX_SCORES,
			this->scores.begin(),
			[]( double a, int b ){
				return (double) ( ( a / (double)b) * 100 ) ;

			});
}

//Simple table to refer to the grade which will be assigned after
//calculating the score from the raw scores.
//
void Cadet::calculate_grades(){
	this->grades.resize(8);
	transform(
			this->scores.begin(), this->scores.end(),
			this->grades.begin(),
			[]( double score ){
				if( score < 50 ) return "N";
				else if( score < 62 ) return "P";
				else if( score < 72 ) return "C";
				else if( score < 82 ) return "D";
				else return "HD";
			});
}

//Calculates the average score based on the score recieved from the raw score.
void Cadet::calculate_avg(){
	double sum = std::accumulate( this->scores.begin(), this->scores.end(), 0.0 );
	this->avg = sum / this->scores.size();
	auto get_grade = []( double score ){
				if( score < 50 ) return "N";
				else if( score < 62 ) return "P";
				else if( score < 72 ) return "C";
				else if( score < 82 ) return "D";
				else return "HD";
			};
	this->avggrade = get_grade( this->avg );
}
//Calculates the minimum and maximum
void Cadet::calculate_minmax(){
	auto minnmax = std::minmax_element( this->scores.begin(), this->scores.end() );
	this->gmin = round(*minnmax.first);
	this->gmax = round(*minnmax.second);
}
//Calculates the median score from all the scores.
void Cadet::calculate_median(){
	std::vector<double> scores( this->scores.size() );
	copy( this->scores.begin(), this->scores.end(),
		scores.begin()	);
	sort( scores.begin(), scores.end() );
	this->median = scores[ scores.size() / 2 ];

}
//===================================================================
