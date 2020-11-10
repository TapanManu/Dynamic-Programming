#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//checking palindrome for 2n+1 elements

struct node{
    int data;
    node* next;
}*head,*ptr,*cnode;

void reverse(){
    node* prev=NULL;
    node* cur=head;
    node* next=NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void print(node* head){
    node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"\t";
        ptr = ptr->next;
    }
    cout<<endl;
}

node* createnode(int data){
    ptr = new node;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

node* addnode(node* cnode,int data){
    node* temp = createnode(data);
    cnode->next = temp;
    cnode = temp;
    return cnode;    
}

int main(){
    node* mid;
    head = createnode(1);
    cnode = head;
    cnode = addnode(cnode,2);
    cnode = addnode(cnode,3);
    cnode = addnode(cnode,4);
    mid = cnode;
    cnode = addnode(cnode,3);
    cnode = addnode(cnode,2);
    cnode = addnode(cnode,1);
    print(head);
    reverse();
    print(head);
    return 0;
}
