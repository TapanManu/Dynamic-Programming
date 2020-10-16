#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node*header,*ptr1,*ptr2,*header1,*header2,*ptr;
void display(struct node *header)
{
ptr=header->link;
if(ptr==header)
{
	printf("\tno element in list\n");
	return;
}
while(ptr->link!=header->link)
{
	printf("%d->",ptr->data);
	ptr=ptr->link;
}
printf("\n");
}
struct node* createnode()
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
	return 0;
}
printf("\tenter the value into new node\n");
scanf("%d",&(new->data));
ptr->link=new;
new->link=header;
ptr=new;
printf("\tdo you want ot continue inserting node(1/0)\n");
scanf("%d",&ch);
}while(ch==1);
display(header);
return header;
}
void merge(struct node*header1,struct node*header2)
{
ptr1=header1->link;
ptr2=header2->link;
if(ptr1==header ||ptr2==header2)
	return;
header1->link=ptr2;
while(ptr2->link!=header2)
{
ptr2=ptr2->link;
}
ptr2->link=ptr1;
while(ptr1->link!=header1->link)
{
ptr1=ptr1->link;
}
display(header1);
free(header2);
}
void main()
{
header1=createnode();
header2=createnode();
merge(header1,header2);
}
