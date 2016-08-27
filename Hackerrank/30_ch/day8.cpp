/**
 *
 * @file		day*.cpp
 * @author		Eshan Shafeeq
 * @version		v0.1
 * @date		28 May 2016
 * @brief		Phone book challange
 *
 **/


#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    unordered_map< string, long > pb;
    int q;

	cin >> q;
    pb.reserve(q);
    string line;
    getline( cin, line );

    for( int i=0; i<q; i++){
        getline( cin, line );
        string buf; // Have a buffer string
        stringstream ss(line); // Insert the string into a stream

        vector<string> tokens; // Create vector to hold our words

        while (ss >> buf)
            tokens.push_back(buf);

        string::size_type sz;


        pb.insert( make_pair(tokens[0], stol(tokens[1], &sz) ));
    }
    for( int i=0; i<q; i++){
        getline( cin, line );
        unordered_map< string, long >::const_iterator it = pb.find( line );
        if( it != pb.end() ){
            cout << line << "=" << it->second << endl;
        }else{
            cout << "Not found" << endl;
        }
    }

    return 0;
}
