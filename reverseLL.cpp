#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* next;
}*cur,*ptr,*head;

stack <int> s;
//reversing in o(1)

node* createNode(int data){
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void traverse(){
	ptr = head;
	while(ptr->next!=NULL){
		cout<<ptr->data<<"->";
		s.push(ptr->data);
		ptr=ptr->next;
	}
	cout<<ptr->data<<"\n";
	s.push(ptr->data);
}


void reverse(node* ptr){
	//ptr = new node;
	if(s.empty()){
		ptr=NULL;
		return;
	}
	ptr->data = s.top();
	//cout<<ptr->data<<"\n";
	s.pop();
	reverse(ptr->next);
}

int main(){
	head = NULL;
	if(head==NULL){
		head = createNode(1);
		
	}
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	
	traverse();

	ptr=head;
	reverse(ptr);
	cout<<"reversed liked list\n";
	traverse();
	return 0;
}
