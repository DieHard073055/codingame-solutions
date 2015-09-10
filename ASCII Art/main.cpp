#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**

In stations and airports you often see this type of screen. Have you ever asked yourself how it might be possible to simulate this display on a good old terminal? We have: with ASCII art!

ASCII art allows you to represent forms by using characters. To be precise, in our case, these forms are words. For example, the word "MANHATTAN" could be displayed as follows in ASCII art:
# #  #  ### # #  #  ### ###  #  ###
### # # # # # # # #  #   #  # # # #
### ### # # ### ###  #   #  ### # #
# # # # # # # # # #  #   #  # # # #
# # # # # # # # # #  #   #  # # # #

​Your mission is to write a program that can display a line of text in ASCII art.

INPUT:
Line 1: the width L of a letter represented in ASCII art. All letters are the same width.
Line 2: the height H of a letter represented in ASCII art. All letters are the same height.
Line 3: The line of text T, composed of N ASCII characters.
Following Lines: the string of characters ABCDEFGHIJKLMNOPQRSTUVWXYZ? Represented in ASCII art.

OUTPUT:
The text T in ASCII art.
The characters a to z are shown in ASCII art by their equivalent in upper case.
The characters which are not in the intervals [a-z] or [A-Z] will be shown as a question mark in ASCII art.

CONSTRAINTS :
0 < L < 30
0 < H < 30
0 < N < 200

EXAMPLE 1 :
Input
4
5
E
 #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ###  # # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   #  ### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ##  # # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #        # # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #
Output
###
#
##
#
###

EXAMPLE 2 :
Input
4
5
MANHATTAN
 #  ##   ## ##  ### ###  ## # # ###  ## # # #   # # ###  #  ##   #  ##   ## ### # # # # # # # # # # ### ###  # # # # #   # # #   #   #   # #  #    # # # #   ### # # # # # # # # # # #    #  # # # # # # # # # #   #   #  ### ##  #   # # ##  ##  # # ###  #    # ##  #   ### # # # # ##  # # ##   #   #  # # # # ###  #   #   #   ##  # # # # #   # # #   #   # # # #  #  # # # # #   # # # # # # #    ## # #   #  #  # # # # ### # #  #  #        # # ##   ## ##  ### #    ## # # ###  #  # # ### # # # #  #  #     # # # ##   #  ###  #  # # # #  #  ###  #
Output
# #  #  ### # #  #  ### ###  #  ###  ### # # # # # # # #  #   #  # # # #  ### ### # # ### ###  #   #  ### # #  # # # # # # # # # #  #   #  # # # #  # # # # # # # # # #  #   #  # # # # **/

 vector<string> raw_data;
 vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 string text;

//Get the position of the letters
vector<int> convert_text_to_int(string t){
  vector<int> tex;
  for (size_t i = 0; i < t.length(); i++) {
    char y = toupper(t[i]);
    if(find(alphabet.begin(), alphabet.end(), y)!= alphabet.end()){
      int j = distance(alphabet.begin(), find(alphabet.begin(), alphabet.end(), y));
      tex.push_back(j);
    }else{
      tex.push_back(alphabet.size());
    }
  }
  return tex;
}
//Debugging print letter
void print_letter(int u, int L, int H){
  int filterd_u = ((u*L)-L);
  for(int j=0;j<H;j++){
    for(int i=filterd_u;i<filterd_u+(L); i++){
        cout << raw_data[j][i];
    }
    cout << endl;
  }
}
//Get a specific letter from the raw data
vector<vector<char> > get_letter(int u, int L, int H){
  vector<vector<char> > out (H, vector<char>(L));

  int filterd_u = ((u*L)-L);

  for(int j=0;j<H;j++){
    for(int i=filterd_u;i<filterd_u+(L); i++){
        out[j][i-filterd_u] = raw_data[j][i];
    }
  }
  return out;
}
int main()
{
    //Length and Height of the letters
    int L; cin >> L; cin.ignore();
    int H; cin >> H; cin.ignore();
    getline(cin, text);
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        raw_data.push_back(ROW);
    }

    //Vector to store the output
    vector<vector<char> > out(H);
    vector<int> list = convert_text_to_int(text);

    //Fill up the out vector with the data to be pushed out
    for(int k=0;k<text.length();k++){

      vector<vector<char> > data = get_letter(list[k]+1, L, H);
      int filterd_k = ((k*L)-L);


      for(int j=0;j<H;j++){
        for(int i=0;i<L;i++){
          out[j].push_back(data[j][i]);
        }
      }
    }
    //Print out the out vector
    for(int j=0;j<out.size();j++){
      for(int i=0;i<out[j].size();i++){
        cout << out[j][i];
      }
      cout << endl;
    }

    return 0;
}
