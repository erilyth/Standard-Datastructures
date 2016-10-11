//Including the header files
#include <stdio.h>
#include <stdlib.h>

//Ternary Search Recursive Functions
int ternarysearchrecursive(int A[], int l, int r, int x) {
    
    //Variable declaration
    int lmid,rmid;
    
    if(A[r]==x)
        return r;
    
    lmid=(2*l+r)/3; rmid=(l+2*r)/3;
    
    if(lmid==rmid && A[rmid]!=x)
        return -1;
    
    if(x<A[lmid])
        return ternarysearchrecursive(A,l,lmid,x);
    else if (x>A[rmid])
        return ternarysearchrecursive(A,rmid,r,x);
    
    return ternarysearchrecursive(A,lmid,rmid,x);
}

//Main function
int main() {
    
    //Declaring a memory-efficient array
    int i,n,k,pos;
    scanf("%d", &n);
    int A[n];
    
    //Inputting the values of the array
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    
    //Search function calling
    pos = ternarysearchrecursive(A,0,n-1,k);
    printf("%d\n", pos);
    return 0;
}
