/*

	How to reverse a string
	in c++

*/


#include <iostream>
#include <string>


using namespace std;

//Function Prototype
string reverse(string input);

int main(void){

	//Declare Variable to Store User Input
	string text;
	//Get user input
	getline(cin, text);
	//Print the output from the reverse function
	cout << "Output : " << reverse(text) << endl;
	


	return 0;
}
//Function to reverse the string
string reverse(string input){
	//Declare the output varible to hold
	//the reverse string
	string output="";
	//for loop to iterate through the input string
	for(int i=0; i<input.length();i++){
		//Insert the new letter to the front
		output = input[i] + output;
	}
	//return the reversed output.
	return output;

}
