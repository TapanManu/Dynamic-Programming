#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* next;
}*ptr,*head,*tmp,*current;

node* createNode(int data){
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void addNode(node* current){
	int data;
	cout<<"enter data to be entered"<<"\n";
	cin >> data;
	tmp = createNode(data);
	current->next = tmp;
	current = tmp;
}

void traverse(){
	ptr = head;
	while(ptr->next!=NULL){
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<ptr->data<<"\n";
}

void delmid(int data){
	node *prev = NULL;
	ptr = head;
	int key=1;
	while(ptr->data!=data){
		if(ptr->next==NULL){
			key=0;				//data absent
			break;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	if(key==1)
		prev->next = ptr->next;
}

void deldup(node* ptr){
	if(ptr->next==NULL)
		return;
	if(ptr->next!=NULL && ptr->data == ptr->next->data)
		delmid(ptr->next->data);
	deldup(ptr->next);
}



int main(){
	if(head==NULL){
		head = createNode(1);
		ptr = head;
	}
	//asssume list is sorted

	addNode(ptr);
	addNode(ptr);
	addNode(ptr);
	addNode(ptr);

	traverse();

	//delete duplicate elements
	deldup(head);

	traverse();

	return 0;			
}
