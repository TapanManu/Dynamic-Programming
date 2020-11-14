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

node* deleteNode(node** head,int data){
    node* prev;
    node* cur=*head;
    while(cur!=NULL && cur->data!=data){
        prev = cur;
        cur = cur->next;
    }
    if(cur==NULL){
        cout<<"no matching node";
        return NULL;
    }
    if(cur->data==data){
        if(cur==*head){
            *head = cur->next;
            return cur;
        }
        else{
            prev->next = cur->next;
            return cur;
        }
    }
    return NULL;
}

void nlast(node** head,int n){
    int len=0;
    node* cur = *head;
    while(cur!=NULL){
        cur=cur->next;
        len++;
    }
    if(n>len){
        cout<<"cannot remove, value is out of range";
        return;
    }
    int ctr=1;
    cur = *head;
    while(cur!=NULL){
        //cout<<ctr<<" "<<(len-n+1);
        if(ctr==(len-n+1)){
            deleteNode(head,cur->data);
            break;
        }
        cur = cur->next;
        ctr++;
    }
    disp(head);
}



int main(){
    headfirst = createnode(1);
    headfirst->next =  createnode(2);
    headfirst->next->next =  createnode(3);
    headfirst->next->next->next =  createnode(4);
    nlast(&headfirst,4);
    return 0;
}
