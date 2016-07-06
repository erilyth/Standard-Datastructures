#include<stdio.h>
#include<stdlib.h>

//Segment Tree consisting of minimums

int min(int a, int b)
{
	if(b<a)
		return b;
	else
		return a;
}

int mintree[300000]={0}; //The tree you construct
int val[300000]={0}; //Given array
int thingers[100010][5];

int maketree(int start, int end, int index)
{
	if(start==end)
	{
		mintree[index]=val[start];
		return mintree[index];
	}
	else
	{
	 	mintree[index]=min(maketree(start,(start+end)/2,index*2+1),maketree((start+end)/2+1,end,index*2+2));
		return mintree[index];
	}
}

int rangemin(int start, int end, int fromwhere, int tillwhere, int index)
{
	if(fromwhere>end || tillwhere<start)
		return 100000000;
	else if(fromwhere<=start && tillwhere>=end)
		return mintree[index];
	else
		return min(rangemin(start,(start+end)/2,fromwhere,tillwhere,index*2+1),rangemin((start+end)/2+1,end,fromwhere,tillwhere,index*2+2));

}

int changeval(int start, int end, int pos, int valtoadd, int index)
{
	if(pos>=start && pos<=end)
	{
		if(start!=end)
			mintree[index]=min(changeval(start,(start+end)/2,pos,valtoadd,index*2+1),changeval((start+end)/2+1,end,pos,valtoadd,index*2+2));
		else
			mintree[index]+=valtoadd;
		return mintree[index];
	}
	if(pos<start || pos>end) 
		return mintree[index];
}

int main()
{
	int i,j,k,a,b,c;
	for(i=0;i<10;i++)
		val[i]=i+1;
	maketree(0,9,0);
	printf("%d\n", rangemin(0,9,5,8,0)); 
	changeval(0,9,8,-5,0);
	printf("%d\n", rangemin(0,9,5,9,0));
	return 0;
}
