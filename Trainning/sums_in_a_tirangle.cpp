/*
	Calculating the max way to bottom of the triangle
	only can go down and down right.
	
	Input format : 
	No. of test cases
		
		Size of Triangle
			
			Values for the triangle ( x size of triangle)

	eg: 	2
		3
		1
		2 1
		1 2 3
		4
		1
		1 2
		4 1 2
		2 3 1 1

	Output:
		5
		9

	

*/

#include <iostream>  // std:: cin / cout
#include <algorithm> // std:: max
//To output extra data for debugging
// Enable Debugging = 1
// Disable Debugging = 0

#define DEBUGGING 0

using namespace std;
/*
	Depth first search algorithm goes through the whole "tree" (triangle)
	and then on the way back to the start node finds the maximum on the 
	triangle.
*/
int findMax(int** triangle, int y, int x, int level){
	/*
	int node_1_result : To store the sum from the node directly below
	int node_2_result : To store the sum from the node bottom right of the current one
	*/
	int node_1_result = triangle[y][x], node_2_result = triangle[y][x];
	
	if(DEBUGGING)cout << "current node : " << node_1_result << " | " ;
	if(DEBUGGING)cout <<" y : " <<  y << " x : " << x << endl;
	
	//Preventing the cursor from going out side the y-axis of the triangle	
	if(y < (level -1)){

		//Entering the first connected node of the triangle
		if(DEBUGGING)cout << node_1_result << " -Node 1--> "<< endl;
		node_1_result +=  findMax(triangle, y+1, x, level);
		
		//Preventing the cursor from going out side the x-axis of the triangle		
		if(x < (level -1)){
			
			//Entering the second connected node of the triangle
			if(DEBUGGING)cout << node_2_result << " -Node 2-->" << endl;
			node_2_result +=  findMax(triangle, y+1, x+1, level);
		}
	}
	//Return the result with the maximum value
	return max(node_1_result, node_2_result);
	
}
/*
	Main method in the program
*/	
void start(int test_case_num, int total_test_cases){
/*	
	2D array to hold the values of the triangle

	1
	2 3
	4 5 6
	7 8 9 10		
*/
	int** triangle;

//	To define the size of the triangle	
	int level;

//	Let the user define the triangle size	
	cin >> level;
	
//	Dynamic Memory Allocation for the triangle
//	Allocates Memory in a triangle manner	
	triangle = (int**) malloc(level * sizeof(int**));
	for(int i=0;i<level;i++) triangle[i] = (int*) malloc(i+1 * sizeof(int*));

//	The second loop x < y+1 to construct the memory in a triangle manner	
	for(int y=0;y<level;y++)for(int x=0;x<y+1;x++){
		cin >> triangle[y][x];
	}

//	Call the findMax algorithm function and print out the answer	
	if(DEBUGGING)cout << "Max : " << findMax(triangle, 0, 0, level) << endl;
	else cout << findMax(triangle, 0, 0, level) << endl;

	//Destroy the triangle
	for(int y=0;y<level;y++)free(triangle[y]);free(triangle);
	
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
