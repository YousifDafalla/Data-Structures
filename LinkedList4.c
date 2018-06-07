#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node
{
	int data;
	struct Node* next;
};
struct Node * head;

void print(struct Node* p)
{
	if(p==NULL)
	return;
	printf("%d ",p->data);
	print(p->next);
}


void printReverse(struct Node* p)
{
	if(p==NULL)
	return;
	printReverse(p->next);
	printf("%d ",p->data);
}
void insert(int data,unsigned int pos)
{
	if(pos>count+1)
	{
		printf("Position %d is out of bounds\n",pos);
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

void reverse()
{
	struct Node* temp1=head;
	struct Node* temp2=NULL;
	struct Node* next=head->next;
	while(temp1!=NULL)
	{
		next=temp1->next;
		temp1->next=temp2;
		temp2=temp1;
		temp1=next;
	}
	head=temp2;
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
	print(head);
	printf("\n");
	printReverse(head);
	return 0;
}
