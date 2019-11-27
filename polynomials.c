#include <stdlib.h>
#include<stdio.h>
struct node{
	int coeff;
	int exp;
	struct node* link;
};
struct node *header,*header1,*header2,*header3,*header4,*ptr,*ptr1,*ptr2,*ptr3,*ptr4,*new,*s;
void display(struct node*header)
{
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=header->link;
	while(ptr!=NULL)
	{
		printf("+%dx^%d",ptr->coeff,ptr->exp);
		ptr=ptr->link;
	}
}
void createnode(struct node *header)//when addition ,you need to specify header for header 1 and header2 within parenthesis for creation of two lists. 
{
	int x;
	printf("enter the polynomial:");
	header->link=NULL;
	ptr=header;
	do{
		new=(struct node*)malloc(sizeof(struct node));
		printf("enter the data");
		scanf("%d",&(new->coeff));
		printf("enter the exponent");
		scanf("%d",&(new->exp));
		ptr->link=new;
		new->link=NULL;
		ptr=new;
		printf("do you want to add any more expressions(1/0)?");
		scanf("%d",&x);
	}while(x==1);
	display(header);
}

void addpoly(struct node*header1,struct node*header2,struct node*header3)
{
	ptr1=header1->link;
	ptr2=header2->link;
	header3->link=NULL;
	ptr3=header3;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		new=(struct node*)malloc(sizeof(struct node));
		ptr3->link=new;
		if(ptr1->exp<ptr2->exp)
		{
			new->exp=ptr1->exp;
			new->coeff=ptr1->coeff;
			ptr1=ptr1->link;
			ptr3=new;
		}
		else if(ptr2->exp<ptr1->exp)
		{
			new->exp=ptr2->exp;
			new->coeff=ptr2->coeff;
			ptr2=ptr2->link;
			ptr3=new;
		}
		else if(ptr1->exp==ptr2->exp)
		{
			new->exp=ptr1->exp;
			new->coeff=ptr1->coeff+ptr2->coeff;
			ptr1=ptr1->link;
			ptr2=ptr2->link;
			ptr3=new;
		}
	}
	while(ptr1!=NULL)
		{
			new=(struct node*)malloc(sizeof(struct node));
			ptr3->link=new;	
			new->exp=ptr1->exp;
			new->coeff=ptr1->coeff;
			ptr1=ptr1->link;
			ptr3=new;
		}
	while(ptr2!=NULL)
		{
			new=(struct node*)malloc(sizeof(struct node));
			ptr3->link=new;
			new->exp=ptr2->exp;
			new->coeff=ptr2->coeff;
			ptr2=ptr2->link;
			ptr3=new;
		}	
		printf("\n");
	display(header3);
}

void multpoly(struct node* header1,struct node* header2,struct node* header4)
{
	ptr1=header1->link;
	ptr4=header4;
	while(ptr1!=NULL)
	{
		ptr2=header2->link;
		while(ptr2!=NULL)
		{
			s=(struct node*)malloc(sizeof(struct node));
			ptr4->link=s;
			s->exp=(ptr1->exp)+(ptr2->exp);
			s->coeff=ptr1->coeff*(ptr2->coeff);
			ptr4=s;
			ptr2=ptr2->link;
		}
		ptr1=ptr1->link;
	}
	
	printf("\n");
	display(header4);
}
void main()
{
	header1=(struct node*)malloc(sizeof(struct node));
	if(header1==NULL)
	{
		printf("no header1");
	}
	header2=(struct node*)malloc(sizeof(struct node));
	if(header2==NULL)
	{
		printf("no header2");
	}
	header3=(struct node*)malloc(sizeof(struct node));
	if(header3==NULL)
	{
		printf("no header3");
	}
	header4=(struct node*)malloc(sizeof(struct node));
	if(header4==NULL)
	{
		printf("no header4");
	}
	createnode(header1);
	createnode(header2);
	//addpoly(header1,header2,header3);
	multpoly(header1,header2,header4);
}