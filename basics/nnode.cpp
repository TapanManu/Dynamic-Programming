#include<iostream>
#include<bits/stdc++.h>
								//Nth node from last
using namespace std;

struct node{
	int data;
	node* next;
}*cur,*ptr,*head,*last;

stack <node*> s;

node* createNode(int data){
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void addNode(node *cur){
	int data;
	cout<<"enter data to be inserted";
	cin>>data;
	node* tmp = createNode(data);
	cur->next = tmp;
	cur = tmp;
}

void traverse(){
	ptr = head;
	while(ptr->next!=NULL){
		s.push(ptr);
		ptr = ptr->next;
	}
	s.push(ptr);
}


int main(){
	const int MAX=5;
	if(head==NULL){
		head = createNode(1);
		ptr = head;
	}
	char c='y';
	while(c=='y'){
		addNode(ptr);
		cout<<"do you want to continue inserting(y/n)?\n";
		cin>>c;
	}

	int n;
	cout<<"get the value of n\n";
	cin>>n;
	if(n>MAX){
		cout<<"limit reached";
		return 1;
	}
	traverse();
	while(!s.empty() && --n)
		s.pop();

	cout<<"nth node from last:"<<s.top()->data;
}






