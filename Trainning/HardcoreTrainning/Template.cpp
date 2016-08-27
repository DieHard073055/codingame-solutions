#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#define DEBUGGING
#define TESTCASE
#define WHILECASE
#define USEFUL

using namespace std;

// Debugging
void print_d(string d){
#ifdef DEBUGGING
    cout << d << endl;
#endif
}

// Useful functions
#ifdef USEFUL
string toString(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int toNum(string s)
{
    stringstream ss(s);
    int i;
    ss >> i;
    return i;
}
#endif

void start(int test_case_num, int total_test_cases)
{
}

int main(void)
{
#ifdef TESTCASE
    int num_test_cases = 0;
    cin >> num_test_cases;
    for(int i = 0; i < num_test_cases; i++)
    {
        start(i, num_test_cases);
    }
#else
#ifdef WHILECASE
    int while_num_case = 0;
    while (1)
    {
        start(while_num_case, 1);
        while_num_case++;
    }
#else
    start(0, 1);
#endif
#endif
        return 0;
}
