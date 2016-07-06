#include<stdio.h>
#include<stdlib.h>

//This is the Iterative Heap which is faster!!

struct Node{
	long long int val;
	long long int weight;
	struct Node* next;
};

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

long long int findd(long long int i)
{
	if(AA[i]==0)
		return i;
	return findd(AA[i]);
}

void unions(long long int a, long long int b)
{
	long long int aa=findd(a);
	long long int bb=findd(b);
	AA[bb]=aa;
}

long long int m;

long long int partition(long long int start, long long int end, long long int pivot)
{
	long long int i,j,a,b,c,piv,temp,temp1,temp2;
	piv=A[pivot];
	temp=A[pivot];
	temp1=B[pivot];
	temp2=C[pivot];
	C[pivot]=C[end];
	B[pivot]=B[end];
	A[pivot]=A[end];
	A[end]=temp;
	B[end]=temp1;
	C[end]=temp2;
	long long int place=start;
	for(i=start;i<=end;i++)
	{	
		if(A[i]<=piv)
		{
			temp=A[place];
			temp1=B[place];
			temp2=C[place];
			A[place]=A[i];
			B[place]=B[i];
			C[place]=C[i];
			A[i]=temp;
			B[i]=temp1;
			C[i]=temp2;
			place++;
		}
	}
	return place-1;
}

void quick(long long int start, long long int end)
{
	long long int newpiv,random;
	while(start<end)
	{
		srand(time(NULL));
		random=rand();
		random=start+random%(end-start);
		newpiv=partition(start,end,random);
		if(newpiv-start<=end-newpiv)
		{
			quick(start,newpiv-1);
			start=newpiv+1;
		}
		else
		{
			quick(newpiv+1,end);
			end=newpiv-1;
		}
	}
}

int main()
{
	long long int i,j,k,n,a,b,c;
	visited=0;
	scanf("%lld%lld", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		A[i]=c;
		B[i]=a;
		C[i]=b;
	}
	count=0;
	sum=0;
	quick(0,m-1);
	while(count<m && visited<n-1)
	{
		a=A[count];
		b=B[count]; //Node 1
		c=C[count]; //Node 2
		count++;
		if(findd(b)!=findd(c))
		{
			visited++;
			sum+=a;
			unions(findd(b),findd(c));
		}
	}
	if(visited==n-1)
		printf("%lld\n", sum);
	else
		printf("-1\n");
	return 0;
}
