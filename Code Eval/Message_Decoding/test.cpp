





#include <iostream>
#include <string>
#include <vector>

#define ENTROPY '1'
#define NUMBITS 4


bool bfs_step( std::string& data, bool& restart, int num ){

	bool finished = true;
	int d;

	for( int i=0;i<num;i++ ){
		if( data[i] != ENTROPY ) finished = false;

	}
	if( finished ){
		restart = false;
		return true;
	}

	d = data.length()-1;

	if( restart ){
		data[d] = '1';
	}else{
		restart = true;
	}

	std::cout << data << std::endl;

	if( data[d] == ENTROPY ){
		for( int i=0; i<data.length(); i++ ){
			if( data[data.length()-1-i] != ENTROPY ){
				int selected = data.length()-1-i;
				data[selected]=ENTROPY;
				selected+=1;

				while( selected != data.length()-1 ){
					data[selected]='0';
					selected+=1;
				}

				restart = false;
				return false;
			}
		}
	}



}
void bfs( int num, std::vector< std::string> all_data ){

	std::string data="";
	bool x = false;
	bool restart = false;

	for( int i=0; i<num; i++ ){
		data+="0";
	}

	while( x == false ){
		x = bfs_step( data, restart, num );
	}

}
int main( void ){

	std::vector< std::string > all_data;

	bfs( NUMBITS, all_data );



	return 0;
}
