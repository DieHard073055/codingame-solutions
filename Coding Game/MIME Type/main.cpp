#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
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



#define UKN "UNKNOWN"
using namespace std;

int main()
{
    //map to store the reference table
    unordered_map<string, string> data;
    // Number of elements which make up the association table.
    int N; cin >> N; cin.ignore();
    // Number Q of file names to be analyzed.
    int Q; cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        //extension  mime type
        string EXT; string MT;
        cin >> EXT >> MT; cin.ignore();
        //convert to lower case
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        //add to the hash table
        data[EXT] = MT;

    }
    for (int i = 0; i < Q; i++) {
        //Get file to be processed
        string FNAME; getline(cin, FNAME);
        //Convert filename to lowercase
        transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);
        //check if the file has an extensnion
        unsigned j = FNAME.rfind('.'); if(j==-1)cout << UKN << endl;
        else{
          //Find the extension from the hash map
          unordered_map<string, string>::const_iterator t = data.find(FNAME.substr(j+1));
          if(t == data.end()){
            cout << UKN << endl;
          }else{
            //Found!
            cout << t->second << endl;
          }
        }
    }

}
