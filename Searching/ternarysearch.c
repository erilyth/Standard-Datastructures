#include<stdio.h>
#include<stdlib.h>

int A[1000000];

int ternarysearch(int l, int r, int x)
{
    int lmid,rmid;
    lmid=(2*l+r)/3; rmid=(l+2*r)/3;
    while(lmid!=rmid)
    {
        if(x<=A[lmid])
            r=lmid;
        else if(x>A[rmid])
            l=rmid;
        else
        {
            l=lmid; r=rmid;
        }
        lmid=(2*l+r)/3; rmid=(l+2*r)/3;
    }
    if(x==A[r])
        return r;
    return -1;
}

int main()
{
    int i,n,k,pos;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    pos = ternarysearch(0,n-1,k);
    printf("%d\n", pos);
    return 0;
}
