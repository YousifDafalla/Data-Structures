#include<stdio.h>
#include<stdlib.h>
#define max 10
int array[max];
int top=-1;

void Push(int x)
{
	if(top==max-1)
	{
		printf("Stack overflow\n");
		return;
	}
	array[++top]=x;
}

void Pop()
{
	if(top==-1)
	{
		printf("No element to pop\n");
		return;
	}
	top--;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}

int Top()
{
	return array[top];
}

void print()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
int main()
{
	//top=-1;
	Push(1);
	Push(2);
	Push(3);
	Pop();
	printf("%d",Top());
	return 0;
}
