#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int value;
	struct Queue* next;
};

struct Queue* head=NULL;
struct Queue* tail=NULL;

void enqueue(int x)
{
	struct Queue* temp=malloc(sizeof(struct Queue));
	temp->value=x;
	temp->next=NULL;
	if(head==tail && head==NULL)
	{
		head=temp;
		tail=head;
	}
	else
	{
		head->next=temp;
		head=head->next;
	}
}

void dequeue()
{
	if(head==tail && head!=NULL)
	{
		tail=NULL;
		head=NULL;
	}
	else if(head!=NULL)
	{
		tail=tail->next;
	}
}

void front()
{
	if(tail!=NULL)
		printf("%d\n", tail->value);
}

void printtot()
{
	struct Queue* ptr=tail;
	while(ptr!=NULL)
	{
		printf("%d ", ptr->value);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()
{
	int a;
	int i,n,m;
	scanf("%d", &n);
	while(n!=5)
	{
		if(n==1)
		{
			scanf("%d", &a);
			enqueue(a);
		}
		if(n==2)
			dequeue();
		if(n==3)
			front();
		if(n==4)
			printtot();
		scanf("%d", &n);
	}
	return 0;
}
