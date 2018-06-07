#include<stdio.h>
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

void insert(int data)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	if(head==NULL)
	{
		newNode->next=NULL;
	}
	else
	{
		newNode->next=head;
	}
	head=newNode;
}

int main(void)
{
	head=NULL;
	int i,n,x;
	printf("How many numbers? ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number you want to insert: ");
		scanf("%d",&x);
		insert(x);
	}
	print();
	return 0;
}
