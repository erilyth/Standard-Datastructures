#include <queue>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long int count=0;
long long int visited=0;
long long int sum=0;
long long int AA[1000000]={0};

struct Node{
	long long int val;
	long long int x,y;
};

struct comparator{
    bool operator() (const Node &i,const Node &j){
        return i.val > j.val;
}};
 

long long int findd(long long int i)
{
	if(AA[i]==-1)
                return i;
	return findd(AA[i]);
} 
	
void unions(long long int a, long long int b)
{
	long long int aa=findd(a);
	long long int bb=findd(b);
        AA[bb]=aa;
}

int main()
{
    priority_queue<Node, vector<Node>, comparator> minHeap;
    //priority_queue<Node> minHeap;
    long long int x,y,i,j,k,b,c,n,m;
    Node a;
    scanf("%lld%lld", &n, &m);
    for(i=0;i<m;i++)
    {
	    scanf("%lld%lld%lld", &x, &y, &b);
	    struct Node temp;
	    temp.val=b;
	    temp.x=x;
	    temp.y=y;
	    minHeap.push(temp);
    }
    count=n;
    visited=0;
    for(i=0;i<1000000;i++)
	    AA[i]=-1;
    while(count>0 && visited<n-1)
    {
	    a=minHeap.top();
	   // printf("%lld %lld\n", a.x, a.y);
	    minHeap.pop();
	    if(findd(a.x)!=findd(a.y))
	    {
		visited++;
	    	sum+=a.val;
		unions(findd(a.x),findd(a.y));
	    }
    }
    printf("%lld\n", sum);
    return 0;
}
