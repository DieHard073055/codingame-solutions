#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define UKN "UNKNOWN"
/**
MIME types are used in numerous internet protocols to associate a media type (html, image, video ...) with the content sent. The MIME type is generally inferred from the extension of the file to be sent.
You have to write a program that makes it possible to detect the MIME type of a file based on its name.



You are provided with a table which associates MIME types to file extensions. You are also given a list of names of files to be transferred and for each one of these files, you must find the MIME type to be used.

The extension of a file is defined as the substring which follows the last occurrence, if any, of the dot character within the file name.
If the extension for a given file can be found in the association table (case insensitive, e.g. TXT is treated the same way as txt), then print the corresponding MIME type. If it is not possible to find the MIME type corresponding to a file, or if the file doesn’t have an extension, print UNKNOWN.

INPUT:
Line 1: Number N of elements which make up the association table.
Line 2: Number Q of file names to be analyzed.
N following lines : One file extension per line and the corresponding MIME type (separated by a blank space).
Q following lines : One file name per line.

OUTPUT:
For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.

CONSTRAINTS:
0 < N < 10000
0 < Q < 10000
File extensions are composed of a maximum of 10 alphanumerical ASCII characters.
MIME types are composed of a maximum 50 alphanumerical and punctuation ASCII characters.
File names are composed of a maximum of 256 alphanumerical ASCII characters and dots (full stops).
There are no spaces in the file names, extensions or MIME types.

EXAMPLE:
Input
2
4
html text/html
png image/png
test.html
noextension
portrait.png
doc.TXT
Output
text/html
UNKNOWN
image/png
UNKNOWN
**/



string TL(string &t){
  string out="";
  for (size_t i = 0; i < t.length(); i++) {
    out+=tolower(t[i]);
  }
  return out;
}


string get_mime(map<char, map<string, string> > table, string f){

    f=TL(f);//lower case the letters
    //cout << "filename : \n" << f << "|" << f.length() << "| " << endl;
    char letter = f[0];//the first letter of the search query
    map<char, map<string, string> > ::const_iterator tt = table.find(letter);

    if(tt != table.end()){
      map<string, string>::const_iterator t = tt->second.find(f);

      if(t != tt->second.end()){
        return t->second;
      }
    }
    return UKN;
}

int main()
{

    vector<string> results;
    map<char, map<string, string> > table;

    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();


        EXT = TL(EXT);

        map<string, string> t;
        t[EXT] = MT;
        table[EXT[0]] = t;

        //cout << "data : \n" <<  t.begin()->first << "|" << t.begin()->first.length()<< "| " <<  t.begin()->second <<  endl;

    }
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        int l = FNAME.length();
        for(int j=0;j<l;j++){
          if(FNAME[l-j] == '.'){
            if((l-j) < l){
              cout << get_mime(table, FNAME.substr((l-j)+1, l)) << endl;
              j=l;
            }
          }
          if(j == l-1){
            cout << UKN << endl;
          }
        }
    }
    //cout << get_mime(ext, mime, ext[0]) <<endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "UNKNOWN" << endl; // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}
