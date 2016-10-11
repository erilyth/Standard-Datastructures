//Including the header files
#include <stdio.h>
#include <stdlib.h>

//Binary Search Recursive function
int binarysearchrecursive(int A[],int l, int r, int x) {
    
    //Varible declaration
    int m;
    
    if(l>r)
        return -1;
    
    m=(l+r)/2;
    
    if(A[m]<x)
        return binarysearchrecursive(A,m+1,r,x);
    else if (A[m]>x)
        return binarysearchrecursive(A,l,m-1,x);
    else
        return m;
}

//Main function devclaration
int main() {
    //Declaring a memory efficient array
    int i,n,k,pos;
    scanf("%d", &n);
    int A[n];

    //Inputting the values of the array
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    
    //Calling the Binary Search function
    pos = binarysearchrecursive(A,0,n-1,k);
    printf("%d\n", pos);
    
    return 0;
}
