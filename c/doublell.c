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
void deletenode()
{
ptr=header;
while(ptr->rlink!=NULL)
ptr=ptr->rlink;
ptr->llink->rlink=NULL;
free(ptr);
display();
}
void createnode()
{
int ch=1;
struct node*new;
header=(struct node*)malloc(sizeof(struct node));
header->data=NULL;
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
void insertmid(int item)
{
struct node*new;
new=(struct node*)malloc(sizeof(struct node));
if(new==NULL)
{
	printf("no allocation");
	return;
}
ptr=header;
while(ptr->rlink!=NULL && ptr->data!=item)
	ptr=ptr->rlink;
if(ptr->data==item)	
{
new->rlink=ptr->rlink;
new->llink=ptr;
ptr->rlink=new;
printf("enter value:");
scanf("%d",&(new->data));
if(ptr->rlink!=NULL)
	ptr->rlink->llink=new;
}
else
printf("no item found");
display();
}
void main()
{
int item;
createnode();
printf("enter the data item in which new node is to be inserted after the data item");
scanf("%d",&item);
insertmid(item);//insertion
deletenode();
}
