#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	int weight;
	struct Node* next;
};

int marked[100000]={0};
int visited=0;
//The final graph is build in this list
struct Node* mylist[100000]={NULL};
//For checking if cycles are present or not, union find algorithm
int AA[100000]={0};
//Heap uses arrays A, B, C to store x, y and weight of edge
//where x<y, and when we remove the edge from the heap we add the edge from x to y and from y to x
int A[100000]={0};
int B[100000]={0};
int C[100000]={0};
int count=0;

void swapper(int a, int b)
{
	int temp,temp2,temp3;
	temp=A[a]; temp2=B[a]; temp3=C[a];
	A[a]=A[b]; B[a]=B[b]; C[a]=C[b];
	A[b]=temp; B[b]=temp2; C[b]=temp3;
	return;
}

void worker(int j) //Goes up the tree swapping with the parent wherever required.
{
	int temp,temp2,temp3;
	if(j>=2)
	{
		if(A[j/2]>=A[j])
		{
			swapper(j,j/2);
			worker(j/2);
		}
	}
}

void insert(int x, int y, int vals)
{
	if(x>y)
	{
		int temp=x;
		x=y;
		y=temp;
	}
	count++;
	A[count]=vals;
	B[count]=x;
	C[count]=y;
	worker(count);
}

void remover(int i) //Shifts down the tree swapping with the children whenever required.
{
	int temp,temp2,temp3;
	if(i>count)
		return;
	if(i*2<=count && A[i*2]<A[i*2+1])
	{
		if(A[i*2]<A[i])
		{
			swapper(i,i*2);
			remover(i*2);
		}
	}
	if(i*2+1<=count && A[i*2+1]<A[i])
	{
		swapper(i,i*2+1);
		remover(i*2+1);
	}
}

void deletetop()
{
	if(count>0)
	{
		A[1]=A[count];
		B[1]=B[count];
		C[1]=C[count];
		A[count]=10000000;
		B[count]=0;
		C[count]=0;
		count--;
		remover(1);
	}
}

int findd(int i)
{
	if(AA[i]==-1)
		return i;
	return findd(AA[i]);
}

void unions(int a, int b)
{
	int aa=findd(a);
	int bb=findd(b);
	AA[bb]=aa;
}

int main()
{
	int i,j,k,n,m,a,b,c;
	visited=0;
	scanf("%d%d", &n, &m);
	for(j=0;j<100000;j++)
		AA[j]=-1;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		insert(a,b,c);
	}
	while(count>0 && visited<n-1)
	{
		//printf("%d\n", count);
		a=A[1];
		b=B[1]; //Node 1
		c=C[1]; //Node 2
		deletetop();
		if(findd(b)!=findd(c))
		{
			visited++;
			struct Node* temp=malloc(sizeof(struct Node));
			temp->weight=a;
			temp->val=b;
			temp->next=mylist[c];
			mylist[c]=temp;
			struct Node* temp2=malloc(sizeof(struct Node));
			temp2->weight=a;
			temp2->val=c;
			temp2->next=mylist[b];
			mylist[b]=temp2;
			unions(findd(b),findd(c));
		}
	}
	for(i=1;i<=n;i++)
	{
		struct Node* temp=mylist[i];
		while(temp!=NULL)
		{
			printf("%d %d\t", temp->val, temp->weight);
			temp=temp->next;
		}
		printf("\n");
	}
	return 0;
}
