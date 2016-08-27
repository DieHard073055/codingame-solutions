#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Edge{
    private:
        int node;
        int other_node;
        double weight;
        
        
    public:
        inline Edge(int n1, int n2, double w):node(n1), other_node(n2), weight(w){}
        inline int getNode(int num){if(num == 0) return node; else return other_node;}
        inline double getWeight(){return weight;}
        
};


#endif
