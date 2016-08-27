#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

void reverse_words(string text){
    
    std::stringstream ss(text);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> words(begin, end);
    //copy(words.begin(), words.end(), ostream_iterator<string>(cout, "-"));
    for(size_t i=0;i<words.size();i++){
        cout << words[words.size()-1-i] << " ";
    }
    cout << endl;

}
int main(int argc, char * argv[]){

    string line;
    ifstream file (argv[1]);
    if(file.is_open()){
        while(getline(file, line)){
            reverse_words(line);
        }
        file.close();
    }else{
        cout << "lol" << endl;
    }
    return 0;
}
