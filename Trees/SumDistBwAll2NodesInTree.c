#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Program to find sum of distances b/w all nodes using number of children of each node

long long int visited[100100]={0};
long long int a,b,acnt,bcnt;

struct LL{
	long long int val;
	long long int weight;
	struct LL* next;
};

long long int min(long long int a, long long int b)
{
	if(a<b)
		return a;
	return b;
}

struct LL* mylist[100100]={NULL};
long long int children[100100]={0};

int dfs(long long int x)
{
	long long int ii;
	visited[x]=1;
	struct LL* temp=mylist[x];
	while(temp!=NULL)
	{
		if(visited[temp->val]==0)
			children[x]+=dfs(temp->val)+1;
		temp=temp->next;
	}
	return children[x];
	//printf("%d %d", x, children[x]);
}

int main()
{
	long long int pp,n,c,i,j,k,q,m;
	long long int arr3[100100][4];
	scanf("%lld", &n);
	q=n-1; //In a tree there are n-1 edges
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		arr3[i][0]=a;
		arr3[i][1]=b;
		arr3[i][2]=c;
		struct LL* temp=malloc(sizeof(struct LL));
		temp->val=b;
		temp->weight=c;
		temp->next=mylist[a];
		struct LL* temp2=malloc(sizeof(struct LL));
		temp2->val=a;
		temp2->weight=c;
		temp2->next=mylist[b];
		mylist[b]=temp2;
		mylist[a]=temp;
	}
	dfs(1); //Given that 1 exists in the tree, we can choose any vertex to be root
	long long int sum=0;
	for(i=0;i<q;i++)
	{
		//printf("Children of %lld ARE %lld\n", i,children[i]);
		if(children[arr3[i][0]]<children[arr3[i][1]])
			sum+=(children[arr3[i][0]]+1)*(n-(children[arr3[i][0]]+1))*arr3[i][2];
		else
			sum+=(children[arr3[i][1]]+1)*(n-(children[arr3[i][1]]+1))*arr3[i][2];
	}
	printf("%lld\n", sum);
	return 0;
}
