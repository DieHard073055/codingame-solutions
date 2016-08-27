#include<iostream>
#include<vector>
#include<utility>

#define DIRTY_SPOT 'd'
using namespace std;

pair <int, int> find_dirty_spot(vector<string> stage){
    pair<int, int> dirty_spot(-1,-1);
    for(size_t i=0; i<stage.size();i++){
        for(size_t j=0;j<stage.size();j++){
            if(stage[i][j] == DIRTY_SPOT){
                dirty_spot.first = i;
                dirty_spot.second = j;
                return dirty_spot;
            }
        }
    }
    return dirty_spot;
}


void next_move(int posr, int posc, vector <string> board) {
    pair<int, int> bot(posr, posc);
    pair<int, int> dirty_spot = find_dirty_spot(board);
    if(board[bot.first][bot.second] == DIRTY_SPOT){
        cout << "CLEAN" << endl;
    }else if(bot.first > dirty_spot.first){
        //move up
        bot.first--;
        cout << "UP" << endl;
    }else if(bot.first < dirty_spot.first){
        //move down
        bot.first++;
        cout << "DOWN" << endl;
    }else if(bot.second > dirty_spot.second){
        //move left
        bot.second--;
        cout << "LEFT" << endl;
    }else if(bot.second < dirty_spot.second){
        //move right
        bot.second++;
        cout << "RIGHT" << endl;
    }

}
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
