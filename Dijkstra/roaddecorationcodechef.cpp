#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<set>
#define MAX 10000000000000000

using namespace std;

//THIS IS A MIN HEAP!!!!

long long int ans[500001]={0}; //The final answer of dist of each vertex from given vertex is stored in this array

struct Node{ //Adjacency list
	long long int val;
	long long int weight;
	struct Node* next;
};

struct Nodek{ //Stores the nodes for kruskals
	long long int val;
	long long int x,y;
};

struct comparator{ //For the priority queue in kruskals
	bool operator()(const Nodek &i, const Nodek &j){
		return i.val>j.val;
	}
};

long long int n,m,count;
long long int parval[500001]={0}; //Stores the shortest possible edge to the ith node
struct Node* edges[500001]={NULL}; //Adjacency List
long long int marked[500001]={0}; //Already visited elements for dijkstra
long long int AA[500001]={0}; //The union find set array
long long int rank[500001]={0}; //For union find in kruskals

long long int find(long long int i)
{
	if(AA[i]!=i)
		AA[i]=find(AA[i]);
	return AA[i];
}

void unions(long long int a, long long int b)
{
	long long int aa=find(a);
	long long int bb=find(b);
	if(rank[aa]>rank[bb]) AA[bb]=aa;
	if(rank[bb]>rank[aa]) AA[aa]=bb;
	if(rank[bb]==rank[aa])
	{
		AA[aa]=bb;
		rank[bb]++;
	}
}

int main()
{
	long long int tc,jj;
	scanf("%lld", &tc);
	for(jj=0;jj<tc;jj++)
	{
		pair<long long int, long long int> mypair; 
		priority_queue<Nodek,vector<Nodek>,comparator> minHeap; //For Kruskals
		set<pair<long long int, long long int> > myset; //For dijkstra
		scanf("%lld%lld", &n, &m);
		long long int kk,a,b;
		for(kk=0;kk<=2*n+10;kk++)
		{
			AA[kk]=kk; ans[kk]=MAX; marked[kk]=0; parval[kk]=0; edges[kk]=NULL; rank[kk]=0;
		}
		long long int top,mains,aa,bb,i,j,k,c,ww;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld", &aa, &bb, &ww);
			struct Node* temp=new Node;
			temp->weight=ww;
			temp->val=bb;
			temp->next=edges[aa];
			edges[aa]=temp;
			struct Node* temp2=new Node;
			temp2->weight=ww;
			temp2->val=aa;
			temp2->next=edges[bb];
			edges[bb]=temp2;
			struct Nodek tempp;
			tempp.val=ww;
			tempp.x=aa;
			tempp.y=bb;
			minHeap.push(tempp);
		}
		ans[0]=0;
		marked[0]=1;
		myset.insert(pair<long long int,long long int>(0,0)); //We insert the first element into the min heap with dist from source=0 as this is the source itself
		long long int dijkanscount=0;
		long long int dijkstra=0;
		long long int count3=m;
		while(!myset.empty())
		{
			dijkstra++;
			pair <long long int ,long long int> topp=*myset.begin();
			myset.erase(myset.begin());
			dijkanscount+=parval[topp.second];
			marked[topp.second]=2;
			struct Node* temp3=edges[topp.second];
			while(temp3!=NULL)
			{
				if(marked[temp3->val]==0)
				{
					ans[temp3->val]=ans[topp.second]+temp3->weight;
					myset.insert(pair<long long int, long long int>(ans[temp3->val],temp3->val));
					marked[temp3->val]=1; //Once a vertex is in the heap we dont want to add it again
					parval[temp3->val]=temp3->weight;				
				}
				else if(marked[temp3->val]!=2 && ans[temp3->val]>(ans[topp.second]+temp3->weight))
				{
					myset.erase(myset.find(pair <long long int, long long int>(ans[temp3->val],temp3->val)));
					ans[temp3->val]=ans[topp.second]+temp3->weight;
					myset.insert(pair<long long int, long long int>(ans[temp3->val],temp3->val));
					parval[temp3->val]=temp3->weight;
				}
				else if(marked[temp3->val]!=2 && ans[temp3->val]==ans[topp.second]+temp3->weight)
				{
					if(parval[temp3->val]>temp3->weight)
						parval[temp3->val]=temp3->weight;
				}
				temp3=temp3->next;
			}
		}
		long long int state=0;
		long long visited=0;
		long long sum=0;
		while(!minHeap.empty())
		{
			struct Nodek tnode;
			tnode=minHeap.top();
			minHeap.pop();
			if(find(tnode.x)!=find(tnode.y))
			{
				visited++;
				sum+=tnode.val;
				unions(find(tnode.x),find(tnode.y));
			}
		}
		if(visited!=n-1 || dijkstra!=n)
			state=1;
		if(dijkanscount==sum && state==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
