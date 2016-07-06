#include<stdio.h>
#include<stdlib.h>
#define MAX 10000000000000000

//THIS IS A MIN HEAP!!!!

struct Node{
	long long int val;
	long long int weight;
	struct Node* next;
};

struct Node* edges[500001]={NULL};
long long int A[500001]={0}; //Zero indicates that the location is empty
long long int B[500001]={0};
long long int pos[500001]={0}; //Position of each vertex in the heap
long long int ans[500001]={0}; //The final answer of dist of each vertex from given vertex is stored in this array
long long int marked[500001]={0}; //Already visited elements
//Only use positive numbers in the heap
//The heap always ensures that its a perfect tree (Breadth wise insertion and deletion)
long long int val=0;
long long int state=0;
long long int count=0;

void worker(long long int j) //Goes up the tree swapping with the parent wherever required.
{
	long long int temp,temp2;
	if(j>=2)
	{
		if(A[j/2]>=A[j])
		{
			temp=A[j/2];
			temp2=B[j/2];
			pos[B[j/2]]=j; //On moving up we need to store new positions for the vertices which we have in B
			pos[B[j]]=j/2;
			A[j/2]=A[j];
			B[j/2]=B[j];
			A[j]=temp;
			B[j]=temp2;
			worker(j/2);
		}
	}
}

void insert(long long int vals,long long int num)
{
	state=0;
	val=0;
	count++;
	A[count]=vals;
	B[count]=num;
	//We simply insert the element at the end of the array and then check throughout the tree above it (worker function).
	//We can store i in A[count+1] as count+1'th location is empty as of now. In a heap, suppose there are n elements until now then the n elements are arranged in array locations 1 to n, n+1th location is untouched. This is because its a balanced binary tree, so n+1th location is filled only after nth location is filled and so on.....
	worker(count);
}

void remover(long long int i) //Shifts down the tree swapping with the children whenever required.
{
	long long int temp,temp2;
	if(i>count)
		return;
	if(i*2<=count && A[i*2]<A[i*2+1])
	{
		if(A[i*2]<A[i])
		{
			temp=A[i*2];
			temp2=B[i*2];
			pos[B[i*2]]=i; //We need to store new positions in heap for elements in B as we are shifting down
			pos[B[i]]=i*2;
			A[i*2]=A[i];
			B[i*2]=B[i];
			A[i]=temp;
			B[i]=temp2;
			remover(i*2);
		}
	}
	else if(i*2+1<=count)
	{
		if(A[i*2+1]<A[i])
		{
			pos[B[i*2+1]]=i; //We need to store new positions of vertices in B as we are shifting down/
			pos[B[i]]=i*2+1;
			temp=A[i*2+1];
			temp2=B[i*2+1];
			A[i*2+1]=A[i];
			B[i*2+1]=B[i];
			A[i]=temp;
			B[i]=temp2;
			remover(i*2+1);
		}
	}
}

void deletetop()
{
	A[1]=A[count];
	B[1]=B[count];
	pos[B[1]]=1;
	A[count]=MAX;
	B[count]=0;
	count--;
	remover(1);
}

void change(long long int a, long long int b)
{
	A[a]=b; //Since we will only call this function if b is lesser than the previous value of A[a], we can simply shift up the min heap
	worker(a);
}

int main()
{
	long long int kk,a,b;
	for(kk=0;kk<1000;kk++)
	{
		ans[kk]=MAX;
		marked[kk]=0;
		edges[kk]=NULL;
	}
	long long int top,mains,aa,bb,i,j,k,c,n,m;
	scanf("%lld%lld", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld", &aa, &bb, &n);
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
	scanf("%lld%lld", &a, &b);
	ans[a]=0;
	marked[a]=1;
	insert(0,a); //We insert the first element into the min heap with dist from source=0 as this is the source itself
	pos[a]=1; //This source is at position 1 in the heap.
	while(count!=0)
	{
		top=B[1];
		marked[B[1]]=2;
		deletetop();
		struct Node* temp3=edges[top];
		struct Node* temp4=temp3;
		while(temp3!=NULL)
		{
			if(marked[temp3->val]==0)
			{
				ans[temp3->val]=ans[top]+temp3->weight;
				insert(ans[temp3->val],temp3->val);
				pos[temp3->val]=count;
				//We always insert at count in the heap and then as we swap up the pos array changes appropriately
				marked[temp3->val]=1; //Once a vertex is in the heap we dont want to add it again
			}
			else if(marked[temp3->val]!=2 && ans[temp3->val]>(ans[top]+temp3->weight))
			{
				ans[temp3->val]=ans[top]+temp3->weight;
				change(pos[temp3->val],ans[temp3->val]);
			}
			temp3=temp3->next;
		}
	}
	if(ans[b]==MAX)
		printf("NO\n");
	else
		printf("%lld\n", ans[b]);
	return 0;
}
