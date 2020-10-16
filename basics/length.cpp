#include<iostream>
#include<bits/stdc++.h>

using namespace std;

static int length=0;

struct node{
	int data;
	node* next;
}*head,*ptr;

node* createNode(int data){
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

node* addNode(node* ptr){
	int data;
	cout<<"enter data\n";
	cin>>data;
	node* tmp = createNode(data);
	ptr->next = tmp;
	ptr=tmp;
	return ptr;
}

int iterLength(){
	int len=0;
	ptr = head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
		len++;
	}
	return ++len;
}

void reclen(node* ptr){
	if(ptr==NULL)
		return ;
	reclen(ptr->next);
	length++;
}

int main(){
	if(head==NULL){
		head = createNode(1);
		ptr = head;
	}
	ptr = addNode(ptr);
	ptr = addNode(ptr);
	cout<<"length by iteration:"<<iterLength()<<"\n";
	reclen(head);
	cout<<"length by recursion:"<<length<<"\n";
}
