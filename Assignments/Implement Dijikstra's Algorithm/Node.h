#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string>



class Node{
    private:
        int id;
        std::string data;
        
    public:
        inline Node(){};
        inline Node(int id):id(id){};
        inline Node(int id, std::string d):id(id),data(d){}

        inline int getId(){return id;}
        inline void setData(std::string d){data = d;}
        inline std::string getData(){return data;}
};


#endif
