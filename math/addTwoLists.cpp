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

node* addList(node* first, node* second){
    node* reshead = createnode(-1);
    node* result =  reshead;
    int carry=0;
    while(first!=NULL && second!=NULL){
        node* res;
        int temp = first->data + second->data + carry;
        carry = (temp)/10;
        res = createnode(temp - carry*10);
        first=first->next;
        second=second->next;
        result->next = res;
        result = res;
    }
    while(first!=NULL){
        node* res;
        int temp = first->data + carry;
        carry = (temp)/10;
        res = createnode(temp - carry*10);
        first=first->next;
        result->next = res;
        result = res;
    }
    while(second!=NULL){
        node* res;
        int temp = second->data + carry;
        carry = (temp)/10;
        res = createnode(temp - carry*10);
        second=second->next;
        result->next = res;
        result = res;
    }
    if(carry!=0){
        result->next = createnode(carry);
    }
    return reshead->next;
}
//numbers are provided in reverse order

int main(){
    headfirst = createnode(2);
    headfirst->next =  createnode(9);
    headfirst->next->next =  createnode(9);
    headsecond = createnode(5);
    headsecond->next =  createnode(9);
   // headsecond->next->next =  createnode(9);
    node* sum = addList(headfirst,headsecond);
    disp(&sum);
    return 0;
}
