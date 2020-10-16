#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *llink;
struct node *rlink;
};
struct node*ptr,*header;
void display()
{
ptr=header;
printf("\tthe linked list consist of:\n");
while(ptr->rlink!=NULL)
{
	printf("%d<->",ptr->data);
	ptr=ptr->rlink;
}
printf("\n");
}
void createnode()
{
int ch=1;
struct node*new;
header=(struct node*)malloc(sizeof(struct node));
header->llink=NULL;
header->rlink=NULL;
ptr=header;
do{
new=(struct node*)malloc(sizeof(struct node));
printf("\tenter data value");
scanf("%d",&(ptr->data));
new->llink=ptr;
new->rlink=NULL;
ptr->rlink=new;
ptr=new;
printf("\tdo you want to add more nodes(1/0)?\n");
scanf("%d",&ch);
}while(ch==1);
display();
}
void removeeven()
{
struct node *ptr1;  
ptr=header;
if(ptr==NULL)
{
	printf("no element");
	return;
}
while(ptr->rlink!=NULL)
{
if((ptr->data)%2==0)
{
	if(ptr->llink!=NULL)
		ptr->llink->rlink=ptr->rlink;
	else
		header->rlink=ptr->rlink;
	if(ptr->rlink!=NULL)
	{
		ptr->rlink->llink=ptr->llink;
	}
	ptr1=ptr;
	free(ptr1);
}
ptr=ptr->rlink;
}
display();
}
void main()
{
int item;
createnode();
removeeven();
}
