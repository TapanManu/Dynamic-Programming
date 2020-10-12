#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* next;
}*ptr1,*head1,*head2,*ptr2,*ptr,*tmp;

node* createNode(int data){
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

node* addNode(node* current){
	int data;
	cout<<"enter data:\n";
	cin>>data;
	tmp = createNode(data);
	current->next = tmp;
	current = tmp;
	return current;
}

void traverse(node* head){
	ptr = head;
	while(ptr->next!=NULL){
		cout<<ptr->data<<"->";
		ptr = ptr->next;
	}
	cout<<ptr->data<<"\n";
	
}

node* merge(node* head1,node* head2){
	node* head = new node;
	node* ptr = NULL;
	ptr1 = head1;
	ptr2 = head2;
	if(head1->data <= head2->data){
		head->data = head1->data;
		ptr1 = head1->next;
	}
	else{
		head->data = head2->data;
		ptr2 = head2->next;
	}
	ptr = head;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->data <= ptr2->data){
			ptr->next = createNode(ptr1->data);
			ptr1 = ptr1->next;
		}
		else{
			ptr->next = createNode(ptr2->data);
			ptr2 = ptr2->next;
		}
		if(ptr!=NULL)
			ptr = ptr->next;
	}
	while(ptr1!=NULL){
			ptr->next = createNode(ptr1->data);
			ptr = ptr->next;
			ptr1 = ptr1->next;
	}
	while(ptr2!=NULL){
			ptr->next = createNode(ptr2->data);
			ptr = ptr->next;
			ptr2 = ptr2->next;
	}
	return head;
}

int main(){
	if(head1==NULL && head2==NULL){
		head1 = createNode(1);
		head2 = createNode(2);
		ptr1 = head1;
		ptr2 = head2;
	}
	cout<<"first node\n";
	ptr1 = addNode(ptr1);
	ptr1 = addNode(ptr1);
	ptr1 = addNode(ptr1);

	cout<<"second node\n";
	ptr2 = addNode(ptr2);
	ptr2 = addNode(ptr2);
	ptr2 = addNode(ptr2);

	traverse(head1);
	traverse(head2);

	node* head = merge(head1,head2);
	traverse(head);

	return 0;
}
