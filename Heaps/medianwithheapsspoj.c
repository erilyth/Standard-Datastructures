#include<stdio.h>
#include<stdlib.h>
#define MAX 100000000000000000

//We insert elements in to the heap as and when we get them as input. Then we start deletion from the head to get the sorted decending order of the given array.

//Only use positive numbers in the heap
//The heap always ensures that its a perfect tree (Breadth wise insertion and deletion)
long long int val=0;
long long int state=0;
long long int count=0;
long long int count2=0;
long long int state2=0;

void worker(long long int A[],long long int j) //Goes up the tree swapping with the parent wherever required.
{
	long long int temp;
	if(j>=2)
	{
		if(A[j/2]<A[j])
		{
			temp=A[j/2];
			A[j/2]=A[j];
			A[j]=temp;
			worker(A,j/2);
		}
	}
}

void worker2(long long int B[],long long int j) //Goes up the tree swapping with the parent wherever required.
{
	long long int temp;
	if(j>=2)
	{
		if(B[j/2]>B[j])
		{
			temp=B[j/2];
			B[j/2]=B[j];
			B[j]=temp;
			worker2(B,j/2);
		}
	}
}

void insert2(long long int B[],long long int i)
{
	state=0;
	val=0;
	count2++;
	B[count2]=i; 
	//We simply insert the element at the end of the array and then check throughout the tree above it (worker function).
	//We can store i in A[count+1] as count+1'th location is empty as of now. In a heap, suppose there are n elements until now then the n elements are arranged in array locations 1 to n, n+1th location is untouched. This is because its a balanced binary tree, so n+1th location is filled only after nth location is filled and so on.....
	worker2(B,count2);
}

void insert(long long int A[],long long int i)
{
	state=0;
	val=0;
	count++;
	A[count]=i; 
	//We simply insert the element at the end of the array and then check throughout the tree above it (worker function).
	//We can store i in A[count+1] as count+1'th location is empty as of now. In a heap, suppose there are n elements until now then the n elements are arranged in array locations 1 to n, n+1th location is untouched. This is because its a balanced binary tree, so n+1th location is filled only after nth location is filled and so on.....
	worker(A,count);
}

void remover(long long int A[],long long int i) //Shifts down the tree swapping with the children whenever required.
{
	long long int temp;
	if(i>count)
		return;
	if(i*2+1<300000 && A[i*2]>=A[i*2+1] && A[i*2]!=0)
	{
		if(A[i*2]>A[i])
		{
			temp=A[i*2];
			A[i*2]=A[i];
			A[i]=temp;
			remover(A,i*2);
		}
	}
	else if(i*2+1<300000 && A[i*2+1]!=0)
	{
		if(A[i*2+1]>=A[i])
		{
			temp=A[i*2+1];
			A[i*2+1]=A[i];
			A[i]=temp;
			remover(A,i*2+1);
		}
	}
}

void remover2(long long int B[],long long int i) //Shifts down the tree swapping with the children whenever required.
{
	long long int temp;
	if(i>count2)
		return;
	if(i*2<=count2 && B[i*2]<B[i*2+1])
	{
		if(B[i*2]<B[i])
		{
			temp=B[i*2];
			B[i*2]=B[i];
			B[i]=temp;
			remover2(B,i*2);
		}
	}
	else if(i*2+1<=count2)
	{
		if(B[i*2+1]<B[i])
		{
			temp=B[i*2+1];
			B[i*2+1]=B[i];
			B[i]=temp;
			remover2(B,i*2+1);
		}
	}
}


void deletetop(long long int A[])
{
//	printf("%d\n",A[1]);
	if(count==1)
	{
		A[1]=0;
		count=0;
		return;
	}
	A[1]=A[count];
	A[count]=0;
	count--;
	remover(A,1);
}

void deletetop2(long long int B[])
{
//	printf("%d\n",B[1]);
	if(count2==1)
	{
		B[1]=MAX;
		count2=0;
		return;
	}
	B[1]=B[count2];
	B[count2]=MAX;
	count2--;
	remover2(B,1);
}

void increase(long long int index, long long int change, long long int A[])
{
	A[index]+=change;
	worker(A,index); //This shifts the position to the correct location of the max heap
}
//For the increase and decrease functions change must be positive
void decrease(long long int index, long long int change, long long int A[])
{
	A[index]-=change;
	remover(A,index); //This shifts the position down to the correct location of the max heap
}

long long int funct(long long int i, long long int a, long long int b, long long int c, long long int m)
{
	return (a*m+b*i+c)%1000000007;
}

int main()
{
	//Call the insert function whenever you want to and the deletetop() to remove the maximum element whenever needed.
	long long int i,j,jj,kk,k,a,b,c,n,m,tempval,finval,temp1,temp2,temp3,state=0,finsum=0,median;
	long long int tc;
	scanf("%lld", &tc);
	for(kk=0;kk<tc;kk++)
	{
		count=0;
		count2=0;
		state=0;
		finsum=0;
		long long int A[300000]={0};
		long long int B[300000]={0};
	scanf("%lld%lld%lld%lld", &a, &b, &c, &n);
	finsum+=1;
	insert(A,1);
	median=1;
	for(k=2;k<=n;k++)
	{
		//printf("%d ", median);
		finsum+=funct(k,a,b,c,median);
		finval=funct(k,a,b,c,median);
		//printf("%lld %lld %lld %lld %lld %lld\n", k, a, b, c, median, finval);
		/*if(k<=8)
		{
			for(jj=1;jj<=count;jj++)
				printf("%lld ", A[jj]);
			printf("\n");
			for(jj=1;jj<=count2;jj++)
				printf("%lld ", B[jj]);
			printf("\n");
		}*/
		if(state==2)
		{
			if(finval>median)
			{
				state=1;
				insert2(B,finval);
			}
			else
			{
				state=0;
				insert(A,finval);
			}
		}
		else if(state==1)
		{
			if(finval>median)
			{
				state=2;
				temp1=B[1];
				deletetop2(B);
				insert(A,temp1);
				insert2(B,finval);
			}
			else
			{
				state=2;
				insert(A,finval);
			}
		}
		else if(state==0)
		{
			if(finval<median)
			{
				state=2;
				temp1=A[1];
				deletetop(A);
				insert2(B,temp1);
				insert(A,finval);
			}
			else
			{
				state=2;
				insert2(B,finval);
			}
		}
		if(state==2)
			median=A[1];
		else if(state==1)
			median=B[1];
		else if(state==0)
			median=A[1];
	}
	printf("%lld\n", finsum);
	}
	/*
	long long int B[100000]={100000000};
	long long int i,a,b,c;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &i);
	insert2(B,5);
	insert2(B,9);
	insert2(B,10);
	printf("%lld %lld %lld %lld\n", B[1], B[2], B[3], B[4]);
	deletetop2(B);
	printf("%lld %lld %lld %lld\n", B[1], B[2], B[3], B[4]);
	insert2(B,12);
	printf("%lld %lld %lld %lld\n", B[1], B[2], B[3], B[4]);*/
	return 0;
}
