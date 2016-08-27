#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int data;
    node * next;
};

node * n_node( int data ){
    node * n = new node;
    n->data = data;
    n->next = nullptr;
    return n;
}

node * insert( node * root, int data ){
    if( root == nullptr ){
        return n_node( data );
    }else{
        root->next = insert( root->next, data );
    }
    return root;
}
node * q1( node * root, int i, int j ){
    node * s1;
    node * s2;
    int count = 1;
    
    if(i == count){
        return root;
    }
    count++;
    
    for( node * n=root; n->next!=nullptr; n=n->next ){
        if( i == count ){
            s1 = n;
        }
        
        if( j == count ){
            node * s3;
            s2 = n->next;
            s3 = s2->next;
            s2->next = root;
            root = s1->next;
            s1->next = s3;
            
            return root;
        }
        count++;
    }
    return root;
}

node * q2( node * root, int i, int j ){
    node * s1;
    node * s2;
    node * s3;
    node * s4;
    node * n;
    int count = 2;
    
    s1 = root;
    s2 = root->next;
    
        
    
    for( n=root; n->next!=nullptr; n=n->next ){
        
        if( count == i ){
            s1 = n;
            s2 = n->next;
        }
         if( count == j ){
            s3 = n->next;
        }
        s4 = n->next;    
        count++;
    }
    
    if( i==1 ){
        s4->next = root;
        root = s3->next;
    }else{
        
        s4->next = s2;
        s1->next = s3->next;
    }
    
    s3->next = nullptr;
    
    return root;
}
/*
node * process_query( node * root, int qt, int i, int j ){
    switch( qt ){
        case 1:
            
        break;
    }
}*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    node * root;
    int list_size;
    int queries;
    
    cin >> list_size;
    cin >> queries;
    
    
    
    
    for( size_t i=0; i<list_size; i++ ){
        int val;
        cin >> val;
        root = insert( root, val );
    }
    
    
    for( size_t i=0; i<queries; i++ ){
        int q, n, m;
        cin >> q >> n >> m;
        //cout << q << n << m << endl;
        if(q == 1)
            root = q1( root, n, m );
        else
            root = q2( root, n, m );
    }
    int first=root->data;
    int last;
    for(node * i=root; i!=nullptr; i=i->next)
        last = i->data;
    cout << first - last << endl;
    /*
    root = q1( root, 2, 4 );
    root = q2( root, 3, 5 );
    root = q1( root, 4, 7 );
    root = q2( root, 1, 4 );
    */
    for( node * i=root; i!=nullptr; i=i->next )
        cout << i->data << " " ;
    cout << endl;
    
    
    return 0;
}
