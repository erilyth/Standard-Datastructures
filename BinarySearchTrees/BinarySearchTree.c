#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};

struct Node* top=NULL;

struct Queue{
	struct Node* value;
	struct Queue* next;
}; //The queue's elements are pointers to nodes in the BST

struct Queue* head=NULL;
struct Queue* tail=NULL;

void enqueue(struct Node* x)
{
	struct Queue* temp=malloc(sizeof(struct Queue));
	temp->value=x; //We are adding the BST node pointer to the queue.
	temp->next=NULL;
	if(head==tail && head==NULL)
	{
		head=temp;
		tail=head;
	}
	else
	{
		tail->next=temp;
		tail=tail->next;
	}
}

struct Node* dequeue()
{

	struct Node* temp;
	if(head==tail && head!=NULL)
	{
		temp=head->value;
		head=NULL;
		tail=NULL;
		return temp; //We return the BST node pointer at the current head.
	}
	else if(head!=NULL)
	{
		temp=head->value;
		head=head->next;
		return temp; //We return the BST node pointer at the current head.
	}
}

int is_empty()
{
	if(head==tail && head==NULL)
		return 1;
	else
		return 0;
}

void bfs(struct Node* t1)
{
	if(t1!=NULL)
		enqueue(t1);
	while(is_empty()!=1)
	{
		struct Node* tempo=dequeue();
		if(tempo->left!=NULL)
			enqueue(tempo->left);
		if(tempo->right!=NULL)
			enqueue(tempo->right);
		printf("%d ", tempo->val);
	}
}

void preordertraverse(struct Node* t1)
{	
	if(t1!=NULL)
	{
		printf("%d ", t1->val);
		preordertraverse(t1->left);
		preordertraverse(t1->right);
	}
}

void inordertraverse(struct Node* t1)
{
	if(t1!=NULL)
	{
		inordertraverse(t1->left);
		printf("%d ", t1->val);
		inordertraverse(t1->right);
	}
}

void postordertraverse(struct Node* t1)
{
	if(t1!=NULL)
	{
		postordertraverse(t1->left);
		postordertraverse(t1->right);
		printf("%d ", t1->val);
	}
}

void insert(int x)
{
	struct Node* temp=top;
	struct Node* temp2=malloc(sizeof(struct Node));
	temp2->val=x;
	temp2->left=NULL;
	temp2->right=NULL;
	while(1)
	{
		if(temp==NULL)
		{
			top=temp2;
			break;
		}
		else if(temp->val<x && temp->right==NULL)
		{
			temp->right=temp2;
			break;
		}
		else if(temp->val>=x && temp->left==NULL)
		{
			temp->left=temp2;
			break;
		}
		else if(temp->val<x)
			temp=temp->right;
		else
			temp=temp->left;
	}
}

int main()
{
	insert(5);
	insert(4);
	insert(3);
	insert(10);
	insert(1);
	inordertraverse(top);
	printf("\n");
	preordertraverse(top);
	printf("\n");
	postordertraverse(top);
	printf("\n");
	bfs(top); //The bfs takes the top pointer of the BST and then its adds the pointer to the queue, then we follow the general bfs method.
	return 0;
}
