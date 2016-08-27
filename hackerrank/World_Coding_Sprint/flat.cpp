#include <vector>
#include <iostream>
using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(n);
    for(int c_i = 0;c_i < m;c_i++){
        int x;
        cin >> x;
        c[x] = -1;
    }
    int dist = 1;
    for(int i=0;i<c.size();i++){
        if(c[i] == -1) dist = 0;
        if(c[i] != -1) c[i] = dist;
        dist++;
    }
    for(int i=c.size()-1;i>=0;i--){
        if(c[i] == -1) dist = 0;
        else if(c[i]>dist) c[i] = dist;
        dist++;
    }
    int max =0;
    for(int i=0;i<c.size();i++)
        if(c[i] > max) max =c[i];
    cout << max << endl;
    return 0;
}

