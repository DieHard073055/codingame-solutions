/**
 * @file		day4.cpp
 * @author		Eshan Shafeeq
 * @version 	v0.1
 * @date		28 May 2016
 * @brief		Challange day 4 - Hackerrank 30 day code challange
 **/

#include <iostream>

class Person{

	private:
		int age;
	public:
		Person( const int& initialAge ){
			if( initialAge >= 0 ){
				this->age = initialAge;
			}else{
				std::cout << "Age is not valid, setting age to 0."
					<< std::endl;
				this->age = 0;
			}
		}

		void yearPasses(){
			this->age++;
		}

		void amIOld() const{
			if( this->age < 13 )
				std::cout << "You are young." << std::endl;
			else if( this->age >= 13 && this->age < 18 )
				std::cout << "You are a teenager." << std::endl;
			else
				std::cout << "You are old." << std::endl;
		}

};

