#include<stdio.h>
#include<stdlib.h>
#define MAX 100000000000000000

long long int myHeap[500005]={0};
long long int myHeap2[500005]={0};
long long int pos[500005]={0};
long long int count=0;
long long int dijmarked[500005]={0};
long long int dijans[500005]={0};

struct Noded{
	long long int vald;
	long long int weightd;
	struct Noded* next;
};

struct Noded* dijlist[500005]={NULL};

//Latest Simple Heap!

void swapheap(long long int a, long long int b)
{
	long long int temp=myHeap[a];
	long long int temp2=myHeap2[a];
	//long long int temp3=pos[myHeap2[a]];
	pos[myHeap2[a]]=b;
	pos[myHeap2[b]]=a;
	myHeap[a]=myHeap[b]; myHeap2[a]=myHeap2[b];
	myHeap[b]=temp; myHeap2[b]=temp2;
}

void upshift(long long int a)
{
	while(a>1)
	{
		if(myHeap[a/2]>myHeap[a])
		{
			swapheap(a,a/2);
			a=a/2;
		}
		else
			return;
	}
}

void downshift(int i) //Shifts down the tree swapping with the children whenever required.
{
	while(i<=count)
	{
		if(i*2<=count)
		{
			if((i*2+1<=count && myHeap[i*2]<myHeap[i] && myHeap[i*2]<myHeap[i*2+1]) || (myHeap[i*2]<myHeap[i] && i*2+1>count))
			{
				swapheap(i,i*2);
				i=i*2;
			}
			else if(i*2+1<=count && myHeap[i*2+1]<myHeap[i] && myHeap[i*2+1]<=myHeap[i*2])
			{
				swapheap(i,i*2+1);
				i=i*2+1;
			}
			else
				break;
		}
		else
			break;
	}
}

void insert(long long int a, long long int node)
{
	count++;
	myHeap[count]=a;
	myHeap2[count]=node;
	pos[node]=count;
	upshift(count);
}

void deletetop()
{
	if(count>0)
	{
		myHeap[1]=myHeap[count];
		myHeap2[1]=myHeap2[count];
		pos[myHeap2[1]]=1;
		count--;
		downshift(1);
	}
}

void insertlist(long long int a, long long int b, long long int w)
{
	struct Noded* temp=malloc(sizeof(struct Noded));
	temp->vald=b;
	temp->weightd=w;
	temp->next=dijlist[a];
	dijlist[a]=temp;
}

void reset()
{
	long long int i;
	for(i=0;i<500005;i++)
	{
		myHeap[i]=0; myHeap2[i]=0; pos[i]=0; count=0; dijmarked[i]=0; dijans[i]=MAX; dijlist[i]=NULL;
	}
}

int main()
{
	long long int pp,w,tc,a,b,c,i,j,k,n,m,start,end;
	//scanf("%lld", &tc);
	tc=1;
	for(pp=0;pp<tc;pp++)
	{
		reset();
		scanf("%lld%lld", &n, &m);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld", &a, &b, &w);
			insertlist(a,b,w);
		}
		scanf("%lld%lld", &start , &end);
		insert(0,start);
		dijmarked[start]=1;
		dijans[start]=0;
		while(count!=0)
		{
			long long int temper=myHeap[1], temper2=myHeap2[1];
			deletetop();
			dijmarked[temper2]=2;
			struct Noded* tempk=dijlist[temper2];
			while(tempk!=NULL)
			{
				if(dijmarked[tempk->vald]==0)
				{
					dijmarked[tempk->vald]=1;
					dijans[tempk->vald]=dijans[temper2]+tempk->weightd;
					insert(dijans[tempk->vald],tempk->vald);
				}
				else if(dijmarked[tempk->vald]==1)
				{
					if(dijans[tempk->vald]>dijans[temper2]+tempk->weightd)
						dijans[tempk->vald]=dijans[temper2]+tempk->weightd;
					myHeap[pos[tempk->vald]]=dijans[tempk->vald];
					upshift(pos[tempk->vald]);
				}
				tempk=tempk->next;
			}
		}
		if(dijans[end]!=MAX)
			printf("%lld\n", dijans[end]);
		else
			printf("NO\n");
	}
	return 0;
}
