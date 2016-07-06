#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n;

int partition(int A[], int start, int end, int pivot)
{
	int i,j,a,b,c,piv,temp;
	piv=A[pivot];
	temp=A[pivot];
	A[pivot]=A[end];
	A[end]=temp;
	int place=start;
	for(i=start;i<=end;i++)
	{	
		if(A[i]<=piv)
		{
			temp=A[place];
			A[place]=A[i];
			A[i]=temp;
			place++;
		}
	}
	return place-1;
}

void quick(int A[], int start, int end)
{
	int newpiv,random;
	if(start<end)
	{
		srand(time(NULL));
		random=rand();
		random=start+random%(end-start);
		newpiv=partition(A,start,end,random);
		quick(A,start,newpiv-1);
		quick(A,newpiv+1,end);
	}
}

int main()
{
	int A[10000];
	int i;
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &A[i]);
	quick(A,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
