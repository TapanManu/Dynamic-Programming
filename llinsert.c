#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*link;
};
struct node* header,*ptr,*new;
void insertbeg()
{
new=(struct node*)malloc(sizeof(struct node));
if(new==NULL)
{
printf("memory not available");
return;
}
printf("read data");
scanf("%d",&(new->data));
new->link=header->link;
header->link=new;
}
void insertend()
{
new=(struct node*)malloc(sizeof(struct node));
struct node*ptr;
ptr=header;
if(new==NULL)
{
printf("memory not available");
return;
}
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
printf("read data");
scanf("%d",&(new->data));
ptr->link=new;
new->link=NULL;
}
void insertmid(int x)
{
new=(struct node*)malloc(sizeof(struct node));
struct node*ptr;
ptr=header;
if(new==NULL)
{
printf("memory not available");
return;
}
while((ptr->data!=x)&&(ptr->link!=NULL))
{
ptr=ptr->link;
}
if(ptr->data==x && ptr->link==NULL)
{
	printf("no node after key node");
	return;
}
else if(ptr->link==NULL)
	{
		printf("key element is not found");
		return;
	}
else
{
printf("read data");
scanf("%d",&(new->data));
new->link=ptr->link;
ptr->link=new;
}
}
void display()
{
ptr=header->link;
while(ptr!=NULL)
{
printf("%d->",ptr->data);
ptr=ptr->link;
}
printf("\n");
}
void main()
{
header=(struct node*)malloc(sizeof(struct node));
header->data=NULL;
header->link=NULL;
int d=0,choice=0,item;
ptr=header;
do//entering values to LINKED LIST
{
new=(struct node*)malloc(sizeof(struct node));
ptr->link=new;
printf("enter the data to  linked list");
scanf("%d",&(new->data));
new->link=NULL;
ptr=new;
printf("enter 1 to continue inserting data");
scanf("%d",&d);
}while(d==1);
display();
do//menu driven program
{
printf("1.insertion at beginning");
printf("2.insertion at end");
printf("3.insertion at middle");
printf("4.display");
printf("select your choice");
scanf("%d",&choice);
switch(choice)
{
	case 1:
				{
					insertbeg();
					break;
				}
	case 2:
				{
					insertend();
					break;
				}				
	case 3:
			{
				printf("enter item");
					scanf("%d",&item);
					insertmid(item);
					break;
			}
	case 4:
			{display();
				break;
			}
	default:
			printf("wrong choice");
}
printf("do you want to continue INSERTION");
scanf("%d",&d);
}while(d==1);

free(new);
free(ptr);
free(header);
}



