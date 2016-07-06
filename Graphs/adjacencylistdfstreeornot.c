#include<stdio.h>
#include<stdlib.h>

int a,b;

struct List{
	int val;
	struct List* next;
};

int state=0;
struct List* mylist[100000]={NULL};
int marked[100000]={0};

void dfs(int a)
{
	marked[a]=1;
	struct List* temp=mylist[a];
	while(temp!=NULL)
	{
		if(marked[temp->val]!=1 && state!=1)
			dfs(temp->val);
		else
		{
		//	printf("%d", temp->val);
			state=1;
			return;
		}
		temp=temp->next;
	}
}

int main()
{
	int n,m,i,j,k,c;
	scanf("%d%d", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d", &a, &b);
		//We insert at the head so insertion in in O(1)
		struct List* temp=malloc(sizeof(struct List));
		temp->val=b;
		temp->next=mylist[a];
		mylist[a]=temp;
	}
	//Printing the Adjacency List
	/*for(i=1;i<=n;i++)
	{
		struct List* temp=mylist[i];
		while(temp!=NULL)
		{
			printf("%d ", temp->val);
			temp=temp->next;
		}
		printf("\n");
	}*/
	for(i=0;i<=n;i++)
		if(marked[i]==0)
			dfs(i);
	if(state==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
