#include<stdio.h>
#include<stdlib.h>


// create a struct called `Node` that holds an int
// and pointers to two other Node structs
struct Node{
	int val;
	struct Node* left;
	struct Node* right;
};

// create the pointer of type Node called 'top' and set its value to NULL
struct Node* top=NULL;

// create a Queue struct that holds a Node Struct and another Queue Struct
struct Queue{
	struct Node* value;
	struct Queue* next;
}; //The queue's elements are pointers to nodes in the BST

// create pointers 'head' and 'tail' that point to Queue types and set their values
// to null
struct Queue* head=NULL;
struct Queue* tail=NULL;

// create enqueue function that takes a pointer to a Node struct and does
// not return anything (noted by the 'void' return type)
void enqueue(struct Node* x)
{
	// create a pointer 'temp' that points to a heap address with enough space to
	// hold a Queue struct
	struct Queue* temp=malloc(sizeof(struct Queue));
	// set the `temp.value` to x
	temp->value=x; //We are adding the BST node pointer to the queue.
	// set `temp.next` to NULL
	temp->next=NULL;
	// if this tree is empty
	if(head==tail && head==NULL)
	{
		// set the head to this new Node and set tail to the head
		head=temp;
		tail=head;
	}
	else
	{
		// set tail.next = temp (which is a struct of type Queue)
		tail->next=temp;
		// set tail to next (which is a pointer to Node set on line 34)
		tail=tail->next;
	}
}

// declare a dequeue function that takes no arguments and returns a pointer to
// a Node struct
struct Node* dequeue()
{
	// set temp to a pointer to a Node struct
	struct Node* temp;
	if(head==tail && head!=NULL)
	{
		// temp to the value of head
		temp=head->value;
		head=NULL;
		tail=NULL;
		return temp; //We return the BST node pointer at the current head.
	}
	else if(head!=NULL)
	{
		// set temp to the value of head
		temp=head->value;
		// set head to the next value of head
		head=head->next;
		return temp; //We return the BST node pointer at the current head.
	}
}

// a function that returns 0 or 1 and references the global variables
// `head` and `tail` set on line 23 and 24 and mutated elsewhere
int is_empty()
{
	if(head==tail && head==NULL)
		return 1;
	else
		return 0;
}

// declare bfs that will conduct a breadth first search of a tree
// and print out results as they're encountered
void bfs(struct Node* t1)
{
	// if the t1 is not null, enqueue it to be traversed
	if(t1!=NULL)
		enqueue(t1);
	// while is_empty returns false
	while(is_empty()!=1)
	{
		// create tempo, a pointer to the Node returned by dequeue
		struct Node* tempo=dequeue();
		// if there are Nodes to the left, enqueue them
		if(tempo->left!=NULL)
			enqueue(tempo->left);
		// if there are Nodes to the right, enqueue them
		if(tempo->right!=NULL)
			enqueue(tempo->right);
		// print the value of this Node
		printf("%d ", tempo->val);
		// go back to top of while loop until
	}
}

// recursive depth first traversal that
// prints values out as they're encountered
void preordertraverse(struct Node* t1)
{
	// if the Node is NULL do nothing
	if(t1!=NULL)
	{
		// print the Node's value
		printf("%d ", t1->val);
		// recurse down the left side of the tree if
		// more Nodes exist
		preordertraverse(t1->left);
		// Once left nodes have been traversed,
		// traverse the right side nodes
		preordertraverse(t1->right);
	}
}

// depth first traversal that prints values
// starting at the bottom left Node, and then in order (favoring left then right)
// back up from there
void inordertraverse(struct Node* t1)
{
	if(t1!=NULL)
	{
		inordertraverse(t1->left);
		printf("%d ", t1->val);
		inordertraverse(t1->right);
	}
}

// depth first traversal that print values
// starting at the bottom right node and then in order (favoring right then left)
// back up from there
void postordertraverse(struct Node* t1)
{
	if(t1!=NULL)
	{
		postordertraverse(t1->left);
		postordertraverse(t1->right);
		printf("%d ", t1->val);
	}
}

// function to insert an int value into a binary tree
void insert(int x)
{
	// create a pointer called temp that points to the top Node of the tree
	struct Node* temp=top;
	// allocate heap space for a new Node
	struct Node* temp2=malloc(sizeof(struct Node));
	// set the new Node's value to x and left and right pointers to NULL
	temp2->val=x;
	temp2->left=NULL;
	temp2->right=NULL;
	// Start while loop to place the Node in the appropriate position
	while(1)
	{
		// Note: `temp` is a pointer reference to the `top` Node
		if(temp==NULL)
		{
			// if the top Node and the new node are equal, exit
			top=temp2;
			break;
		}
		// if top value is less than x and doesn't have a right Node
		// place the new Node as the right address of the top Node
		else if(temp->val<x && temp->right==NULL)
		{
			temp->right=temp2;
			break;
		}
		// if top value is greater or equal to x and the left Node is NULL
		// place the new Node as the left address of the top Node
		else if(temp->val>=x && temp->left==NULL)
		{
			temp->left=temp2;
			break;
		}
		// if the top value is less than x, place the new Node as the right
		// address of the Top Node
		else if(temp->val<x)
			temp=temp->right;
		// set temp (previously the top node) to be the left address of the top node.
		// since we're in a while loop, this will loop back through this process with
		// `temp` now set to the address of the left hand Node of the previous loop
		else
			temp=temp->left;
	}
}

// main function, inserts values into the tree and calls the various traversal
// functions
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
