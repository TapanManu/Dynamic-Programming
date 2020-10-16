#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
}*head,*ptr,*cur;

node* createnode(int data){
    ptr = new node;
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

node* addnode(int data){
    node* tmp = createnode(data);
    cur->next = tmp;
    cur = tmp;
    return cur;
}

void traverse(node* ptr){
    if(ptr==NULL)
        return;
    if(ptr->next==NULL){
        cout<<ptr->data<<"\n";
        return;
    }
    cout<<ptr->data<<"->";
    traverse(ptr->next);
}

void swap(node* l, node* r){
   // cout<<l->data<<"\t"<<r->data<<"\n";
    int tmp = l->data;
    l->data = r->data;
    r->data = tmp;
  //  cout<<l->data<<"\t"<<r->data<<"\n";
}

void bubblesort(){
    node* start = head;
    node* n;
    int flag=1;

    while(flag==1){
        flag=0;
        n = head;
        while(n!=NULL){
            if(n->next!=NULL && n->data > n->next->data){
                swap(n,n->next);
                //traverse(head);
                flag=1;
            }
            n=n->next;
        }
        if(flag==0)
            break;
        start = start->next;
    }
}


int main(){
    if(head==NULL){
        head = createnode(5);
        cur = head;
    }
    cur = addnode(4);
    cur = addnode(3);
    cur = addnode(2);
    cur = addnode(1);
    traverse(head);
    bubblesort();
    traverse(head);

    return 0;
}

/*this algo works for test case
5 4 3 2 1

1 2 3 4 5
==================
1 4 3 2 1

1 1 2 3 4
*/

