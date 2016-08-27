/**
 *
 * @file		Cadet.h
 * @author		Eshan Shafeeq
 * @version		v0.1
 * @date		19 June 2016
 * @brief		Cadet class to store the details about
 * 				the cadet scores.
 **/
#ifndef _CADET_H_
#define _CADET_H_

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>

class Cadet{

	//Constant to store the MAX SCORE for every subject
	static const int MAX_SCORES[];

	private:
		std::string 				name;
		std::vector<double>			raw_scores;
		std::vector<double>			scores;
		std::vector<std::string>	grades;
		double						avg;
		double						median;
		int							gmax;
		int							gmin;
		std::string					avggrade;


	public:

		//Constructor
		Cadet(){};
		void insert_data( std::string name, const std::vector<int>& raw_scores );
		//===============Getters=========================================
		inline std::string get_name(){	return this->name; }
		inline std::vector<double> get_rawscores(){ return this->raw_scores; }
		inline std::vector<double> get_scores(){ return this->scores; }
		inline std::vector<std::string> get_grades(){ return this->grades;	}
		inline double get_avg(){ return this->avg; }
		inline double get_median(){ return this->median;}
		inline int get_max(){ return this->gmax; }
		inline int get_min(){ return this->gmin; }
		inline std::string get_avggrade(){ return this->avggrade; }
		//================================================================
		//==================Calculations=================================
		void calculate_scores();
		void calculate_grades();
		void calculate_avg();
		void calculate_minmax();
		void calculate_median();
		//===================================================================
		//==================Stream Operators============================
		//Data formatting to be printed out to stdout
		//===========================================
		friend std::ostream& operator<< ( std::ostream& st, Cadet& s ){
			st << "Name : " << s.name << std::endl << "raw scores : ";
			for( const auto& i : s.get_rawscores() ){
				st.width(7);
				st << std::left << i << " ";
			}
			st << std::endl << "scores     : ";
			for( auto& i : s.get_scores() ){
				st.width(7);
				st.precision(4);
				st << i << " ";
			}
			st << std::endl << "grades     : ";
			for( auto& g : s.get_grades() ){
				st.width(7);
				st << g << " ";
			}
			st << std::endl
				<< "\t\t\t--------------------------------"
				<< std::endl;
			st << "AVG : " << s.get_avg() << " | " << s.get_avggrade()
				<< " \tMAX : " << s.get_max()
				<< "\tMIN : " << s.get_min()
				<< "\tMEDIAN : " << s.get_median();
			st << std::endl;

		}
		friend std::istream& operator>>( std::istream& st, Cadet& s ){
			std::vector<int> raw_scores;
			std::string name;

			st >> name;
			for( int i=0; i<8; i++ ){
				int score;
				st >> score;
				raw_scores.push_back( score );
			}
			s.insert_data( name, raw_scores );

			return st;

		}
		//==============================================================
};
#endif
