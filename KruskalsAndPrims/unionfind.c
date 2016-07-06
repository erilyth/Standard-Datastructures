#include<stdio.h>
#include<string.h>

int count[100000]={0};
int rank[100000]={0};
int AA[100000]={0};
//Bad time complexity, no rank order and no compression

long long int findd(long long int i)
{
	if(AA[i]!=i)
		AA[i]=findd(AA[i]);
	return AA[i];
}

void unions(long long int a, long long int b)
{
	long long int aa=findd(a);
	long long int bb=findd(b);
	if(rank[aa]>rank[bb])
		AA[bb]=aa;
	if(rank[bb]>rank[aa])
		AA[aa]=bb;
	else if(rank[bb]==rank[aa])
	{
		AA[aa]=bb;
		rank[bb]++;
		count[bb]+=count[aa];
	}
}

int main()
{
	int a,b,c,i,j,k,n;
	scanf("%d", &n);
	for(i=0;i<=n;i++)
	{
		AA[i]=i;
		count[i]=1;
	}
	scanf("%d", &c);
	for(i=0;i<c;i++)
	{
		scanf("%d%d", &a, &b);
		int pp=findd(a);
		int qq=findd(b);
		if(pp==qq) //If the roots of pp and qq are the same then that means they belong to the same set so they will now form a cycle if an edge is added between them
			printf("Found Cycle\n");
		else
			unions(a,b); //We set the root of a to be the parent of the root of b
	}
	return 0;
}
