#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
}*ptr,*headfirst,*headsecond;

node* createnode(int data){
    node* ptr = new node;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void disp(node** head){
    ptr = *head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
}

//merge two sorted lists recursively
node* mergelist(node* first,node* second){
    node* merge=NULL;
    if(first==NULL){
        return second; 
    }
    if(second==NULL){
        return first;
    }
    if(first->data <= second->data){
        merge = first;
        merge->next = mergelist(first->next,second);
    }
    else{
        merge = second;
        merge->next = mergelist(first,second->next);
    }
    return merge;
}

int main(){
    headfirst = createnode(1);
    headfirst->next =  createnode(2);
    headfirst->next->next =  createnode(3);
    headfirst->next->next->next =  createnode(4);
    headsecond = createnode(1);
    headsecond->next =  createnode(2);
    headsecond->next->next =  createnode(7);
    headsecond->next->next->next =  createnode(8);
    node* mergehead = createnode(0);
    mergehead = mergelist(headfirst,headsecond);
    disp(&mergehead);
    
    return 0;
}
