#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
	char place[25];
	struct node* link;
};
struct node *header,*ptr,*temp,*new;
void create_record()
{
	int x;
	header=(struct node*)malloc(sizeof(struct node));
	printf("enter the source details:");
	scanf("%s",header->place);
	header->link=header;
	temp=header;
	do{
	new=(struct node*)malloc(sizeof(struct node));
	printf("enter the place details:");
	scanf("%s",(new->place));
	temp->link=new;
	new->link=header;
	temp=new;
	printf("do you want to add more nodes?");
	scanf("%d",&x);
	}while(x==1);
}
void printrecord()
{
	ptr=header;
	printf("->");
	puts(header->place);
	ptr=ptr->link;
	while(ptr!=header)
	{
		printf("->");
		puts(ptr->place);
		ptr=ptr->link;	
	}
}
void add_new_record()
{
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("no data");
		return;
	}
	printf("enter new place to add:\n");
	scanf("%s",new->place);
	ptr=header;
	while(ptr->link!=header)
	{
		ptr=ptr->link;
	}
	ptr->link=new;
	new->link=header;
}
void replace_destination()
{
	char dest[25];
	int flag=0;
	printf("enter the place to be replaced:");
	scanf("%s",dest);
	ptr=header->link;
	while(ptr!=header)
	{
		if(strcmp(ptr->place,dest)==0)
		{
			flag=1;
			printf("replace data\n");
			scanf("%s",ptr->place);
		}
		ptr=ptr->link;
	}
	if(flag==0)
	{
		printf("no place in the list\n");
	}
}
void reorder_dest()
{	int flag=0;
	//delete the destination from the corresponding positition and reordering the destination back to the end
	new=(struct node*)malloc(sizeof(struct node));
	ptr=header;
	char replace[25];
	printf("enter the place to be reordered:");
	scanf("%s",replace);
	ptr=header->link;
	while((strcmp(ptr->place,replace)!=0) && ptr!=header)
	{
		temp=ptr;
		ptr=ptr->link;
	}
	if(strcmp(ptr->place,replace)==0)
	{
		if(ptr->link==header)
			return;
		temp->link=ptr->link;
		new=ptr;
		while(ptr->link!=header)		
		{	
			ptr=ptr->link;
		}
		ptr->link=new;
		new->link=header;
	}
	else if(ptr==header)
	{
		printf("no change at all!");
	}
}
void deletedest()
{
	char dest[25];
	printf("enter the palce to be deleted");
	scanf("%s",dest);
	ptr=header->link;
	while(strcmp(ptr->place,dest)!=0 &&ptr!=header)
	{
		temp=ptr;
		ptr=ptr->link;
	}
	if(strcmp(ptr->place,dest)==0)
	{
		temp->link=ptr->link;
	}
	else
	{
		printf("place not in brochure");
	}
}
void main()
{
	create_record();
	printrecord();
	add_new_record();
	printrecord();
	replace_destination();
	printrecord();
	reorder_dest();
	printrecord();
	deletedest();
	printrecord();

}	




