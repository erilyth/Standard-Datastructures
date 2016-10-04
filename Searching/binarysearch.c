#include<stdio.h>
#include<stdlib.h>

int A[1000000];

int binarysearch(int size, int x)
{
    int l,r,m;
    l=0; r=size;
    while(l<=r)
    {
        m=(l+r)/2;
        if(A[m]<x)
            l=m+1;
        else if(A[m]>x)
            r=m-1;
        else
            return m;
    }
    return -1;
}

int main()
{
    int i,n,k,pos;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    pos = binarysearch(n-1,k);
    printf("%d\n", pos);
    return 0;
}
