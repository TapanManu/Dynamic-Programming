#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//checking palindrome for 2n+1 elements

struct node{
    int data;
    node* next;
}*head,*ptr,*cnode;

void reverse(node** headref){
    node* prev=NULL;
    node* cur=*headref;
    node* next=NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *headref = prev;
}

int compareList(node* n1, node* n2){
    int same=1;
    while(n1!=NULL && n2!=NULL){
        if(n1->data==n2->data){
            n1 = n1->next;
            n2 = n2->next;
        }
        else{
            same=0;
            break;
        }
    }
    if(n1==NULL || n2==NULL)        //odd order hence atleast one should be null
        return same;
    return same==1;
}

void ispalindrome(node* head){
    node* slow=head;
    node* fast=head;
    node* prevslow;
    while(fast!=NULL && fast->next!=NULL){
        prevslow=slow;
        slow = slow->next;
        fast = fast->next->next;    
    }
    //for odd element list, now slow points to mid element
    node* sptr = slow->next;
    reverse(&sptr);
    slow->next=sptr;
    if(compareList(head,sptr)){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    cout<<endl;
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
    cnode = addnode(cnode,3);
    cnode = addnode(cnode,2);
    cnode = addnode(cnode,1);
    print(head);
    ispalindrome(head);
    //reverse(&mid);
    
    return 0;
}
