#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node
{
	int data;
	struct Node* next;
};
struct Node * head;
void print()
{
	struct Node* pNav=head;
	printf("List is: ");
	while(pNav!=NULL)
	{
		printf("%d ",pNav->data);
		pNav=pNav->next;	
	}
	printf("\n");
}

void insert(int data,unsigned int pos)
{
	if(pos>count+1)
	{
		printf("Position out of bounds\n");
		return;
	}
	else
	{
		int i;
		struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
		struct Node* pNav=head;
		newNode->data=data;
		if(pos==1)
		{
			newNode->next=head;
			head=newNode;
		}
		else
		{
			for(i=1;i<pos-1;i++)
			pNav=pNav->next;
			newNode->next=pNav->next;
			pNav->next=newNode;
		}
		count++;
	}
}

void delete(unsigned int pos)
{
	
	struct Node* temp=head;
	if(pos>count)
	{
		printf("position out of list\n");
		return;
	}
	if(pos==1 && temp!=NULL)
	{
		head=head->next;
		free(temp);
	}
	else
	{
		int i;
		for(i=0;i<pos-2;i++)
		temp=temp->next;
		struct Node* oldNode=temp->next;
		temp->next=oldNode->next;
		free(oldNode);
	}
	count--;
	
}

int main(void)
{
	head=NULL;
	int i,n,x;
	unsigned char exit=0;
	insert(1,1);
	insert(5,2);
	insert(7,3);
	insert(9,4);
	insert(10,5);
	print();
	
	while(exit==0)
	{
		printf("Enter a position to delete: ");
		scanf("%d",&n);
		delete(n);
		print();
		printf("Continue or exit?\n");
		printf("0. continue\n");
		printf("1. exit\n");
		scanf("%u",&exit);
	}
	return 0;
}
