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

//two-pointer method
void find_mid(node** head){
    node* prev;
    node* slow = *head;
    node* fast = *head;
    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }   
    if(fast==NULL){
        //even 
        cout<<prev->data<<" "<<slow->data;
    }
    else if(fast->next==NULL){
        cout<<slow->data;
    }
    cout<<endl;
}

int main(){
    head = createnode(1);
    head->next =  createnode(2);
    head->next->next =  createnode(3);
    head->next->next->next =  createnode(4);
    find_mid(&head);
    return 0;
}
