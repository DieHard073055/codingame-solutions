#include <iostream>
#include <string>

#define DEBUGGING 1
#define TESTCASE 1

using namespace std;

/*Debug output functions*/
void print_d(string d);
void printn_d(string d);

void start(int test_case_num, int total_test_cases){





}

int main(void){

	/*Get the number of test cases*/
	int num_test_cases = 0;
	if(TESTCASE == 1)
	{
		cin >> num_test_cases;
		for(int i=0; i<num_test_cases; i++)
		{
			start(i, num_test_cases);
		}
	}else{
	/*Incase no test cases*/
		start(0,1);
	}
	return 0;
}


/*debug output functions */
void print_d(string d){

	if(DEBUGGING == 1){
		cout << d;	
	}
}
void printn_d(string d){

	if(DEBUGGING == 1){
		cout << d << endl;
	}
}
