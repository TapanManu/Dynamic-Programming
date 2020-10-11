#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	node *next;
}*cur,*head,*ptr;

node* createNode(){
	node *temp = new node;
	cout<<"enter data to the node\n";
	cin>>temp->data;
	temp->next=NULL;		//next pointer
	return temp;
}

void addNode(){				//dynamic adding o(1)
	cout<<ptr->data<<"\n";
	cur = createNode();
	ptr->next = cur;
	ptr = cur;
}

void traverse(){			//traversing  o(n)
	ptr=head;
	if(ptr==NULL){
		cout<<"empty list";
		return;
	}
	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
}

node* deleteNode(){
	ptr=head;
	node* prev = new node;
	while(ptr->next!=NULL){
		prev = ptr;
		ptr = ptr->next;
	}
	if(ptr==head){
		return head;
	}
	if(prev==NULL){
		ptr=NULL;
		return NULL;
	}
	//cout<<"prev:"<<prev->data;
	prev->next = NULL;
	return ptr;
}

int main(){
	head=ptr=NULL;
	if (head == NULL){
		cout<<"initialise to header\n";
		head = createNode();
		cout<<"Head data:"<<head->data<<"\n";
		ptr = head;
	}
	int c = 0;			//count value
	/*while(c++<3){		//o(n)
		addNode();
	}*/
	traverse();
	node *del = deleteNode();
	if(del==head)
		head=NULL;
	if(del!=NULL)
		delete del;
	cout << "\n";
	traverse();
	return 0;
}
