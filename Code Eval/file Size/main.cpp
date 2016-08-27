#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
    char* filename = argv[1];
    
    streampos begin, end;
    ifstream file (filename, ios::binary);

    begin = file.tellg();
    file.seekg(0, ios::end);
    end = file.tellg();

    file.close();
    
    cout << "filename : " << filename << endl << endl;
    cout <<  "file size : " << (end-begin) << " bytes." << endl;

    

    return 0;
}
