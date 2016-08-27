//g++ main.cpp -o main -lm Node.o Graph.o -std=c++0x

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "Graph.h"
#include "Kruskal.h"

using namespace std;

const int SIZE_GRAPH = 10;
const double CONNECTED_DENSITY = 195;

void generateRandomGraph(Graph * g, double density){
	int con_edges = density/100 * g->num_vertices;
	//cout << "Number of edges to be connected " << con_edges << endl;
	
	srand(time(0));
		
	for(int i=0; i<con_edges; i++){
		bool proper_num = false;
		int r_num1, r_num2;
		
		while(!proper_num){
			r_num1 = rand() % g->num_vertices;
			r_num2 = rand() % g->num_vertices;

			if(r_num1 != r_num2){
				if(!g->isConnected(r_num1, r_num2)){
					proper_num = true;
					break;
				}
			}
		}
		
		const double w = rand() % int(200.4535 - 34.54353 + 1.6778) + 34.54353;
		g->connectNodes(r_num1, r_num2, w);
		
        //cout << "Successfull!" << endl << "r1 : " << r_num1 << " r2 : " << r_num2 << endl;
    }
//    Printing All the Node Data    
//    for(int i=0; i<g->num_vertices; i++){
//        string data = "Node Data " + to_string(rand() % 4454);
//        g->addNode(i, data);
//    }
}

int main(void){
   //Initialise Graph
   //Initialise the Kruskal Class
   Graph * g = new Graph(SIZE_GRAPH);
   Kruskal * k = new Kruskal();
   
   //Generate Random Graph
   //Print the Graph
   generateRandomGraph(g, CONNECTED_DENSITY);
   g->printGraph();
   
   //Solve the Puzzle
   k->kruskals_short_path(g, 0, g->num_vertices-1);
   
   //Clean up Everything
   delete k;
   delete g;
   return 0;
   
}
