#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
#include<string>
#include "Node.h"
#include "Edge.h"

class Graph{
    private:
        std::vector < std::vector < Edge*> > adj_nodes;
        std::vector <Node*> node_data;
    
    public:
        int num_vertices;
        
        Graph(int num_v);
        ~Graph();
        void connectNodes(int n1, int n2, double w);
        void addNode(int id, std::string Data);
        std::string getNodeData(int id);
        std::vector<Edge*> getConnectedNodes(int node);
        void printGraph();
        bool isConnected(int n1, int n2);
        
    
};

#endif
