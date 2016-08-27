#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <algorithm>
#include <regex>



using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 string trim(string& str){
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}
string get_urinary(vector<bitset<7>> arr){
  string result="";
  bool zero = false;
  for(int i=0;i<arr.size();i++){
    for(int j=arr[i].size()-1;j> -1;j--){
      if(arr[i][j]){
        if(!zero){
          if(result == ""){
            //cout << j << " : " << arr[i][j] <<" result empty but 1" << endl;
            result = "0 0";
          }else{
            //cout <<  j << " : " << arr[i][j] << " append 1 " << endl;
            result += "0";
          }
        }else{
          //cout <<  j << " : " << arr[i][j] <<" switch to 1 " << endl;
          result += " 0 0";
          zero = !zero;
        }
      }else{
        if(zero){
          if(result == ""){
            //cout <<  j << " : " << arr[i][j] <<" result empty but 0" << endl;
            result = "00 0";
          }else{
            //cout <<  j << " : " << arr[i][j] <<" append 0" << endl;
            result += "0";
          }
        }else{
          //cout <<  j << " : " << arr[i][j] <<" switch to 0" << endl;
          result += " 00 0";
          zero = !zero;
        }
      }
    }
  }

  return trim(result);
}
int main()
{
    string MESSAGE; //Store the message to convert
    vector<bitset<7>> byte_array; //Store the Byte vector of the message
    getline(cin, MESSAGE);


    //Convert the message to the byte vector
    for(int i=0; i<MESSAGE.length();i++){
      bitset<7> b(MESSAGE[i]);
      byte_array.push_back(b);
      //cout << b << endl;
    }

    cout << get_urinary(byte_array) << endl;
}
