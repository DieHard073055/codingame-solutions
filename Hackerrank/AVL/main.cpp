/**
 * @file 	avl.cpp
 * @author	Eshan Shafeeq
 * @version	v0.1
 * @date	April 17 2016
 * @brief	Implementation of a balanced binary tree.
 *
 **/

#include <iostream>
#include <string>

#define DEBUG

struct node{
	int data;
	node * left;
	node * right;
	int height;
};

void pd( std::string msg ){
#ifdef DEBUG
	std::cout << msg << std::endl;
#endif
}

node * get_new_node( int data ){

	node * n;
	n = new node;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	n->height = 1;

	pd("[get_new_node] created new node[" + std::to_string(data) + "]");
	return n;
}

int get_height( node * root ){
	return root ? root->height : 0;
}

int get_balance_factor( node * root ){
	if( root == nullptr ) return 0;
	return get_height(root->right) -
		get_height(root->left);
}

void calculate_height( node * root ){
	int left = get_balance_factor(root->left);
	int right = get_balance_factor(root->right);

	root->height = ( left < right ? ( right+1 ) : ( left+1 ) );

}

node * right_rotate( node * root ){
	node * child;
	child = root->left;
	root->left = child->right;
	child->right = root;

	calculate_height( root );
	calculate_height( child );

	return child;
}

node * left_rotate( node * root ){
	node * child;
	child = root->right;
	root->right = child->left;
	child->left = root;

	calculate_height( root );
	calculate_height( child );

	return child;
}

node * check_balance( node * root ){
	calculate_height( root );
	if( get_balance_factor( root ) < -1 ){

		pd("[check_balance] left case");
		if( get_balance_factor( root->left ) > 0 )
			root->left = left_rotate( root->left );
		return right_rotate( root );
	}
	if( get_balance_factor( root ) > 1 ){
		pd("[check_balance] right case");
		if( get_balance_factor( root->right ) < 0 )
			root->right = right_rotate( root->right );
		return left_rotate( root );
	}
	return root;
}

node * insert( node * root, int data ){
	if( root == nullptr ){

		return get_new_node(data);
	}
	if( data < root->data )
		root->left = insert( root->left, data);
	else if( data > root->data ){
		root->right = insert( root->right, data );
	}

	return check_balance( root );
}

void in_order( node * root ){
	if( root == nullptr ) return;

	in_order( root->left );
	std::cout << root->data << " ";
	in_order( root->right );
}

void post_order( node * root ){
	if( root == nullptr ) return;
	post_order( root->left);
	post_order( root->right );
	std::cout << root->data << " ";
}

void top_view_left( node * root ){
	if( root == nullptr ) return;
	top_view_left( root->left );
	std::cout << root->data << " ";
}

void top_view_right( node * root ){
	if( root == nullptr ) return;
	std::cout << root->data << " ";
	top_view_right( root->right );
}

void top_view( node * root ){
	top_view_left( root->left );
	std::cout << root->data << " ";
	top_view_right( root->right );
}

void level_order_traverse( node * root, int level ){
	if( root == nullptr ) return;
	if( level == 0 ) std::cout << root->data << " ";
	else{
		level_order_traverse( root->left, level-1 );
		level_order_traverse( root->right, level-1 );
	}
}

int get_tree_height( node * root ){
	if( root == nullptr ) return 0;
	int left = get_tree_height(root->left);
	int right = get_tree_height(root->right);
	return ( left < right ? (right+1) : (left+1) );
}

void level_order( node * root ){
	for( size_t i=0; i<get_tree_height( root ); i++ ){
		level_order_traverse( root, i );
		std::cout << " | ";
	}
}

void delete_tree( node * root ){
	if( root == nullptr ) return;
	delete_tree( root->left );
	delete_tree( root->right );
	delete( root );
}

int main( void ){
	node * root;
	int N;
	std::cin >> N;
	for( size_t i=0; i<N; i++ ){
		int val;
		std::cin >> val;
		root = insert( root, val );
	}

	level_order(root);
	std::cout << std::endl;
	delete_tree( root );
}
