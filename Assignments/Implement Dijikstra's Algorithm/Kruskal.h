#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include <vector>
#include "Graph.h"
#include "Edge.h"


class Kruskal{
	private:
		std::vector<int> explored_nodes;
		std::vector<Edge*> unexplored_nodes;
		
		//Utility functions
		bool exists_in_explored(int node){
			for(int i=0; i<explored_nodes.size(); i++){
				if(explored_nodes[i] == node){
					return true;
				}
			}
			return false;
		}
		
		bool exists_in_unexplored(Edge * node){
			for(int i=0; i<unexplored_nodes.size(); i++){
				if(unexplored_nodes[i]->getNode(1) == node->getNode(1)){
					return true;
				}
			}
			return false;
		}
		int getNextMinNode(){
			int min_node = unexplored_nodes[0]->getNode(1);
			double min = unexplored_nodes[0]->getWeight();
			for(int i=0; i<unexplored_nodes.size(); i++){
				if(unexplored_nodes[i]->getWeight() < min){
					min_node = unexplored_nodes[i]->getNode(1);
					min = unexplored_nodes[i]->getWeight();
				}
			}
			return min_node;
		}
		
		void printUnExplored(){
			std::cout << "Printing UnExplored Node List" << std::endl;
			for(int i=0; i<unexplored_nodes.size(); i++){
				std::cout << "Node[" << i << "] : " << unexplored_nodes[i]->getNode(1) << std::endl;
			}
			std::cout << std::endl;
		}
		
		int getPositionUnExplored(int node){
			for(int i=0; i<unexplored_nodes.size(); i++){
				if(unexplored_nodes[i]->getNode(1) == node){
					return i;
				}
			}
		}
	public:
		void kruskals_short_path(Graph * g, int start_node, int goal_node){
			std::cout << "Solving the shortest path from " << start_node << " to " << goal_node << std::endl << std::endl << std::endl;
			bool algorithm_running = true;
			int current_node = start_node;
			while(algorithm_running){
				//get connected nodes and add them to unexplored list
				//			conditions to add
								//-only if they dont exist in the explored list
								//-The current route in the explored list longer then the new found entry
				//		if non of the conditions are met, and there is nothing in the unexplored list
				//		terminate the algorithm, and print out no solution
				std::vector<Edge*> adj = g->getConnectedNodes(current_node);
				for(int i=0; i<adj.size(); i++){
					if(!exists_in_explored(adj[i]->getNode(1)) && !exists_in_unexplored(adj[i])){
						std::cout << "Node[" << current_node << "] adj[" << i << "] : " << adj[i]->getNode(1) << " Added! " << std::endl;
						unexplored_nodes.push_back(adj[i]);
					}
				}
				
				//get the smallest weight node in the unexplored list
				//Go to that node
				current_node = getNextMinNode();
				std::cout << "min node : " << current_node << std::endl;
				explored_nodes.push_back(current_node);
				unexplored_nodes.erase(unexplored_nodes.begin() + getPositionUnExplored(current_node));
				printUnExplored();
				
				//check if we have reached the destination, print out solution found! and terminate the algorithm
				//else repeat the above process
				
				if(current_node == goal_node){
					std::cout << "We have found the Goal Node!" << std::endl;
					algorithm_running = false;
				}else{
					std::cout << std::endl << std::endl << "Enter to continue" << std::endl;
					std::cin.ignore();
				}
			}
			
		}
		
	

};
#endif
