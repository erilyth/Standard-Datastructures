#include<stdio.h>
#include<stdlib.h>

int A[1000000];

int binarysearchrecursive(int l, int r, int x)
{
    int m;
    if(l>r)
        return -1;
    m=(l+r)/2;
    if(A[m]<x)
        return binarysearchrecursive(m+1,r,x);
    else if (A[m]>x)
        return binarysearchrecursive(l,m-1,x);
    return m;
}

int main()
{
    int i,n,k,pos;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    pos = binarysearchrecursive(0,n-1,k);
    printf("%d\n", pos);
    return 0;
}
