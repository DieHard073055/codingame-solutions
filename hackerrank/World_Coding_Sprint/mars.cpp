#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    string data;
    string sample = "SOS";
    vector<string> messages;
    int diff = 0;

    cin >> data;

    for(int i=0;i<(data.length()/3);i++){
        messages.push_back(data.substr(i*3, 3));
    }
    for(int i=0;i<messages.size();i++){
        for(int j=0; j<sample.length(); j++){
            if(messages[i][j] != sample[j]) diff++;
        }
    }
    cout << diff << endl;

    return 0;
}
