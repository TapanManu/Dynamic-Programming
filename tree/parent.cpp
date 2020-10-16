#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* lc;
    node* rc;
}*root,*ptr;

static int l=0,r=0;          //left child right child falg
node* par=root;

node* createNode(int data){
    ptr = new node;
    ptr->data = data;
    ptr->lc = NULL;
    ptr->rc = NULL;
    return ptr;
}

void inorder(node* ptr){
    if(ptr!=NULL){
        inorder(ptr->lc);
        cout<<ptr->data<<"\t";
        inorder(ptr->rc);
    }
}

node* parent(node* par,node* ptr){
    node* p;
    if(ptr==root)
        return root;        // root
    if(ptr!=NULL){
        if(par->lc==ptr){
            l = 1;                  //left child
        }
        else if(par->rc==ptr){
            r = 1;                  //right child
        }
        else{
            if(par->lc!=NULL){
                p = parent(par->lc,ptr);        // if found left sub tree
                if( l==1 || r==1 )
                    return p;
            }
            if(par->rc!=NULL){
                p = parent(par->rc,ptr);        // if found in right sub tree
                if( l==1 || r==1 )
                    return p;
            }    
            if( l==0 && r==0 )
                return NULL;                //no parent found
        }
        if(l==1 || r==1){
            return par;
        }

    }
    return NULL;                            //no parent found
}

int main(){
    root = createNode(4);
    root->lc = createNode(2);
    root->rc = createNode(6);
    root->lc->lc = createNode(1);
    root->lc->rc = createNode(3);
    root->rc->lc = createNode(5);
    root->rc->rc = createNode(8);
    root->rc->rc->lc = createNode(7);
    root->rc->rc->rc = createNode(9);
    ptr = root;
    inorder(ptr);  
    cout<<"\n";
    node* res = parent(root,root->rc->rc->rc);
    if(res==NULL)
        cout<<"no parent";
    else
        cout<<"parent:"<<res->data;
    cout<<"\n";
    return 0;
}
