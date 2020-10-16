#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node*header,*ptr,*ptr1;
void display()
{
ptr=header->link;
if(ptr==NULL)
{
	printf("\tno element in list\n");
	return;
}
while(ptr->link!=NULL)
{
	printf("%d->",ptr->data);
	ptr=ptr->link;
}
printf("\n");
}
void createnode()
{
printf("\tcreating node:\n");
int ch=1;
struct node*new;
header=(struct node*)malloc(sizeof(struct node));
header->data=NULL;
header->link=header;
ptr=header;
do{
new=(struct node*)malloc(sizeof(struct node));
if(new==NULL)
{
	printf("\tno allocation\n");
	return;
}
printf("\tenter the value into new node\n");
scanf("%d",&(new->data));
ptr->link=new;
new->link=NULL;
ptr=new;
printf("\tdo you want ot continue inserting node(1/0)\n");
scanf("%d",&ch);
}while(ch==1);
display();
}
void searchitem(int x)
{
ptr=header->link;
int pos=1;
if(ptr==NULL)
{
		printf("no list");
		return;
}
while(ptr->data!=x && ptr->link!=NULL)
{
ptr=ptr->link;
pos+=1;
}
if(ptr->data==x)
{
printf("%d",pos);
}
else
{
printf("no element found");
}
}

void main()
{
int item;
createnode();
printf("enter item to be searched");
scanf("%d",&item);
searchitem(item);
}
