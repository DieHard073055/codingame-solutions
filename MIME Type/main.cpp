#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#define UKN "UNKNOWN"
using namespace std;

string find(string ext, const unordered_map<string, string> data){

}
int main()
{
    unordered_map<string, string> data;
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        data[EXT] = MT;

    }
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        int l = FNAME.length();
        string ext;
        for(int j=0;j<l;j++){
          if(FNAME[l-j] == '.'){
            if((l-j) < l){
              ext = FNAME.substr((l-j)+1, l);
              //cerr << "main| ext : " << ext << endl;
              transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
              unordered_map<string, string>::const_iterator t = data.find(ext);
              if(t == data.end()){
                cout << UKN << endl;
              }else{
                cout << t->second << endl;
              }
              cout << find(ext, data) << endl;
              j=l;
            }
          }
          if(j == l-1){
            cout << UKN << endl;
          }
        }
    }


    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "UNKNOWN" << endl; // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}
