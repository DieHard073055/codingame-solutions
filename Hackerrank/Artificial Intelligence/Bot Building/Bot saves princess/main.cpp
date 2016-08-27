#include <iostream>
#include <vector>
#include <utility>

#define PRINCESS    'p'
#define MARIO       'm'

using namespace std;

pair <int, int> find_mario(vector<string> stage){
    pair<int, int> mario(-1,-1);
    for(size_t i=0; i<stage.size();i++){
        for(size_t j=0;j<stage.size();j++){
            if(stage[i][j] == PRINCESS){
                mario.first = i;
                mario.second = j;
                return mario;
            }
        }
    }
    return mario;
}
pair <int, int> find_princess(vector<string> stage){
    pair<int, int> princess(-1,-1);
    for(size_t i=0; i<stage.size();i++){
        for(size_t j=0;j<stage.size();j++){
            if(stage[i][j] == PRINCESS){
                princess.first = i;
                princess.second = j;
                return princess;
            }
        }
    }
    return princess;
}
bool done(pair<int, int> m, pair<int, int> p){
    if(m.first == p.first && m.second == p.second)
        return false;
    return true;
}

void save_princess(vector<string> stage){
    pair<int, int> princess = find_princess(stage);
    pair<int, int> mario((stage.size()-1)/2, (stage.size()-1)/2);
    
    if(stage[(stage.size()-1)/2][(stage.size()-1)/2] != 'm'){
        mario = find_mario(stage);
    }

    //cout << princess.first << " " << princess.second << endl;

    while(done(mario, princess)){
        if(mario.first > princess.first){
            //move up
            mario.first--;
            cout << "UP" << endl;
        }else if(mario.first < princess.first){
            //move down
            mario.first++;
            cout << "DOWN" << endl;
        }else if(mario.second > princess.second){
            //move left
            mario.second--;
            cout << "LEFT" << endl;
        }else if(mario.second < princess.second){
            //move right
            mario.second++;
            cout << "RIGHT" << endl;
        }
    }
}

int main(){

    int mat_size;
    vector<string> stage;
    
    cin >> mat_size;
    for(size_t i=0;i<mat_size;i++){
        string line;
        cin >> line;
        stage.push_back(line);
    }

   // for(size_t i=0;i<mat_size;i++){
   //     cout << stage[i] << endl;
   // }
    save_princess(stage);

    return 0;
}
