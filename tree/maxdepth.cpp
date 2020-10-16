#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* lc;
    node* rc;
}*root,*ptr;

static int maxdepth=0;

void maxDepth(node* ptr){
    static int depth=0;
    if(ptr->lc == NULL && ptr->rc == NULL){             //leaf nodes
        if(depth > maxdepth){
            maxdepth = depth;                //max depth
        }
        return;
    }
    if(ptr->lc!=NULL){
        depth++;
        maxDepth(ptr->lc);                  //left child
        depth--;
    }
    if(ptr->rc!=NULL){
        depth++;
        maxDepth(ptr->rc);                  //right child
        depth--;
    }
}

node* createnode(int data){
    node* ptr = new node;
    ptr->data = data;
    ptr->lc = NULL;
    ptr->rc = NULL;
    return ptr;
}

int main(){
    root = createnode(5);
    root->lc = createnode(1);
    root->rc = createnode(2);
    root->rc->rc = createnode(3);
    root->rc->rc->lc = createnode(4);
    root->lc->rc=createnode(6);
    if(root!=NULL)
        maxDepth(root);
    cout<<maxdepth+1;           //maxdepth of node
    cout<<"\n";
    return 0;
}
