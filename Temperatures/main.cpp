#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
Statement
In this exercise, you have to analyze records of temperature to find the closest to zero.


Sample temperatures. Here, -1 is the closest to 0.

Write a program that prints the temperature closest to 0 among input data.

INPUT:
Line 1: N, the number of temperatures to analyse
Line 2: The N temperatures expressed as integers ranging from -273 to 5526

OUTPUT:
Display 0 (zero) if no temperature is provided
Otherwise, display the temperature closest to 0, knowing that if two numbers are equally close to zero, positive integer has to be considered closest to zero (for instance, if the temperatures are -5 to 5, then display 5)

CONSTRAINTS:
0 ≤ N < 10000

EXAMPLE:
Input
5
1 -2 -8 4 5
 **/
int main()
{
    int min=-274, m_min;
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    for(int i=0;i<N;i++){
        int temp, ttemp;
        cin >> temp;
        cerr << temp << endl;
        ttemp = temp;
        if(temp < 0) {temp *= -1; temp++;}
        if(min == -274){ min = temp; m_min = ttemp;}
        if(temp < min){ min = temp; m_min = ttemp;}
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if(min == -274) { min =0; m_min = 0;}
    cout << m_min << endl;
}
