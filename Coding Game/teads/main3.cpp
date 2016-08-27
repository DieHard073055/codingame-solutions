#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

//#define DEBUG

using namespace std;

class Node{
private:
    int n_id;
    int edge_count;
public:
  Node(){}
  Node(int node, int edge):n_id(node),edge_count(edge){}
  int get_nid(){return n_id;}
  int get_ec(){return edge_count;}
  void set_nid(int id){n_id=id;}
  void set_ec(int ec){edge_count=ec;}
};

void connect_nodes(vector<vector<int> > &graph, int xi, int yi){
  graph[xi].push_back(yi);
  graph[yi].push_back(xi);

  #ifdef DEBUG
  cout << "connecting : " << xi << " " << yi << endl;
  #endif
}

bool has_visited(vector<int> v, int n){
  if(find(v.begin(), v.end(), n) != v.end()){
    return true;
  }
  return false;
}

Node bfs(vector<vector<int> > &graph, int start){
  vector<int> visited;
  deque<Node> explore;

  Node highest_edge;

  explore.push_back(Node(start, 0));

  while(!explore.empty()){
      int node = explore.back().get_nid();
      int c = explore.back().get_ec();
      explore.pop_back();

      visited.push_back(node);

      for(int i=0;i<graph[node].size();i++){
        if(!has_visited(visited,graph[node][i])){
          explore.push_front(Node(graph[node][i], c+1));
        }
      }
      if(c > highest_edge.get_ec()) {highest_edge.set_ec(c);highest_edge.set_nid(node);}
  }
  return highest_edge;
}
int max_distance(vector<vector<int> > &graph, int start){
  Node n1 = bfs(graph, start);
  Node n2 = bfs(graph, n1.get_nid());
 // Node n3 = bfs(graph, n2.get_nid());

    int ans = n2.get_ec()/2;
    if((ans * 2) < n2.get_ec()){ans++;}


  return ans;
}
int main(){
  int n; // the number of adjacency relations
  int max=0; // biggest node id in the graph
  vector<vector<int> > graph;
	cin >> n; cin.ignore();

	for (int i = 0; i < n; i++){
		int xi; // the ID of a person which is adjacent to yi
  	int yi; // the ID of a person which is adjacent to xi
  	cin >> xi >> yi; cin.ignore();
    if(yi > max || xi > max){
      max=((xi)>(yi)?(xi):(yi));
      graph.resize(max+1);
    }
    connect_nodes(graph, xi, yi);
  }
  /*#ifdef DEBUG
  for(int i=0;i<graph.size();i++){
    cout << i << " - ";
    for(int j=0;j<graph[i].size();j++){
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
  #endif*/
  cout << max_distance(graph, graph.size()-1) << endl;

  return 0;

}
