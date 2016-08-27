#include <iostream>

using namespace std;

//Recursive Method to calculate the 
//factorial of any given number
//if the given number is greater then 1
//then multiply the the number with the 
//factorial() of the number - 1
int factorial(int num){
	if(num > 1){
		return num * factorial(num-1);
	}else{
		return num;
	}
}
/*
	Main method
	
	Get user_input which is the number to find the factorial for.
	then calculate the factorial for that number.
	Then display the answer.
*/
int main(void){

	int user_input;

	cout << "Calculating the factorial of any given Number" << endl;
	cout << endl << "Please Enter the number : " ;
	cin >> user_input;

	int num = user_input;

	num = factorial(num);
	
	cout << endl << endl << "The factorial of " << user_input << " is " << num << endl;
		


}
