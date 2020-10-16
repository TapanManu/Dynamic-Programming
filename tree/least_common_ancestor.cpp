#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* lc;
    node* rc;
}*root,*ptr;

static int l=0,r=0;          //left child right child falg


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

node* findNode(node* ptr,int data){
    node* p;
    if(ptr->data == data)
        return ptr;
    if(ptr->lc==NULL && ptr->rc==NULL)
        return NULL;
    if(ptr->lc!=NULL){
        p = findNode(ptr->lc,data);
        if(p!=NULL){
            return p;
        }
    }
    if(ptr->rc!=NULL){
        p = findNode(ptr->rc,data);
        if(p!=NULL)
            return p;
    }
    return NULL;
}
static int depth=0;
int findDepth(node* ptr,node* cur){
    int d=0;
    if(ptr==root)
        return 0;
    if(cur==ptr)
        return depth;
    if(cur->lc!=NULL){
        depth++;
        d = findDepth(ptr,cur->lc);
        if(d!=-1)
            return d;
        depth--;
    }
    if(cur->rc!=NULL){
        depth++;
        d = findDepth(ptr,cur->rc);
        if(d!=-1)
            return d;
        depth--;
    }
    return -1;          //if matching node not found

}

node* ancestor(node* ptr1,node* ptr2){
    if(ptr1==ptr2){                  //if they are same
        return ptr1;
    }
    
    depth=0;
    int d1 = findDepth(ptr1,root);
    depth=0;                            //resetting static variable value
    int d2 = findDepth(ptr2,root);
    
   
    if(d1==d2){
        
        l=0,r=0;
        node* par1 = parent(root,ptr1);
        l=0,r=0;
        node* par2 = parent(root,ptr2);
        depth=0;
        
        if(par1==par2){
            
            return par1;                    //same parent
        }
        return ancestor(par1,par2);
    }
    if(d1<d2){
        l=0,r=0;
        node* par2 = parent(root,ptr2);           //find parent of par1 until depth are same
        return ancestor(ptr1,par2);     //call ancestor of new parents
    }
    if(d1>d2){
        l=0,r=0;
        node* par1 = parent(root,ptr1);     //find parent of par2 until depth are same
        return ancestor(par1,ptr2);     //call ancestor of new parents
    }
    
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
    node* res = parent(root,root->rc->rc->lc);
    if(res==NULL)
        cout<<"no parent";
    else
        cout<<"parent:"<<res->data;
  

    cout<<"\n";
    node* first = findNode(root,1);
    node* second = findNode(root,9);
    //depth=0;
    l=0,r=0;
    cout<<"least common ancestor:"<<ancestor(first,second)->data;    
    return 0;
}
