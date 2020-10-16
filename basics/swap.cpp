#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node* next;
}*ptr,*tmp,*head;

node* createNode(int data){
	ptr = new node;
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void swapnode(node *first,node* second){
	if(first==NULL || second==NULL || first==second)
		return;														//no swapping

	node* prevfirst = head;
	node* prevsecond = head;

	if(first==head)
		head = second;
							//prevfirst becomes equal to first when both are head

	while(prevfirst!=first && prevfirst->next!=first)
		prevfirst = prevfirst->next;

	while(prevsecond->next!=second)
		prevsecond = prevsecond->next;

	if(prevsecond==first)
		prevsecond=second;
	
	if(prevfirst==second)
		prevfirst=first;

	tmp = first->next;
	first->next = second->next;
	second->next = tmp;

	if(prevfirst!=first)
		prevfirst->next = second;

	prevsecond->next = first;
}

void traverse(){
	ptr = head;
	while(ptr->next!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<ptr->data<<"\n";
}

int main(){
	if(head==NULL){
		head = createNode(1);
	}
	
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	traverse();
	swapnode(head,head);
	traverse();
	return 0;

}
