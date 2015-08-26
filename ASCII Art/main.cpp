#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 vector<string> raw_data;
 vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 string text;

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

void print_letter(int u, int L, int H){
  int filterd_u = ((u*L)-L);
  for(int j=0;j<H;j++){
    for(int i=filterd_u;i<filterd_u+(L); i++){
        cout << raw_data[j][i];
    }
    cout << endl;
  }
}
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
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    getline(cin, text);
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        raw_data.push_back(ROW);
    }

    vector<vector<char> > out(H);
    vector<int> list = convert_text_to_int(text);

    for(int k=0;k<text.length();k++){

      vector<vector<char> > data = get_letter(list[k]+1, L, H);
      int filterd_k = ((k*L)-L);


      for(int j=0;j<H;j++){
        for(int i=0;i<L;i++){
          //out[j][i+filterd_k] = data[j][i];
          out[j].push_back(data[j][i]);
        }
      }
    }
    //for(int i=0;i<list.size();i++)cout << list[i] << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    for(int j=0;j<out.size();j++){
      for(int i=0;i<out[j].size();i++){
        cout << out[j][i];
      }
      cout << endl;
    }

    return 0;
}
