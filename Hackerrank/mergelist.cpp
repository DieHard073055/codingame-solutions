/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
#include<vector>

typedef struct BST{
    Node * data;
    struct BST *l, *r, *parent;
    int i;
}BNd;

Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission.
  // You only need to complete this method
    BNd * root;
    BNd * n;
    vector<int> dl;

    root=NULL;
    int count =0;
    if(headA !=NULL)for(Node * i=headA; i!=NULL; i=i->next)dl.push_back(i->data);
    if(headB !=NULL)for(Node * i=headB; i!=NULL; i=i->next)dl.push_back(i->data);

    if(dl.size() > 0){

        for(int i=0;i<dl.size();i++){

           //SETUP ROOT
            if(root==NULL && i==0){
                root = (BNd*) calloc(1, sizeof(BNd));
                root->l = NULL;
                root->r = NULL;
                root->parent = NULL;
                root->i=0;
                root->data = (Node*) calloc(1, sizeof(Node));
                (root->data)->data= dl[0];
            }else{
                bool done = false;
                BNd * curr_node;
                BNd * n;
                n = (BNd*) calloc(1,sizeof(BNd));
                n->l = NULL;
                n->r = NULL;
                n->parent = NULL;
                n->i=0;
                n->data = (Node*) calloc(1, sizeof(Node));
                (n->data)->data = dl[i];
                curr_node = root;
               while(!done){
                    if((n->data)->data < (curr_node->data)->data){
                        if(curr_node->l == NULL){
                            curr_node->l=n;
                            n->parent = current_node;
                            done =!done;
                        }
                        else{
                            curr_node = curr_node->l;
                        }
                    }else if((n->data)->data > (curr_node->data)->data){
                        if(curr_node->r == NULL){
                            curr_node->r=n;
                            n->parent = current_node;
                            done =!done;
                        }
                        else{
                            curr_node =curr_node->r;
                        }
                    }else if((n->data)->data == (curr_node->data)->data){
                        free(n);
                        curr_node->i++;
                    }
                }
            }
        }
        vector<int> unv;
        BNd * curr_node;
        curr_node = root;

        //INORDER FUNCTION
        while (root) {
          while (left) {
            /* code */
          }

          while (right) {
            /* code */
          }
        }
    }
    return headB;
}
