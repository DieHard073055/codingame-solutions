#include <iostream>
/*
	Pyramid.cpp
	-This program will take 2 parameters
	-A character and an integer
	-Integer decides the height of the pyramid
	-The character will the bricks used to build the pyramid

*/
using namespace std;
void pyramid(char x, int y){

	for(int i = 0; i < y; i++){
		for(int j=i; j<y; j++)	cout << " " ;
		for(int j=i+1; j>0;j--) cout << x ;
		for(int j=i; j>0; j--) cout << x;
		cout << endl;
	}


}
int main(void){

	cout << "Welcome to the pyramid builder" << endl << endl;
	cout << "Please type a character you want to " << endl;
	cout << "use as a brick." << endl;
	cout << "Brick: " ;
	
	char x;
	cin >> x;
	
	cout << "Please enter the size of the pyramid" << endl;
	cout << "Size : " ;
	
	int y;
	cin >> y;

	cout << endl << endl << endl;
	pyramid(x,y);	
	cout << endl << endl;

	return 0;

}
