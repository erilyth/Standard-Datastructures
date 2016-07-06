#include<stdio.h>
#include<string.h>

long long int mark[100000]={0},count[100000]={0},rank[100000]={0},AA[100000]={0},ans[100000]={0},anscount=0;
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
	{
		AA[bb]=aa;
	}
	if(rank[bb]>rank[aa])
	{
		AA[aa]=bb;
	}
	else if(rank[bb]==rank[aa])
	{
		AA[aa]=bb;
		rank[bb]++;
	}
}

int main()
{
	long long int a,b,c,i,j,k,n,q,tc;
	scanf("%lld", &tc);
	for(j=0;j<tc;j++)
	{
	scanf("%lld", &n);
	scanf("%lld", &q);
	for(i=0;i<=n;i++)
	{
		AA[i]=i;
		mark[i]=0;
		count[i]=0;
		rank[i]=0;
		ans[i]=0;
	}
	anscount=0;
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld", &b, &c);
		unions(b,c);
	}
	long long int counts=0;
	for(i=0;i<=n;i++)
	{
		count[findd(i)]++;
	}
	for(i=1;i<=n;i++)
	{
		if(count[findd(i)]>0 && mark[findd(i)]==0)
		{
			mark[findd(i)]=1;
			counts++;
			ans[anscount++]=count[findd(i)];
		}
	}
	printf("%lld ", counts);
	long long int answer=1;
	for(i=0;i<anscount;i++)
	{
		answer=(answer*ans[i])%1000000007;
	}
	printf("%lld\n", answer);
	}
	return 0;
}
