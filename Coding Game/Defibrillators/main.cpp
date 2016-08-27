#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;

#define NUM_SEMI 5

#define EARTH_RADIUS 6371


/*
The city of Montpellier has equipped its streets with defibrillators to help save victims of cardiac arrests. The data corresponding to the position of all defibrillators is available online.

Based on the data, you decide to write a program that will allow users to find the defibrillator nearest to their location using their mobile phone.



The input data you require for your program is provided in ASCII format.
Hint: Remember to turn the comma [,] into point [.], to use the data in your program.
This data is comprised of lines, each of which represents a defibrillator. Each defibrillator is represented by the following fields:
A number identifying the defibrillator
Name
Adress
Contact Phone number
Longitude (degrees)
Latitude (degrees)
These fields are separated by a semicolon ;

DISTANCE
The distance d between two points A and B will be calculated using the following formula:


​
Note: In this formula, the latitudes and longitudes are expressed in radians. 6371 corresponds to the radius of the earth in km.

The program will display the name of the defibrillator located the closest to the user’s position. This position is given as input to the program.

INPUT:
Line 1: User's longitude (in degrees)
Line 2: User's latitude (in degrees)
Line 3: The number N of defibrillators located in the streets of Montpellier
N lignes suivantes : N lines describing each defibrilator

OUTPUT:
The name of the defibrillator located the closest to the user’s position.

CONSTRAINTS :
0 < N < 10000

EXAMPLE :
Input
3,879483
43,608177
3
1;Maison de la Prevention Sante;6 rue Maguelone 340000 Montpellier;;3,87952263361082;43,6071285339217
2;Hotel de Ville;1 place Georges Freche 34267 Montpellier;;3,89652239197876;43,5987299452849
3;Zoo de Lunaret;50 avenue Agropolis 34090 Mtp;;3,87388031141133;43,6395872778854
Output
Maison de la Prevention Sante
*/
class Defibrillators{
private:
  int id;
  string name;
  string address;
  string phone;
  double lng;
  double lat;
  double distance;

  // find any character from the start till the end position
  int sfind(string s, char x, int start, int end){
    for (int i = start; i < end; i++) {
      if(s[i] == x){
        return i;
      }
    }
    return end;
  }
  // Get the sub string based from start to end variables
  string ssub(string s, int start, int end){
    string r = "";
    for (int i = start; i < end; i++) {
      r+=s[i];
    }
    return r;
  }
  //replace char x with char y in string s
  void sreplace(string &s, char x, char y){
    for (size_t i = 0; i < s.length(); i++) {
      if(s[i] == x) s[i] = y;
    }
  }

  //convert degrees to radians
  double degree_to_radians(double d){
    return (double)((double)d * ((double)M_PI / 180));
  }

public:
  //Constructors fot the class
  Defibrillators(){}
  Defibrillators(string d){
    int last = 0, curr = 0;
    vector<string> vdf;

    for (size_t i = 0; i <= NUM_SEMI; i++) {
      curr = sfind(d, ';', last, d.length());
      vdf.push_back(ssub(d, last, curr));
      last = curr+1;
    }

    set_id(vdf[0]);
    set_name(vdf[1]);
    set_address(vdf[2]);
    set_phone(vdf[3]);
    set_lng(vdf[4]);
    set_lat(vdf[5]);
  }

  /*
    I/O for the class
  */
  int get_id(){return id;}
  void set_id(int i_id){id = i_id;}
  void set_id(string i_id){istringstream(i_id) >> id;}
  string get_name(){return name;}
  void set_name(string i_name){name = i_name;}
  string get_address(){return address;}
  void set_address(string i_address){address = i_address;}
  string get_phone(){return phone;}
  void set_phone(string i_phone){phone = i_phone;}
  double get_lng(){return lng;}
  void set_distance(double d){distance=d;}
  double get_distance(){return distance;}

  void set_lng(string i_lng){
    sreplace(i_lng, ',', '.');
    istringstream(i_lng) >> lng;
    //lng = degree_to_radians(lng);
  }

  double get_lat(){return lat;}

  void set_lat(string i_lat){
    sreplace(i_lat,',', '.');
    istringstream(i_lat) >> lat;
    //lat = degree_to_radians(lat);
  }

  //Print all the data
  void print_data(){
    cout << get_id() << endl;
    cout << get_name() << endl;
    cout << get_address() << endl;
    cout << get_phone() << endl;
    cout << get_lng() << endl;
    cout << get_lat() << endl;
    cout << endl << endl;
  }
  //Print the calculated distance
  void print_distance(){cout<<distance<<endl;}
  //Calculate the distance between the given lng, lat.
  void calculate_distance(string ln, string la){
      double ulng, ulat;
      istringstream(ln) >> ulng;
      istringstream(la) >> ulat;

      ulng = degree_to_radians(ulng);
      ulat = degree_to_radians(ulat);

      /*
        The calculation for distance between 2 coordinates
        x = (ulng - lng) * (cos((lat + ulat) / 2);
        y = (ulat - lat);
        distance = root(pow(x,2) + pow(y,2)) * 6371

      */
      double x = (double)(lng - ulng) * (double)(cos((double)(ulat + lat) / 2));
      double y = (double)(lat - ulat);
      distance = sqrt((double)(x*x) + (double)(y*y)) * (double)EARTH_RADIUS;

      cout << "Ulng : " << ulng << endl;
      cout<< " ulat : " << ulat << endl;
      cout<< " lng : " << lng << endl;
      cout<< " lat : " << lat << endl;
      cout << "x : " << x << endl;
      cout<< " y: " << y << endl;
      cout<< " distance: " << distance << endl;
      cout << endl << endl;


  }
};
int main()
{
    string LON; cin >> LON; cin.ignore();
    string LAT; cin >> LAT; cin.ignore();
    int N; cin >> N; cin.ignore();

    //store all information
    vector<Defibrillators> debs;

    //collect all information
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        debs.push_back(Defibrillators(DEFIB));
    }

    double min = -1;
    int i_min;

    for (size_t i = 0; i < debs.size(); i++)
      debs[i].print_data();
    //calculate distance and find min
    for (size_t i = 0; i < debs.size(); i++) {

      debs[i].calculate_distance(LON, LAT);
      if(min == -1){
        min = debs[i].get_distance();
        i_min = i;
      }
      if(min > debs[i].get_distance()){
        min = debs[i].get_distance();
        i_min = i;
      }
      //debug
      //cout << debs[i].get_name() << " :\t" << debs[i].get_distance() << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << debs[i_min].get_name() << endl;
}
