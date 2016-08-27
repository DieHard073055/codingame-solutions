/*
Racing Horses

	Chef is very fond of horses. He enjoys watching them race. As expected, he has a stable full of horses. He, along with his friends, goes to his stable during the weekends to watch a few of these horses race. Chef wants his friends to enjoy the race and so he wants the race to be close. This can happen only if the horses are comparable on their skill i.e. the difference in their skills is less. There are N horses in the stable. The skill of the horse i is represented by an integer S[i]. The Chef needs to pick 2 horses for the race such that the difference in their skills is minimum. This way, he would be able to host a very interesting race. Your task is to help him do this and report the minimum difference that is possible between 2 horses in the race.

Input

First line of the input file contains a single integer T ≤ 10, the number of test cases. Every test case starts with a line containing the integer N ≤ 5000. The next line contains N space separated integers where the i-th integer is S[i] ≤ 1000000.

Output

For each test case, output a single line containing the minimum difference that is possible.

Sample Input

1
5
4 9 1 32 13
Sample Output

3

*/

#include <iostream>
#define UNSET 4231171

using namespace std;

void start(int test_case_num, int total_test_cases){
	/*Do the Coding*/
	int num_horses;
	cin >> num_horses;
	
	int horse_data[num_horses];
	int minimum = UNSET;
	
	for(int i=0;i<num_horses;i++){
		cin >> horse_data[i];
	}
	
	for(int i=0;i<num_horses;i++){
		for(int j=0;j<num_horses;j++){
			if(i!=j){
				//Initiating value for the minimum
				if(minimum == UNSET){
					minimum = horse_data[i] - horse_data[j];
					if(minimum < 0) minimum *= -1;
				}
				//Temp variable to hold the minimum difference
				int currentValue = horse_data[i] - horse_data[j];
				if(currentValue < 0) currentValue = horse_data[j] - horse_data[i];
				
				if(minimum > currentValue) minimum = currentValue;
					
			}
		}
	}
	cout << minimum << endl;
}

int main(void){
	
	/*Get the number of test cases*/
	int num_test_cases = 0;
	cin >> num_test_cases;
	
	/*Call the program in a for loop*/
	for(int i=0; i < num_test_cases; i++){
		start(i, num_test_cases);
	}
	
	return 0;
}
