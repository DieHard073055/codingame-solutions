//https://www.codeeval.com/browse/230/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

vector<string> split(string in){
    stringstream data(in);
    istream_iterator<string> start(data);
    istream_iterator<string> end;
    vector<string> out(start, end);
    return out;
}
int to_int(string text){
    int num;
    stringstream str(text);
    str>>num;
    return num;
}
void process_countries(string list){
    int start=0;
    vector<vector<int> > segments;

    vector<string> data = split(list);
    vector<int> seg;
    for(int i=0;i<data.size();i++){
        if(data[i] == "|"){
            segments.push_back(seg);
            seg.clear();
        }else{
            seg.push_back(to_int(data[i]));
        }
    } 
    segments.push_back(seg);

    segments.push_back(seg);
    for(size_t i=0;i<segments.size();i++){
        for(size_t j=0;j<segments[i].size();j++){
            cout << segments[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char * argv[]){
    string line;
    ifstream file(argv[1]);
    if(file.is_open()){
        while(getline(file, line)){
            //run your code
            cout << line << endl;
            process_countries(line);
        }
    }else{
        cout << "lol" <<endl;
    }
    return 0;
}
