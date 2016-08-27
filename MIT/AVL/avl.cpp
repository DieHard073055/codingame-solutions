/**
 * @file	avl.cpp
 * @author	Eshan Shafeeq
 * @version	v0.1
 * @date	18 April 2016
 * @brief	Quick implementation of a balanced
 * 			binary tree / AVL tree.
 **/

#include <iostream>

/**
 *
 * The structure to create the BST with
 *
 * @param	data	Will be the value that will be compared with
 * 					to determine the location of the node.
 * @param	left	The pointer pointing to the left node.
 * @param	right	The pointer pointing to the right node.
 * @param	height	The height of the node from the bottom ( bottom = 1)
 *
 * */
struct node{

	float data;
	node * left;
	node * right;
	int height;

};

/**
 *
 * Function to create a new instance of the
 * node structure.
 *
 * @param	data	Will contain the value for the node
 *
 * */
node * n_node( float data ){

	node * n;

	n = new node;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	n->height = 1;

	return n;

}

/**
 * Get Height
 *
 * Function to get the height of a specific node
 *
 * */

int get_height( node * root ){
	return root ? root->height : 0;

}

/**
 * Get Balance Factor
 *
 * Will return the balance factor of the node being
 * passed into the function
 *
 * @param	root	The node which the balance factor
 * 					needs to be calculated on.
 *
 * */
int get_balance_factor( node * root ){

	if( root == nullptr ) return 0;
	int bf = get_height( root->left ) - get_height( root->right );
	return bf;
}

/**
 * Set Height
 *
 * This function will set the height of the node passed
 * into the function according to its children.
 *
 * @param	root	The node which the height will be
 * 					calculated for.
 *
 * */

void set_height( node * root ){

	int left;
	int right;

	left = get_height( root->left );
	right = get_height( root->right );
	root->height = ( left < right ) ? (right+1) : (left+1);
}

/**
 * Left Rotate
 *
 * This function will perform a left rotate on the
 * node thats been passed into the function in order
 * to maintain the AVL property.
 *
 * It will swap places with the right child node.
 *
 * @param	root	The node at which the rotation will be
 * 					performed on.
 *
 * */

node * left_rotate( node * root ){

	node * child;
	child = root;
	root = root->right;
	child->right = root->left;
	root->left = child;

	set_height( child );
	set_height( root );
	return root;


}

/**
 * Right Rotate
 *
 * This function will perform a right rotate on the
 * node thats been passed into the function in order
 * to maintain the AVL property.
 *
 * It will swap places with the left child node.
 *
 * @param	root	The at which the rotation will be
 * 					performed on.
 * */

node * right_rotate( node * root ){

	node * child;
	child = root;
	root = root->left;
	child->left = root->right;
	root->right = child;

	set_height( child );
	set_height( root );
	return root;
}

/**
 *
 * Check balance
 *
 * This function will determine if the node passed into the
 * function is required to perform a rotation by getting the
 * balance factor from the get_balance_factor function above.
 * It will select the proper rotation required in order for the
 * tree to maintain the AVL property / balanced binary tree.
 *
 * @param	root	The node at which the check will be performed on
 *
 * */

node * check_balance( node * root ){

	if( root == nullptr ) return root;
	else{
		if( get_balance_factor( root ) == -2 ){
			if( get_balance_factor( root->right ) > 0 ){
				root->right = right_rotate( root->right );
			}
			root = left_rotate( root );
		}
		if( get_balance_factor( root ) == 2 ){
			if( get_balance_factor( root->left ) < 0 ){
				root->left = left_rotate( root->left );

			}
			root = right_rotate( root );
		}
	}
	return root;
}

/**
 * Insert
 *
 * This function will insert a new node to the tree which belongs to
 * the root node that has been passed into the function. It will call
 * the n_node function to get a new instance of the structure which will
 * have the value of the data attribute passed into the function.
 *
 * @param	root	The root node which is the tree that the insertion will
 * 					be performed on.
 * @param	data	The data attribute for the new node that will be inserted.
 *
 * */

node * insert( node * root, float data ){

	if( root == nullptr ){
		return n_node(data);
	}

	if( data < root->data )
		root->left = insert( root->left, data );

	if( data > root->data )
		root->right = insert( root->right, data );

	set_height( root );
	return check_balance( root );

}

/**
 * Delete Tree
 *
 * This function will recursively call itself while passing the
 * left child and then the right child to the function itself.
 * Then proceed to delete itself. Which will delete the sub tree
 * of a given node recursively.
 *
 * @param	root	The root node of the tree that needs to be
 * 					deleted.
 *
 * */

void delete_tree( node * root ){

	if( root == nullptr ) return;
	delete_tree( root->left );
	delete_tree( root->right );
	delete root;

}

/**
 * Get Tree Height
 *
 * This function will calcualte the height of the whole tree
 * by recursively calling itself while passing the children
 * to it.
 *
 * @param	root	The root node the tree which needs the height
 * 					to be calcualted on.
 *
 * */

int get_tree_height( node * root ){

	if( root == nullptr )
		return 0;
	int left = get_tree_height( root->left ) +1;
	int right = get_tree_height( root->right ) +1;
	return ( ( left < right ) ? right : left );

}

/**
 * Level Order Traverse
 *
 * This function is a part of the level order function
 * which will print the whole tree level by level.
 * This function prints the data attribute of a node
 * if the level variable is 0. It calls itself recursively
 * while passing the children nodes to it and deducting 1
 * from the level attribute.
 *
 * @param	root	The node which the print operation might be
 * 					performed on.
 * @param	level	A variable to control the printing as the
 * 					function recursively calls itself.
 *
 * */

void level_order_traverse( node * root, int level ){

	if( root == nullptr )
		return;
	if( level == 0 ){
		std::cout << root->data << " ";
	}else{
		level_order_traverse( root->left, level-1 );
		level_order_traverse( root->right, level-1 );
	}

}

/**
 * Level Order
 *
 * This function will print the tree of a given root node
 * level by level using the level_order_traverse function.
 * It get the hright of the tree then using a for-loop controls
 * the level that will be printed.
 *
 * @param	root	The root node of the tree that the levels will be
 * 					printed to the screen.
 *
 * */

void level_order( node * root ){

	for( size_t i=0; i<get_tree_height(root); i++ ){
		level_order_traverse( root, i );
		std::cout << std::endl;
	}
	std::cout << std::endl;

}

/**
 * In Order
 *
 * This function will print the values sorted from min to max.
 *
 * @param	root	The root node of the tree which will be printed
 * 					to the screen in accending order.
 *
 * */

void in_order( node * root ){
	if( root == nullptr ) return;
	in_order( root->left );
	std::cout << root->data << " ";
	in_order( root->right );
}

/**
 * Main
 *
 * This program will accept a testcase as follows
 *
 * N
 * N numbers seperated by spaces.
 *
 * will construct a balanced binary tree or an AVL tree
 * based on input and then print out the tree using the
 * level_order function.
 *
 *
 * */
int main( void ){

	node * root;
	int N;

	std::cin >> N;

	for( size_t i=0; i<N; i++ ){
		float data;
		std::cin >> data;
		root = insert( root, data );
	}

	level_order( root );
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	in_order( root );
	std::cout << std::endl;
	delete_tree( root );

	return 0;

}

