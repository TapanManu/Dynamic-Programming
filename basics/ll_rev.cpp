#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
}*ptr,*head;

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

void reverse(node** head){
    if(head==NULL) return;
    node* prev = NULL;
    node* n = NULL;
    node* cur = *head;
    while(cur!=NULL){
        node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    *head = prev;
    disp(head);
}


int main(){
    head = createnode(1);
    head->next =  createnode(2);
    head->next->next =  createnode(3);
    reverse(&head);
}
