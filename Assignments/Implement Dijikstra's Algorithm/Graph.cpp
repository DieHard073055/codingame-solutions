#include "Graph.h"
#include "Node.h"

//Constructor

Graph::Graph(int num_v){
    num_vertices = num_v;
    adj_nodes.resize(num_vertices);      
}


void Graph::connectNodes(int n1, int n2, double w){
    Edge * e1 = new Edge(n1, n2, w);
    Edge * e2 = new Edge(n2, n1, w);
    
    adj_nodes[n1].push_back(e1);
    adj_nodes[n2].push_back(e2);
}


std::vector<Edge*> Graph::getConnectedNodes(int node){
    return adj_nodes[node];
}


void Graph::printGraph(){
    std::cout << std::endl << "Printing Nodes of the Graph" << std::endl << "---------------------------" << std::endl;
    for(int i=0; i<adj_nodes.size(); i++){
        std::cout << "Node " << i << " -> " ;
        
        for(int j=0; j<adj_nodes[i].size(); j++){
            std::cout << "( "<< adj_nodes[i][j]->getNode(1) << " | " << adj_nodes[i][j]->getWeight()<< ") ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl << std::endl << "Node Information" << std::endl << std::endl;
    
    for(int i=0; i<node_data.size(); i++){
        std::cout << "Node id : " << node_data[i]->getId() << std::endl << "Node Data : " << node_data[i]->getData() << std::endl << std::endl;
    }
}


bool Graph::isConnected(int n1, int n2){
    if(!adj_nodes[n1].empty()){
        for(int i=0; i<adj_nodes[n1].size(); i++){
            if(adj_nodes[n1][i]->getNode(1) == n2){
                return true;
            }
        }
    }
    return false;
}

void Graph::addNode(int id, std::string Data){
    node_data.push_back(new Node(id, Data));
}

std::string Graph::getNodeData(int id){
    return node_data[id]->getData();
}

Graph::~Graph(){
    for(int i=0; i<node_data.size(); i++)
        delete node_data[i];

}
