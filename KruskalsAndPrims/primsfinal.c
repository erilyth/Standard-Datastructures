#include<stdio.h>
#include<stdlib.h>

//This is the Iterative Heap which is faster!!

struct Node{
	long long int val;
	long long int weight;
	struct Node* next;
};

//This works!
long long int finmarked[100000]={0};
long long int marked[1000005]={0};
long long int visited=0;
//The final graph is build in this list
struct Node* mylist[1000005]={NULL};
//For checking if cycles are present or not
long long int AA[1000005];
//Heap uses arrays A, B, C to store x, y and weight of edge
//where x<y, and when we remove the edge from the heap we add the edge from x to y and from y to x
long long int A[1000005]={0};
long long int B[1000005]={0};
long long int C[1000005]={0};
long long int count=0;
long long int sum=0;

void swapper(long long int a, long long int b)
{
	long long int temp,temp2,temp3;
	temp=A[a]; temp2=B[a]; temp3=C[a];
	A[a]=A[b]; B[a]=B[b]; C[a]=C[b];
	A[b]=temp; B[b]=temp2; C[b]=temp3;
	return;
}

void worker(long long int j) //Goes up the tree swapping with the parent wherever required.
{
	long long int temp,temp2,temp3;
	while(j>=2)
	{
		if(A[j/2]>A[j])
		{
			swapper(j,j/2);
			j=j/2;
		}
		else
			break;
	}
}

void insert(long long int x, long long int y, long long int vals)
{
	count++;
	A[count]=vals;
	B[count]=x;
	C[count]=y;
	worker(count);
}

//Accepted remover code!
void remover(int i) //Shifts down the tree swapping with the children whenever required.
{
	while(i<=count)
	{
		if(i*2<=count)
		{
			if((i*2+1<=count && A[i*2]<A[i] && A[i*2]<A[i*2+1]) || (A[i*2]<A[i] && i*2+1>count))
			{
				swapper(i,i*2);
				i=i*2;
			}
			else if(i*2+1<=count && A[i*2+1]<A[i] && A[i*2+1]<=A[i*2])
			{
				swapper(i,i*2+1);
				i=i*2+1;
			}
			else
				break;
		}
		else
			break;
	}
}

void deletetop()
{
	if(count>0)
	{
		A[1]=A[count];
		B[1]=B[count];
		C[1]=C[count];
		count--;
		remover(1);
	}
}

void inserttoheap(long long int a)
{
	marked[a]=1; //This tells us when to insert the edges in to heap and when not to
	struct Node* temp=mylist[a];
	while(temp!=NULL)
	{
		if(marked[temp->val]==0) //If marked of that node is 1 then that means we have already visited all its neighbours so this endge has already been visited
			insert(a,temp->val,temp->weight);
		temp=temp->next;
	}
}

int main()
{
	long long int sum=0,i,j,k,n,m,a,b,c;
	visited=0;
	scanf("%lld%lld", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		struct Node* temp=malloc(sizeof(struct Node));
		temp->val=b;
		temp->weight=c;
		temp->next=mylist[a];
		mylist[a]=temp;
		struct Node* temp2=malloc(sizeof(struct Node));
		temp2->val=a;
		temp2->weight=c;
		temp2->next=mylist[b];
		mylist[b]=temp2;
	}
	inserttoheap(a);
	//finmarked[a]=1; // a is inserted into final spanning tree
	while(count!=0 && visited<n-1)
	{
		long long int vals=B[1];
		long long int vals2=C[1];
		long long int weight=A[1];
		int state=0;
		deletetop();
		if(marked[vals]==0) //marked stores all the vertices that are present in the final spanning tree
		{
			//printf("%lld %lld %lld\n", vals2, vals, weight);
			inserttoheap(vals);
			visited++;
			sum+=weight;

		}
		if(marked[vals2]==0)
		{
			//printf("%lld %lld %lld\n", vals, vals2, weight);
			inserttoheap(vals2);
			visited++;
			sum+=weight;
		}
	}
	printf("%lld\n", sum);
	return 0;
}

