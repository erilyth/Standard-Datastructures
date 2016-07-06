#include<stdio.h>

int bit[1000000]={0}; //Start from the first index
int n;

//Range Update and Query at a single point
//Doesnt store cumilative sum

void change(int index, int val)
{
	while(index<=n)
	{
		bit[index]+=val;
		index+=index&((-1)*index);
	}
}

int query(int range)
{
	int ans=0;
	while(range>0)
	{
		ans+=bit[range];
		range-=range&((-1)*range);
	}
	return ans;
}

void rangechange(int a, int b, int val)
{
	change(a,val);
	change(b+1,(-1)*val); //Only updates elements at those values from a to b
}

int main()
{
	int i,j,k,m,a,b,c;
	int tc,kk;
	scanf("%d", &tc);
	for(kk=0;kk<tc;kk++)
	{
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)
		bit[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		rangechange(a+1,b+1,c);
	}
	scanf("%d", &m);
	for(j=1;j<=m;j++)
	{
		scanf("%d", &a);
		printf("%d\n", query(a+1));
	}
	}
	return 0;
}
