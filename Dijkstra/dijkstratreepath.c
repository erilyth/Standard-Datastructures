#include<stdio.h>
#include<stdlib.h>

//THIS IS A MIN HEAP!!!!

struct Node{
	int val;
	int weight;
	struct Node* next;
};

int fake;
int parentarr[200005]={0};
struct Node* edges[200005]={NULL};
int A[200005]={0}; //Zero indicates that the location is empty
int B[200005]={0};
int pos[200005]={0}; //Position of each vertex in the heap
int ans[200005]={0}; //The final answer of dist of each vertex from given vertex is stored in this array
int marked[200005]={0}; //Already visited elements
//Only use positive numbers in the heap
//The heap always ensures that its a perfect tree (Breadth wise insertion and deletion)
int val=0;
int state=0;
int count=0;
int lol[200005]={0};
int lolcount=0;
int finaldists[200005]={0};

void swapp(int a, int b)
{
	int temp=A[a];
	int temp2=B[a];
	pos[B[a]]=b;
	pos[B[b]]=a;
	A[a]=A[b];
	B[a]=B[b];
	A[b]=temp;
	B[b]=temp2;

}

void worker(int j) //Goes up the tree swapping with the parent wherever required.
{
	int temp,temp2;
	while(j>=2)
	{
		if(A[j/2]>A[j])
		{
			swapp(j,j/2);
			j=j/2;
		}
		else
			break;
	}
}

void insert(int vals,int num)
{
	state=0;
	val=0;
	count++;
	A[count]=vals;
	B[count]=num;
	pos[num]=count;
	//We simply insert the element at the end of the array and then check throughout the tree above it (worker function).
	//We can store i in A[count+1] as count+1'th location is empty as of now. In a heap, suppose there are n elements until now then the n elements are arranged in array locations 1 to n, n+1th location is untouched. This is because its a balanced binary tree, so n+1th location is filled only after nth location is filled and so on.....
	worker(count);
}	

void remover(int i) //Shifts down the tree swapping with the children whenever required.
{
	while(i<=count)
	{
		if(i*2<=count)
		{
			if((i*2+1<=count && A[i*2]<A[i] && A[i*2]<A[i*2+1]) || (A[i*2]<A[i] && i*2+1>count))
			{
				swapp(i,i*2);
				i=i*2;
			}
			else if(i*2+1<=count && A[i*2+1]<A[i] && A[i*2+1]<=A[i*2])
			{
				swapp(i,i*2+1);
				i=i*2+1;
			}
			else
				break;
		}
		else
			break;
	}
}

void deletetop()
{
	A[1]=A[count];
	B[1]=B[count];
	pos[B[1]]=1;
	count--;
	remover(1);
}

void change(int a, int b)
{
	A[a]=b; //Since we will only call this function if b is lesser than the previous value of A[a], we can simply shift up the min heap
	worker(a);
}

int main()
{
	int kk,a,b;
	for(kk=0;kk<100005;kk++)
	{
		A[kk]=10000000;
		ans[kk]=10000000;
		marked[kk]=0;
		edges[kk]=NULL;
	}
	int top,mains,aa,nn,bb,i,j,k,c,n,m;
	scanf("%d%d", &nn, &m);
	a=1;
	b=nn;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d", &aa, &bb, &n);
		struct Node* temp=malloc(sizeof(struct Node));
		temp->weight=n;
		temp->val=bb;
		temp->next=edges[aa];
		edges[aa]=temp;
		struct Node* temp2=malloc(sizeof(struct Node));
		temp2->weight=n;
		temp2->val=aa;
		temp2->next=edges[bb];
		edges[bb]=temp2;
	}
	a=1;
	ans[a]=0;
	marked[a]=1;
	insert(0,a); //We insert the first element into the min heap with dist from source=0 as this is the source itself
	pos[a]=1; //This source is at position 1 in the heap.
	while(count!=0)
	{
		top=B[1];
		marked[B[1]]=2;
		finaldists[B[1]]=A[1];
		deletetop();
		struct Node* temp3=edges[top];
		while(temp3!=NULL)
		{

			if(marked[temp3->val]==0)
			{
				parentarr[temp3->val]=top;
				marked[temp3->val]=1;
				ans[temp3->val]=ans[top]+temp3->weight;
				insert(ans[temp3->val],temp3->val);
				pos[temp3->val]=count;
				//We always insert at count in the heap and then as we swap up the pos array changes appropriately
 //Once a vertex is in the heap we dont want to add it again
			}
			else if(marked[temp3->val]==1 && ans[temp3->val]>(ans[top]+temp3->weight))
			{
				ans[temp3->val]=ans[top]+temp3->weight;
				change(pos[temp3->val],ans[temp3->val]);
				parentarr[temp3->val]=top;
			}
			temp3=temp3->next;
		}
	}
	a=1;
	b=nn;
	if(ans[nn]==10000000)
	{
		printf("-1\n");
		return 0;
	}
	while(a!=b)
	{
		lol[lolcount++]=b;
		b=parentarr[b];
	}
	printf("%d ", 1);
	for(i=lolcount-1;i>=0;i--)
		printf("%d ", lol[i]);
	printf("\n");
	//printf("%d\n", ans[b]);
	return 0;
}
