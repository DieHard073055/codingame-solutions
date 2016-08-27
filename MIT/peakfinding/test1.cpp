//Peak finding algorithm test

#include <iostream>
#include <vector>

using namespace std;


bool isPeak(vector<int> e, size_t i){
    bool pass_l = false;
    bool pass_r = false;
    if(i > 0){
        if(e[i] > e[i-1]){
            pass_l = true;
        }
    }else{
        pass_l = true;
    }
    if(i < e.size()-1){
        if(e[i] > e[i+1]){
            pass_r = true;
        }
    }else{
        pass_r = true;
    }
    if(pass_l && pass_r) return true;
    return false;
}
int main(){
    
    int size;
	int peaks =0;
    cin >> size;
    vector<int> e(size);

    for(size_t i=0;i<size;i++){
        cin >> e[i];
    }
    cout << endl << endl << endl;
    for(size_t i=0; i<size;i++){
        //cout << e[i];
        if(isPeak(e, i)) peaks++;// cout << "<" << endl;
        //else cout << endl;
    }
	cout << "peaks : " << peaks << endl;


    return 0;
}

