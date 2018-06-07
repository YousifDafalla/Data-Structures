//Stack LinkedList implementation
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void Push(int x)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=x;
	newNode->next=head;
	head=newNode;
}

void Pop()
{
	if(head==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	struct Node* temp=head;
	head=head->next;
	free(temp);
}

unsigned int isEmpty()
{
	if(head==NULL)
	return 1;
	else
	return 0;
}

int Top()
{
	if(!isEmpty())
	return head->data;
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
int main()
{
	head=NULL;
	Push(4);
	Push(10);
	Push(15);
	Push(20);
	Push(25);
	print();
	Pop();
	print();
	return 0;
}
