#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* lc;
    node* rc;
} *root,*ptr;

node* createnode(int data){
    ptr = new node;
    ptr->data = data;
    ptr->lc = NULL;
    ptr->rc = NULL;
    return ptr;
}

stack<node*> s;

void preorder(){
    node* p;
    p = root;
    s.push(root);
    while(!s.empty()){
        p = s.top();
        cout<<p->data;
        s.pop();
        if(p->rc!=NULL)
            s.push(p->rc);
        if(p->lc!=NULL)
            s.push(p->lc);
    }
}

int main(){
    root = createnode(4);
    root->lc = createnode(3);
    root->rc = createnode(5);
    preorder();
    return 0;
}
