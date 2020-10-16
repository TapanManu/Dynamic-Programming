#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *llink;
struct node *rlink;
};
struct node*ptr,*header;
int flag=0;
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
void searchitem(int x)
{
ptr=header->rlink;
int pos=1;
if(ptr==NULL)
{
		printf("no list");
		return;
}
while(ptr->data!=x && ptr->rlink!=NULL)
{
ptr=ptr->rlink;
pos+=1;
}
if(ptr->data==x)
{
printf("%d",pos+1);
flag=1;
}
else if(flag==0)
{
printf("no element found");
}
}
void main()
{
int item;
createnode();
printf("enter the item to be searched");
scanf("%d",&item);
searchitem(item);


}
