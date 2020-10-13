#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* next;
}*head,*ptr,*cur,*odd,*even,*ohead,*ehead;

node* createNode(int data){
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

node* addNode(int data){
	node* tmp = createNode(data);
	cur->next = tmp;
	cur = tmp;
	return cur;
}

void segregate(){
	int count=0;
	ptr = head;
	node* tmp = new node;
	ehead = new node;
	ohead = new node;
	while(ptr!=NULL){
		node* tmp = new node;
		tmp->data = ptr->data;
		tmp->next = NULL;
		if(count%2==0){
			if(ptr==head || head->next==ptr){
				ehead->data = ptr->data;
				ehead->next = NULL;
				even = ehead;
			}
			else{
			even->next=tmp;
			even =tmp;
			}
		}
		else{
			if(ptr==head || head->next==ptr){
				ohead->data = ptr->data;
				ohead->next = NULL;
				odd = ohead;
			}
			else{
			odd->next = tmp;
			odd=tmp;
			}
		}
		ptr = ptr->next;
		count++;
	}
}

void traverse(node* head){
	cur = head;
	while(cur->next!=NULL){
		cout<<cur->data<<"->";
		cur=cur->next;
	}
	cout<<cur->data;
	cout<<"\n";
}
int main(){
	if(head==NULL){
		head = createNode(1);
		cur = head;
	}
	cur = addNode(2);
	cur = addNode(3);
	cur = addNode(4);
	cur = addNode(5);
	cur = addNode(6);
	traverse(head);
	segregate();
	traverse(ohead);
	traverse(ehead);
	return 0;
}
