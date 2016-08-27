#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int fib(int num){
    if(num == 1 || num == 0) return num;
    else if(num > 1)
        return fib(num-1) + fib(num-2);
    else
        return -1;
    
}

int main(int argc, char * argv[]){
    string line;
    ifstream file (argv[1]);
    if(file.is_open()){
        while(getline(file, line)){
            //run your code
            cout << line << endl;
            istringstream ss(line);
            int num;
            ss >> num;
            cout << "fib : " << fib(num) << endl << endl;
        }
    }else{
        cout << "lol" <<endl;
    }
    return 0;
}
