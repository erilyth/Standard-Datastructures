#include<stdio.h>
#include<stdlib.h>

int A[1000000];

int ternarysearchrecursive(int l, int r, int x)
{
    int lmid,rmid;
    if(A[r]==x)
        return r;
    lmid=(2*l+r)/3; rmid=(l+2*r)/3;
    if(lmid==rmid && A[rmid]!=x)
        return -1;
    if(x<A[lmid])
        return ternarysearchrecursive(l,lmid,x);
    else if (x>A[rmid])
        return ternarysearchrecursive(rmid,r,x);
    return ternarysearchrecursive(lmid,rmid,x);
}

int main()
{
    int i,n,k,pos;
    scanf("%d", &n);
    for(i=0;i<n;i++)
	   scanf("%d", &A[i]);
    scanf("%d", &k);
    pos = ternarysearchrecursive(0,n-1,k);
    printf("%d\n", pos);
    return 0;
}
