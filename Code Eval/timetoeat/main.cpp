/**
 *
 * @file	time_to_eat.cpp
 * @author	Eshan Shafeeq
 * @version	v0.1
 * @date	2 May 2016
 * @brief	Given a list of timestamps
 * 			in a file, sort them and
 * 			print them.
 *
 **/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct node{
	int key;
	std::string data;
	node * left;
	node * right;
};

node * n_node( int key, std::string data ){
	node * n;
	n = new node;
	n->key = key;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}
node * insert( node * root, int key, std::string data ){
	if( root == nullptr ) return n_node( key, data );
	else{
		if( key < root->key ) root->left = insert( root->left, key, data );
		else if( key > root->key ) root->right = insert( root->right, key, data );
		return root;
	}
}
void in_order( node * root ){
	if( root == nullptr ) return;
	in_order( root->left );
	std::cout << root->data << " >> " << root->key << std::endl;
	in_order( root->right );
}
void rev_in_order( node * root ){
	if( root == nullptr ) return;
	rev_in_order( root->right );
	std::cout << root->data << " ";

	//std::cout << root->data << " " << root->key << std::endl;
	rev_in_order( root->left );
}

int pow( int x, int y ){
	int ret=x;
	if( y ==0  ) return 0;
	for( int i=0; i<y-1; i++ ) ret=ret*x;
	return ret;
}
void process( std::string line ){

	std::vector<std::string> timestamps;
	node * root=nullptr;

	std::string s="";
	for( int i=0; i<line.length(); i++ ){

		if( line[i] == ' ' ){
			timestamps.push_back( s );
			s = "";
		}else
			s+= line[i];

	}
	timestamps.push_back(s);
	for( int i=0; i<timestamps.size(); i++ ){
		std::string data = timestamps[i];
		std::string number="";

		int count = 2;
		int current_node=0;
		for( int j=0; j<data.length(); j++ ){

			if( data[j] == ':' ){
				std::string::size_type sz;
				int num = std::stoi( number, &sz );
				current_node += num * pow( 60, count-- );
				number = "";
			}else{
				number += data[j];
			}

		}
	std::string::size_type sz;
	int num = std::stoi( number, &sz );
	current_node += num ;
	root = insert( root, current_node, timestamps[i] );
	current_node = 0;
	number = "";

	}
	rev_in_order(root);
	std::cout << std::endl;
}
int main( int argc, char *argv[] ){

	std::ifstream stream( argv[1] );
	std::string line;

	while( std::getline( stream, line ) ){
		process( line );
	}

	return 0;
}
