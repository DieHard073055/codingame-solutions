#include <iostream>
#include <string>
using namespace std;

typedef enum days{SUN, MON, TUE, WED, THR, FRI, SAT} days;

inline days operator+(days d){
    return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

ostream& operator << (ostream& out, days d){
    switch(d){
        case SUN: out << "SUN" ; break;
        case MON: out << "MON" ; break;
        case TUE: out << "TUE" ; break;
        case WED: out << "SUN" ; break;
        case THR: out << "THR" ; break;
        case FRI: out << "FRI" ; break;
        case SAT: out << "SAT" ; break;
    }
    return out;
}
int main(void){
    string p = "yolo";
    days d = MON, e;
    e = +d;
    cout << d << '\t' << e << endl;
    return 0;
}
