#include<stdio.h>
#include<stdlib.h>

int A[100000];
int head=-1;
int tail=-1;

int sizeq;

void enqueue(int x)
{
	if(head==tail && head==-1)
	{
		tail=(tail+1);
		head=tail;
		A[tail]=x;
	}
	else
	{
		if((tail+1)%sizeq==head)
		{
			tail=(tail+1)%sizeq;
			A[tail]=x;
			head++;
			printf("Overlap\n");
		}
		else
		{
			tail=(tail+1)%sizeq;
			A[tail]=x;
		}
	}
}

void dequeue()
{
	if(head==tail && head!=-1)
	{
		head=-1;
		tail=-1;
	}
	else if(head!=-1)
	{
		head=(head+1)%sizeq;
	}
}

void front()
{
	if(head!=-1)
		printf("%d\n", A[head]);
}

void print()
{
	int temphead=head;
	while(temphead!=tail)
	{
		printf("%d ", A[temphead]);
		temphead=(temphead+1)%sizeq;
	}
	if(temphead==tail && temphead!=-1)
		printf("%d ", A[temphead]);
	printf("\n");
}

int main()
{
	scanf("%d", &sizeq);
	int a,b,c,i,j,k;
	scanf("%d", &c);
	while(c!=5)
	{
		if(c==1)
		{
			scanf("%d", &b);
			enqueue(b);
		}
		if(c==2)
			dequeue();
		if(c==3)
			front();
		if(c==4)
			print();
		scanf("%d", &c);
	}
}
