/**
 *
 * @file  	game_of_life.cpp
 * @author	Eshan Shafeeq
 * @version	v0.1
 * @date	2 May 2016
 *
 **/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <mutex>

class Board{

	std::mutex m_mutex;
	std::vector< std::string > board;
	int up;
	int down;
	int right;
	int left;

	public:
	Board(){

		this->up = 0;
		this->down=0;
		this->right=0;
		this->left=0;

	}
	void up_ext(){
		this->up++;
	}
	void down_ext(){
		this->down++;
	}
	void right_ext(){
		this->right++;
	}
	void left_ext(){
		this->left++;
	}
	void add_line( std::string line ){
		this->board.push_back( line );
	}
	void print_data(){
		for( int i =0 ;i<this->board.size(); i++ )
			std::cout << this->board[i] << std::endl;
		std::cout << std::endl;
	}
	int get_neighbours( int i, int j ){
		int n=0;

		if( i > 0 )
			if( this->board[i-1][j] == '*' ) n++;

		if( j > 0 )
			if( this->board[i][j-1] == '*' ) n++;

		if( i > 0 && j > 0 )
			if( this->board[i-1][j-1] == '*' ) n++;

		if( i < this->board.size()-1 )
			if( this->board[i+1][j] == '*' ) n++;

		if( j < this->board[i].length() )
			if( this->board[i][j+1] == '*' ) n++;

		if( i < this->board.size()-1 && j < this->board[i].length() )
			if( this->board[i+1][j+1] == '*' ) n++;

		if( i > 0 && j < this->board[i].length() )
			if( this->board[i-1][j+1] == '*' ) n++;
		if( i < this->board.size()-1 && j > 0 )
			if( this->board[i+1][j-1] == '*' ) n++;



		return n;
	}
	bool should_come_to_life( int i, int j, int n ){
		if( this->board[i][j] == '.' )
			if( n == 3 )
				return true;

		return false;
	}
	bool should_die_of_loneliness( int i, int j, int n ){
		if( this->board[i][j] == '*' )
			if( n < 2 )
				return true;
		return false;

	}
	bool should_die_of_overcrowding( int i, int j, int n ){
		if( this->board[i][j] == '*' )
			if( n > 3 )
				return true;
		return false;
	}
	void copy( std::vector<std::string> new_board  ){
		this->board = std::vector<std::string>();

		for( int i=0; i<new_board.size(); i++ )
			this->board.push_back(new_board[i]);
	}
	void process(){
		std::vector< std::string > new_board;

		for( int i=0; i<this->board.size(); i++ ){
			std::string new_line="";
			for( int j=0; j<this->board[i].length(); j++ ){
				int n = get_neighbours( i, j );

				if( should_die_of_loneliness( i, j, n ) )
					new_line += '.';
				else if( should_die_of_overcrowding( i, j, n ) )
					new_line += '.';
				else if( should_come_to_life( i, j, n ) )
					new_line += '*';
				else
					new_line += this->board[i][j];


			}


			new_board.push_back(new_line);

		}
		copy( new_board );
	}

};

int main( int argc, char * argv[] ){

	std::ifstream stream( argv[1] );
	std::string line;
	Board b;


	while( std::getline( stream, line ) ){
		b.add_line(line);

	}

	for( int i=0; i<10; i++ ){
		b.process();
	}
	b.print_data();
}
