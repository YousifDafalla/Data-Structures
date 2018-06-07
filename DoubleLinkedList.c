//Implementing double linked list in C
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;
void insertAtHead(int data)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=head;
	newNode->prev=NULL;
	if(head!=NULL)
	head->prev=newNode;
	head=newNode;
}

void insertAtTail(int data)
{
	struct Node* pNav=head;
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	if(head==NULL)
	{
		newNode->next=newNode->prev=NULL;
		head=newNode;
	}
	else
	{
		while(pNav->next!=NULL)
		{
			pNav=pNav->next;
		}
		pNav->next=newNode;
		newNode->prev=pNav;
		newNode->next=NULL;
	}
}

void print()
{
	struct Node* pNav=head;
	while(pNav!=NULL)
	{
		printf("%d ",pNav->data);
		pNav=pNav->next;
	}
	printf("\n");
}

void reversePrint()
{
	struct Node* pNav=head;
	if(pNav==NULL)
	return;
	while(pNav->next!=NULL)
	pNav=pNav->next;
	while(pNav!=NULL)
	{
		printf("%d ",pNav->data);
		pNav=pNav->prev;
	}
}
int main()
{
	head=NULL;
	insertAtHead(5);
	insertAtHead(4);
	insertAtHead(3);
	insertAtTail(8);
	print();
	reversePrint();
	return 0;
}
