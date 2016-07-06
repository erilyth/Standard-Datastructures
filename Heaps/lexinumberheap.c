#include<stdio.h>
#include<stdlib.h>

//This is the Iterative Heap which is faster!!

struct Node{
	long long int val;
	struct Node* next;
};

long long int finans[1000005];
long long int fincount=0;
struct Node* mylist[1000005]={NULL};
long long int counts[1000005]={0};
long long int parent[1000005]={0};
long long int marked[1000005]={0};
long long int visited=0;
//The final graph is build in this list
//For checking if cycles are present or not

long long int AA[1000005];
//Heap uses arrays A, B, C to store x, y and weight of edge
//where x<y, and when we remove the edge from the heap we add the edge from x to y and from y to x
long long int A[1000005]={0};
long long int count=0;
long long int sum=0;

void swapper(long long int a, long long int b)
{
	long long int temp,temp2,temp3;
	temp=A[a]; 
	A[a]=A[b];
	A[b]=temp;
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

void insert(long long int vals)
{
	count++;
	A[count]=vals;
	worker(count);
}

void remover(long long int i) //Shifts down the tree swapping with the children whenever required.
{
	long long int temp,temp2,temp3;
	while(i<=count)
	{
		if(i*2+1<=count && A[i*2+1]>=A[i] && A[i*2]>=A[i])
			break;
		if(i*2+1<=count && A[i*2+1]<=A[i*2])
		{
			swapper(i,i*2+1);
			i=i*2+1;
		}
		else if((i*2+1<=count && A[i*2]<=A[i*2+1]) || (i*2<=count && A[i*2]<=A[i] && i*2+1>count))
		{
			swapper(i,i*2);
			i=i*2;
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
		count--;
		remover(1);
	}
}

int main()
{
	long long int a,b,c,i,j,n,m;
	scanf("%lld%lld", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld", &a, &b);
		struct Node* temp=malloc(sizeof(struct Node));
        temp->val=b;
        temp->next=mylist[a];
        mylist[a]=temp;
		counts[b]++;
	}
	for(i=1;i<=n;i++)
	{
		if(counts[i]==0)
			insert(i);
	}
	while(count>0)
	{
		long long int val=A[1];
		finans[fincount++]=val;
		counts[val]=-1;
		deletetop();
		struct Node* temp=mylist[val];
        while(temp!=NULL)
        {
            counts[temp->val]--;
	    	if(counts[temp->val]==0)
		    	insert(temp->val);
            temp=temp->next;
        }
	}
    if(fincount!=n)
    {
        int a=1;
        while(1){a=1-a;}
        printf("NO\n");
    }
    else
    {
        for(i=0;i<fincount;i++)
            if(i==fincount-1)
                printf("%lld\n", finans[i]);
            else
                printf("%lld ", finans[i]);
    }
	return 0;
}
