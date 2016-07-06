#include<stdio.h>
#include<stdlib.h>

struct Node{
	long long int val;
	struct Node* next;
};

long long int minim=10000000;
long long int mult=1;
long long int finsum=0;
long long int finmult=1;
long long int stack[300005]={0};
long long int stackcount=0;
long long int state=0;
long long int count=0,n;
struct Node* mystor[300005]={NULL};
struct Node* mystor2[300005]={NULL};
long long int cost[300005]={0};
long long int marked[300005]={0};
long long int marked2[300005]={0};

void push(long long int a)
{
	stack[stackcount]=a;
	stackcount++;
}

void pop()
{
	stackcount--;
}

long long int top()
{
	if(stackcount!=0)
		return stack[stackcount-1];
	return 0;
}

void dfs2(long long int a)
{
	if(cost[a]==minim)
		mult++;
	if(cost[a]<minim)
	{
		minim=cost[a];
		mult=1;
	}
	struct Node* temp=mystor2[a];
	while(temp!=NULL)
	{
		if(marked2[temp->val]==0)
		{
			marked2[temp->val]=1;
			dfs2(temp->val);
		}
		temp=temp->next;
	}
}

void dfs(long long int a)
{
	struct Node* temp=mystor[a];
	while(temp!=NULL)
	{
		if(marked[temp->val]==0)
		{
			marked[temp->val]=1;
			dfs(temp->val);
		}
		temp=temp->next;
	}
	push(a);
}

int main()
{
	long long int tc,a,b,c,i,j,k,m;
	tc=1;
	for(k=0;k<tc;k++)
	{
		stackcount=0;
		count=1;
		for(i=0;i<300005;i++)
		{
			marked[i]=0;
			marked2[i]=0;
			mystor[i]=NULL;
			mystor2[i]=NULL;
		}
		finsum=0;
		finmult=0;
		scanf("%lld", &n);
		for(i=1;i<=n;i++)
			scanf("%lld", &cost[i]);
		scanf("%lld", &m);
		for(j=0;j<m;j++)
		{
			scanf("%lld%lld", &a, &b);
			struct Node* temp=malloc(sizeof(struct Node));
			temp->val=b;
			temp->next=mystor[a];
			mystor[a]=temp;
			struct Node* temp2=malloc(sizeof(struct Node));
			temp2->val=a;
			temp2->next=mystor2[b];
			mystor2[b]=temp2;
		}
		for(i=1;i<=n;i++)
		{
			if(marked[i]==0)
			{
				marked[i]=1;
				dfs(i);
			}
		}
		finsum=0;
		finmult=1;
		while(stackcount!=-1)
		{
			if(marked2[top()]==0)
			{
				marked2[top()]=1;
				minim=cost[top()];
				mult=0;
				dfs2(top());
				finsum+=minim;
				finmult=finmult*mult;
			}
			pop();
		}
		printf("%lld %lld\n", finsum, finmult%1000000007);
	}
	return 0;
}
