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
void deletefront()
{
ptr=header->link;
if(ptr==NULL)
{		printf("no list");
			return;
}
header->link=ptr->link;
free(ptr);
}
void deleteend()
{

ptr=header->link;
ptr1=header;
if(ptr==NULL)
{
		printf("no list");
		return;
}
while(ptr->link!=NULL)
{
ptr1=ptr;
ptr=ptr->link;
}

ptr1->link=NULL;
free(ptr);
}
void deletemiddle(int x)
{
ptr=header->link;
ptr1=header;
if(ptr==NULL)
{
		printf("no list");
		return;
}
while(ptr->data!=x && ptr->link!=NULL)
{
ptr1=ptr;
ptr=ptr->link;
}
if(ptr->data==x)
{
ptr1->link=ptr->link;
free(ptr);
}
else
{
printf("no element found");
}
}
void main()
{
int ch=1,choice,item;
createnode();
do{
printf("1.deletion from beginning");
printf("2.deletion from middle");
printf("3.deletion from end");
printf("select the choice");
scanf("%d",&choice);
switch(choice)
{
	case 1:
							{
								deletefront();
								break;
							}
	case 2:
							{
								printf("enter the item to be deleted");
								scanf("%d",&item);
								deletemiddle(item);
								break;
							}
	case 3:
							{
								deleteend();
								break;
							}
	case 4:
							{
								display();
								break;
							}
	default:
								printf("wrong choice");
}
printf("do you want to continue deletion?(1/0)");
scanf("%d",&ch);
}while(ch==1);
}

