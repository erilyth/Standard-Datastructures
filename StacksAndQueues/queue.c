//Include header files 
#include <stdio.h>
#include <stdlib.h>

//Create Queue struct
struct Queue {
	int value;
	struct Queue* next;
};

//Initialising head and tail variables
struct Queue* head=NULL;
struct Queue* tail=NULL;

//Enqueuing a variable into the array
void enqueue(int x) {
	
	struct Queue* temp=malloc(sizeof(struct Queue));
	temp->value=x;
	temp->next=NULL;
	
	if(head==tail && head==NULL) {
		head=temp;
		tail=head;
	}
	else {
		head->next=temp;
		head=head->next;
	}

}

//Dequeues the element in the rear
void dequeue() {
	
	if(head==tail && head!=NULL) {
		tail=NULL;
		head=NULL;
	}
	else if(head!=NULL) {
		tail=tail->next;
	}

}

//Return the front element of the Queue
void front() {
	
	if(tail!=NULL)
		printf("%d\n", tail->value);
}

//Prints all the elements in the Queue
void printtot() {
	
	struct Queue* ptr=tail;
	//Traverses throught the array
	while(ptr!=NULL) {
		printf("%d ", ptr->value);
		ptr=ptr->next;
	}
	
	printf("\n");
}

//Main function
int main() {
	//Variable initialisation
	int i,n,m,a;
	scanf("%d", &n);

	//Menu driven method
	while(n!=5) {
		//Enqueues the element in the Queue
		if(n==1) {
			scanf("%d", &a);
			enqueue(a);
		}
		//Dequeues the element at the front
		if(n==2)
			dequeue();
		//Returns the element at the front
		if(n==3)
			front();
		//Prints all the elements of the Queue
		if(n==4)
			printtot();

		scanf("%d", &n);
	}

	return 0;
}
