#include <iostream>


using namespace std;

typedef struct node{
	int val;
	struct node *left;
	struct node *right;
	int ht;
} node;

node * __ROOT__;

node * get_new_node( int node_id ){
	node * new_node;
	new_node = new node;
	new_node->val = node_id;
	new_node->left = nullptr;
	new_node->right = nullptr;
	new_node->ht = 0;

	cout << "created node [" << new_node->val << "]" << endl;
	return new_node;
}

void pdl( node *root, int level ){
	if(level == 0){
		cout << root->val << " ";
	}else{
		if(root->left){
			pdl(root->left, level-1);
		}
		if(root->right){
			pdl(root->right, level-1);
		}
	}
}

int height( node *root ){
	int h1 = -1;
	int h2 = -1;

	if(root->left)
		h1 = height(root->left);

	if(root->right)
		h2 = height(root->right);

	if(h1 > h2)
		return ++h1;
	else
		return ++h2;
}

void levelOrder( node *root ){
	int count=0;
	int ret=0;
	int h = height(root);

	for( size_t i=0; i<h+1; i++ ){
		pdl(root, i);
		cout << "| ";
	}
	cout << endl;
}

int getBalanceFactor( node *root ){
	if( root->left == nullptr && root->right == nullptr ){
		root->ht = 0;
		return 0;

	}else{
		int left=0;
		int right=0;

		if(root->left)
			left = (root->left)->ht + 1;

		if(root->right)
			right = (root->right)->ht + 1;

		if(left > right)
			root->ht = left;
		else
			root->ht = right;

		return (left-1) - (right-1);
	}
}
void print_tree(){
	levelOrder(__ROOT__);
}
node * balance( node * root ){
	node * child;

	//check which case
	if( root->left ){
		child = root->left;
		if(child->left){
			cout << "left left case" << endl;
			cout << "root : " << root->val << " child : " << child->val << endl;
			//left left case
			node * right;
			right = root;
			if(child->right)
				right->left = child->right;
			else
				right->left = nullptr;
			root = child;
			root->right = right;
			return root;

		}else if (child->right){
			cout << "left right case" << endl;
			cout << "root : " << root->val << " child : " << child->val << endl;
			//left right case
			//Rotation on the bottom 2
			//       y
			//      /
			//     x <-- this one [ child ]
			//      \
			//       z <-- this one [child right]
			//
			node * right;
			right = root;
			root = child->right;
			root->left = child;
			root->right = right;
			child->right = nullptr;

			return root;
		}
	}else if( root->right ){
		child = root->right;

		if(child->left){
			cout << "right left case" << endl;
			cout << "root : " << root->val << " child : " << child->val << endl;
			//right left case
			//Rotation on the bottom 2
			//   y
			//    \
			//     x  <-- this one [child] and
			//    /
			//   z  <-- this one [child->left]
			//

			node * left;
			left = root;
			root = child->left;
			root->left = left;
			root->right = child;
			child->left = nullptr;


			return root;

		}else if(child->right){
			cout << "right right case" << endl;
			cout << "root : " << root->val << " child : " << child->val << endl;
			// right right case

			node * left;
			left = root;
			if(child->left)
				left->right = child->left;
			else
				left->right = nullptr;
			root = child;
			root->left = left;
			return root;
		}
	}

	return root;
}

node * insert( node * root, int val ){

	if( root == nullptr )
		return get_new_node(val);

	if( val < root->val ){
		if( root->left )
			insert(root->left, val);
		else
			root->left = get_new_node(val);
	}else if( val > root->val ){
		if( root->right )
			insert(root->right, val);
		else
			root->right = get_new_node(val);
	}
	if( root->left )
		if( getBalanceFactor(root->left) > 1 || getBalanceFactor(root->left) < -1 ){
			cout << "unbalance @ node[" << (root->left)->val << "]" << endl;
			root->left = balance(root->left);
		}

	if( root->right )
		int bf = getBalanceFactor(root->right);
		if( bf > 1 || bbf < -1 ){
			cout << "unbalance @ node[" << (root->right)->val << "]" << endl;
			if( bf )
			root->right = balance(root->right);
		}
	return root;
}

void delete_tree( node *root ){
	if( root->left )
		delete_tree( root->left );
	if( root->right )
		delete_tree( root->right );
	delete( root );
}


int main( void ){

	__ROOT__ = nullptr;
	int N;

	cin >> N;
	for( size_t i=0; i<N; i++ ){
		int val;
		cin >> val;
		cout << "val[" << i << "] : " << val << endl;
		__ROOT__ = insert(__ROOT__, val);

		print_tree();
	}

	levelOrder(__ROOT__);

	delete_tree(__ROOT__);

	return 0;
}


