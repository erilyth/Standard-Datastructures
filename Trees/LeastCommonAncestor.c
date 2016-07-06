#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Use a stack to store paths when doing dfs, when we encounter a certain node, the values in the stack represent the path from the root to that node.
//We can get LCA also by storing intimes and outtimes etc

int stack[100010];
int stackhead=-1;
int afinarr[100010];
int bfinarr[100010];
int visited[100010]={0};
int a,b,acnt,bcnt;

struct LL{
	int val;
	struct LL* next;
};

struct LL* mylist[100010]={NULL};

void dfs(int x)
{
	int ii;
	stackhead++;
	stack[stackhead]=x;
	if(x==a)
	{
		for(ii=0;ii<=stackhead;ii++)
			afinarr[ii]=stack[ii];
		acnt=stackhead+1;
	}
	if(x==b)
	{
		for(ii=0;ii<=stackhead;ii++)
			bfinarr[ii]=stack[ii];
		bcnt=stackhead+1;
	}
	int i;
	visited[x]=1;
	struct LL* temp=mylist[x];
	while(temp!=NULL)
	{
		if(visited[temp->val]==0)
			dfs(temp->val);
		temp=temp->next;
	}
	stackhead--;
}

int main()
{
	int pp,n,c,i,j,k,q,m,af,bf;
	scanf("%d", &n);
	q=n-1; //In a tree there are n-1 edges
	for(i=0;i<q;i++)
	{
		scanf("%d%d", &a, &b);
		struct LL* temp=malloc(sizeof(struct LL));
		temp->val=b;
		temp->next=mylist[a];
		mylist[a]=temp;
		struct LL* temp2=malloc(sizeof(struct LL));
		temp2->val=a;
		temp2->next=mylist[b];
		mylist[b]=temp2;
	}
	scanf("%d", &m); //Number of queries
	for(k=0;k<m;k++)
	{
		memset(visited,0,4*100010);
		stackhead=-1;
		scanf("%d%d", &a, &b);
		acnt=0;
		bcnt=0;
		dfs(1); //We consider 1 as the root node
		int final=afinarr[0];
		for(i=0;i<acnt && i<bcnt;i++)
		{
			if(afinarr[i]==bfinarr[i])
				final=afinarr[i];
		}
		printf("%d\n", final);
	}
	return 0;
}
