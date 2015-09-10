#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>

#define WALL        '#'
#define UNKNOWN     '?'
#define CTRLROOM    'C'
#define STARTPOINT  'T'
#define EMPTY       '.'

#define GOAL_FOUND 10

using namespace std;
/*###########START COORDINATE CLASS############*/
//Coordinate Class to take care of the coordinate system
class Coordinate{
private:
  int x;
  int y;
  int px;
  int py;

public:
  Coordinate(int ix, int iy): x(ix), y(iy){}
  Coordinate(int ix, int iy, int iix, int iiy): x(ix), y(iy), px(iix), py(iiy){}
  void setX(int num){x=num;}
  void setY(int num){y=num;}
  int getX(){return x;}
  int getY(){return y;}
  int getPX(){return px;}
  int getPY(){return py;}
};
/*###########END COORDINATE CLASS############*/

/*###########START NAVIGATION GUIDANCE CLASS############*/
class NavigationGuidance{
#define UNSET   0
#define EXPLORE 1
#define MANUAL  2

private:
  int map_width;
  int map_height;
  int MODE;
  int startx; int starty;
  vector<Coordinate> route;
  vector<string> map;

  //dfs
  vector<Coordinate> dfs_stack;
  vector<Coordinate> dfs_visited;

  bool dfs_has_visited(int x, int y);
  void print_on_map(Coordinate c, char d);

public:
  NavigationGuidance();
  void setMap(int sx, int sy, vector<string> unprocessedMap);
  void setMode(const int mode);
  int getDirectionsTo(char destination);
  int dfs(Coordinate node, char d);


};

NavigationGuidance::NavigationGuidance(){
  map_width=0;
  map_height=0;
  MODE=UNSET;
}

void NavigationGuidance::setMap(int sx, int sy, vector<string> m){
  map_width = sx; map_height = sy;
  map = m;
}

void NavigationGuidance::setMode(const int mode){
  MODE = mode;
}

int NavigationGuidance::getDirectionsTo(char destination){
  dfs_stack.clear();
  dfs_visited.clear();
  startx = 6;starty = 3;
  if(MODE == EXPLORE){
    //depth first search
    dfs(Coordinate(startx,starty), destination);
  }else if(MODE == MANUAL){
    //A star search

  }
}

int NavigationGuidance::dfs(Coordinate node, char d){
    int x = node.getX(); int y=node.getY();
    dfs_visited.push_back(Coordinate(x,y));
    cout << "x : " << x << " y : " << y << endl;
    //check if the current node is the goal node
    if(map[y][x] == d){
      print_on_map(Coordinate(x,y), 'X');
      return GOAL_FOUND;
    }else{
      //get all the adjacent nodes
      //filter the ones that is expandable
      //add them to the stack
      //call dfs and pass the coordinate poped from the stack
      if(y > 0) if(map[y-1][x] != WALL && !dfs_has_visited(x,y-1)) dfs_stack.push_back(Coordinate(x,y-1,x,y));
      if(x > 0) if(map[y][x-1] != WALL && !dfs_has_visited(x-1,y)) dfs_stack.push_back(Coordinate(x-1,y,x,y));
      if(y < map_height) if(map[y+1][x] != WALL && !dfs_has_visited(x,y+1)) dfs_stack.push_back(Coordinate(x,y+1,x,y));
      if(x < map_width) if(map[y][x+1] != WALL && !dfs_has_visited(x+1,y)) dfs_stack.push_back(Coordinate(x+1,y,x,y));
    }

    if(!dfs_stack.empty()){
      node = dfs_stack[dfs_stack.size()-1];
      dfs_stack.pop_back();
      int result = dfs(node, d);
      if(result == GOAL_FOUND){
        if(startx==node.getPX() && starty==node.getPY()){print_on_map(Coordinate(node.getPX(),node.getPY()), 'X');return 0;}
        print_on_map(Coordinate(x,y), 'X');
        return result;
      }

    }


}
void NavigationGuidance::print_on_map(Coordinate c, char d){
  cout << "------------------------------------" << endl;
  for(int i=0;i<map_height;i++){
    for(int j=0;j<map_width;j++){
      if(i == c.getY() && j == c.getX())
        cout << d;
      else
        cout << map[i][j];
    }
    cout << endl;
  }
}





bool check_coordinate (Coordinate c1, Coordinate c2) {
  return (c1.getX()==c2.getX()) & (c1.getY()==c2.getY());
}

bool NavigationGuidance::dfs_has_visited(int x, int y){
    vector<Coordinate>::iterator it;
    Coordinate i[] = {Coordinate(x,y)};
    it =search (dfs_visited.begin(), dfs_visited.end(), i, i+1, check_coordinate);
    if(it != dfs_visited.end()){
      return true;
    }
    return false;
}
/*###########END NAVIGATION GUIDANCE CLASS############*/
int main(){
  vector<string> map_data;
  map_data.push_back("??????????????????????????????");
  map_data.push_back("????......................????");
  map_data.push_back("????#####################.????");
  map_data.push_back("????..T.................#.????");
  map_data.push_back("????..#.................#.????");
  map_data.push_back("????#####################.????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");
  map_data.push_back("??????????????????????????????");

  NavigationGuidance NG = NavigationGuidance();
  NG.setMap(map_data[0].length(), map_data.size(), map_data);
  NG.setMode(EXPLORE);
  NG.getDirectionsTo(UNKNOWN);
  return 0;
}
