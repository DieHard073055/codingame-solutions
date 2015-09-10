#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//#define DEBUGGING

using namespace std;


class Node {
	public:
	int value;
	int dist;
};
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int vec_in(vector<int> j, int x){
	for(int i=0; i<j.size(); i++){
		if(j[i] == x) return 1;
	}
	return 0;
}
int max_distance_to_all_from(vector<vector<int> > graph, int e){
	vector<int> v;
	vector<Node> q;
	int dist = 0;
	Node curr;

	curr.value = e;
	curr.dist = 0;

	q.push_back(curr);

	while(!q.empty()){
		curr.value = q[0].value;
		curr.dist = q[0].dist;
		#ifdef DEBUGGING
		cout << "curr : " << curr.value << " - ";
		#endif
		q.erase(q.begin());
		v.push_back(curr.value);

		for(int i=0; i<graph[curr.value].size(); i++){

			if(!vec_in(v, graph[curr.value][i])){
				Node no;
				no.value = graph[curr.value][i];
				no.dist = curr.dist+1;
				q.push_back(no);
				#ifdef DEBUGGING
				cout << graph[curr.value][i] << " ";
				#endif
				dist = no.dist;

			}
		}
		#ifdef DEBUGGING
		cout << endl;
		#endif
	}

	return dist;
}
int main()
{
    	int n; // the number of adjacency relations
	int min, max=0;

	cin >> n; cin.ignore();min=n;
	vector<vector<int> > graph(n*2);

	for (int i = 0; i < n; i++){
		int xi; // the ID of a person which is adjacent to yi
  		int yi; // the ID of a person which is adjacent to xi
  		cin >> xi >> yi; cin.ignore();
		if(max < xi) max = xi;
		if(max < yi) max = yi;
		graph[xi].push_back(yi);
		graph[yi].push_back(xi);
  	}

  	// Write an action using cout. DON'T FORGET THE "<< endl"
  	// To debug: cerr << "Debug messages..." << endl;
	for(int i=0; i<max+1; i++){
		int m = max_distance_to_all_from(graph, i);
		#ifdef DEBUGGING
		cout << i <<  " : dist : " << m << endl;
		#endif
		if(m < min && m != 0) min = m;
	}
	cout << min << endl; // The minimal amount of steps required to completely propagate the advertisement
}
