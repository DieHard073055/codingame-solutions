#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define debugging 1

using namespace std;

class connected_nodes{
private:
  int n1;
  int n2;

public:
  connected_nodes(){}
  connected_nodes(int i1, int i2):n1(i1),n2(i2){}
  void setn1(int i){n1=i;}
  void setn2(int i){n2=i;}
  int getn1(){return n1;}
  int getn2(){return n2;}
};


void connect_graph(vector<vector<int> > &graph, int n1, int n2, int weight){
  graph[n1][n2]=weight;
  graph[n2][n1]=weight;
  #ifdef debugging
  cout << n1 << " -> " << n2 << " = " << weight << endl;
  cout << n2 << " -> " << n1 << " = " << weight << endl;
  #endif
}

vector<int> get_adj_nodes(vector<vector<int> > graph, int n){
  vector<int> adj;
  #ifdef debugging
  cout << "adj() : " << n << endl;
  #endif
  for(int i=0;i<graph[n].size();i++){
    if(graph[n][i] == 1) {
        adj.push_back(i);
        #ifdef debugging
        cout << i << " ";
        #endif
      }
  }
  #ifdef debugging
  cout << endl;
  #endif
  return adj;
}
bool has_visited(vector<int> v, int n){
  if(find(v.begin(), v.end(), n) != v.end()){
    return true;
  }
  return false;
}
int find_minimum_time(vector<connected_nodes> gd, int max){
  //Store all the data about the graph
  vector<vector<int> > graph(max+1, vector<int>(max+1, 0));

  //print out the highest node id
  #ifdef debugging
  cout << "max : " << max << endl;
  #endif
  for(int i=0;i<gd.size();i++){
    //get the 2 adjacent nodes
    int n1 = gd[i].getn1();
    int n2 = gd[i].getn2();

    //Print out the 2 adjacent nodes
    #ifdef debugging
    cout << n1 << " " << n2 << endl;
    #endif

    //set the edge weight to 1
    connect_graph(graph, n1, n2, 1);

  }
  vector<int> explore;
  vector<int> visited;
  deque<vector<int> > sm;

  explore.push_back(max);

  //cout << "--------- Graph filling algorithm ---------" << endl;
  while(!explore.empty()){
    //pop the nodes from explore list
    int node = explore.back();
    visited.push_back(node);
    explore.pop_back();

    //find adj nodes and add them to explore list
    //if they are not in the visited list
    vector<int> adj = get_adj_nodes(graph, node);
    for(int j=0;j<adj.size();j++){
      if(!has_visited(visited, adj[j])){
        explore.push_back(adj[j]);
      }
    }
    for(int i=0;i<adj.size();i++){
      for(int j=0;j<adj.size();j++){
        if(i!=j){
          connect_graph(graph, adj[i], adj[j], 2);
        }
      }
    }
    for(int i=0;i<graph[node].size();i++){
      for(int j=0;j<adj.size();j++){
        if(graph[node][i] != 0 && graph[adj[j]][i] == 0){
          connect_graph(graph, adj[j], i, graph[node][i]+1);
        }
      }
    }

  }


  //Print the graph
  #ifdef debugging
  cout << "    ";
  for(int j=0;j<graph[0].size();j++){
    if(j >= 10){
    cout << j << "  ";
    }else
    cout << j << "   ";
  }
  cout << endl;
  for(int i=0;i<graph.size();i++){
    if(i < 10)
    cout << i << "   ";
    else
    cout << i << "  ";
    for(int j=0;j<graph[i].size();j++){
      if(graph[i][j] == 0)cout << "-   " ;
      else
      cout << graph[i][j] << "   " ;
    }
    cout << endl;
  }
  #endif

  //Find the node with least number of edges to all the nodes
  //And print out the edge weight
  int max_s [max+1];
  for(int i=0;i<max+1;i++){
    int max_d=0;
    for(int j=0;j<max+1;j++){
      if(graph[i][j] > max_d){
        max_d=graph[i][j];
      //  cout << "dist " << i << " : " <<  graph[i][j] << endl;
      }
    }
    if(max_d != 0)
    max_s[i] = max_d;
    else max_s[i] = gd.size();
  }


  //cout << "max" << endl;
  #ifdef debugging
  for(int i=0;i<max+1;i++)
  cout << max_s[i] << endl;
  #endif
  return *min_element(max_s,max_s+(max+1));
}

int main(){
  int n; // the number of adjacency relations
  int max=0; // biggest node id in the graph
  vector<connected_nodes> graph_data;

	cin >> n; cin.ignore();

	for (int i = 0; i < n; i++){
		int xi; // the ID of a person which is adjacent to yi
  	int yi; // the ID of a person which is adjacent to xi
  	cin >> xi >> yi; cin.ignore();
    graph_data.push_back(connected_nodes(xi, yi));
    if(xi > yi)yi=xi;
    if(yi > max)max=yi;
  }


  cout << find_minimum_time(graph_data, max) << endl;

  return 0;

}
