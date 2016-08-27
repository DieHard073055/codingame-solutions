#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define UP      0
#define DOWN    1
#define RIGHT   2
#define LEFT    3

using namespace std;

int count;
bool not_done(vector<string> stage){
    if(count ==40) return false;
    count++;
    for(size_t i=0;i<stage.size();i++){
        for(size_t j=0;j<stage[i].length();j++){
            if(stage[i][j] == '-')
                return true;
        }
    }
    return false;
}
int get_optimized_number(int y){
    return (y * 3) + 1;
}
int check_which_dir(int y){
    int odd_y;
    bool move_right = true;

    if(y == 0) return DOWN;
    else if((y%3) != 1){
        return UP;
    }
    else{
        odd_y = y/3;
        if(odd_y % 2) return LEFT;
        else return RIGHT;
    }
}
int get_last_horizontal_dir(int y){
    int odd_y;
    bool move_right = true;
    if(y==0)return RIGHT;

    while((y % 3) != 1){y--;}
    odd_y = y/3;

    if(odd_y % 2) return LEFT;
    else return RIGHT;

}
void deb(string i){
    cout <<"DEBUG : "<< i << endl;
}
void print_dir(int d){
    switch(d){
        case UP:
            cout << "UP" << endl;
            break;
        case DOWN:
            cout << "DOWN" << endl;
            break;
        case LEFT:
            cout << "LEFT" << endl;
            break;
        case RIGHT:
            cout << "RIGHT" << endl;
            break;
    }
}
vector<string> generate_search_path(int h, int w, int b1, int b2){
    pair<int, int> bot(b1, b2);
    vector<string> stage;
    for(size_t i=0;i<h;i++){
        string s = "";
        for(size_t j=0;j<w;j++){
            s+='-';
        }
        stage.push_back(s);
    }
    count = 0;
    while(not_done(stage)){
        int dir = check_which_dir(bot.first);
        cout << "init dir : ";
        print_dir(dir);

        // DEFINE THE X EDGES
       
        if(bot.second == 0 || bot.second == w-1){
            if(bot.first == 1){
                if(bot.second == w-1) dir = LEFT; 
            }else if(bot.first == 0){
                dir = DOWN;
            }else{
                dir = UP;
            }
        }else if(bot.second == 1){
            if(bot.first == h-2){
                int last_dir = get_last_horizontal_dir(bot.first-1);
                cout << "last : " ;
                print_dir(last_dir);
                if(last_dir == RIGHT){
                    dir = LEFT;
                }else{
                    dir = RIGHT;
                }
            }else if(bot.first == h-1){
                int last_dir = get_last_horizontal_dir(bot.first-1);
                cout << "last : " ;
                print_dir(last_dir);
                if(last_dir == RIGHT){
                    dir = LEFT;
                }else{
                    dir = RIGHT;
                }
    
            }else{

                int this_level_dir = get_last_horizontal_dir(bot.first);
                if(LEFT == this_level_dir)
                    dir = DOWN;
            }

        }else if(bot.second == w-2){
            if(bot.first == h-2){
                int last_dir = get_last_horizontal_dir(bot.first-1);
                cout << "last : " ;
                print_dir(last_dir);
                if(last_dir == RIGHT){
                    dir = LEFT;
                }else{
                    dir = RIGHT;
                }
            }else if(bot.first == h-1){
                int last_dir = get_last_horizontal_dir(bot.first-1);
                cout << "last : " ;
                print_dir(last_dir);
                if(last_dir == RIGHT){
                    dir = LEFT;
                }else{
                    dir = RIGHT;
                }
    
            }else{
                int this_level_dir = get_last_horizontal_dir(bot.first);
                if(RIGHT == this_level_dir)
                    dir = DOWN;
            }

        }else if(bot.first >= h-2){
            int last_dir = get_last_horizontal_dir(bot.first-1);
            cout << "last : " ;
            print_dir(last_dir);
            if(last_dir == RIGHT){
                dir = LEFT;
            }else{
                dir = RIGHT;
            }
    
        }

        cout << "after init : " ;
        print_dir(dir);
        if(dir == RIGHT){
            stage[bot.first][bot.second] = '>';
            bot.second++;
            cout << "RIGHT" << endl;
        }else if(dir == UP){
            stage[bot.first][bot.second] = '^';
            bot.first--;
            cout << "UP" << endl;
        }else if(dir == LEFT){
            stage[bot.first][bot.second] = '<';
            bot.second--;
            cout << "LEFT" << endl;
        }else if(dir == DOWN){
            stage[bot.first][bot.second] = 'v';
            bot.first++;
            cout << "DOWN" << endl;
        }
        cout << "\t  ";
        for(size_t i=0;i<w;i++) cout << i << " ";
        cout << endl;
        for(size_t i=0;i<h;i++){
            cout << i << "\t: " ;
            for(size_t j=0; j<stage[i].length();j++)
                cout << stage[i][j] << " ";
            cout << endl;
        }
    }

    return stage;
}

int main(){
    
    int height, width, b1, b2;
    cin >> height >> width >> b1 >> b2;
    
    vector<string> stage = generate_search_path(height, width, b1, b2);
    
        
    return 0;
}
