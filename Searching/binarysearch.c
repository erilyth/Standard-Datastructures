//Including Header files
#include <stdio.h>
#include <stdlib.h>

//Binary Search function
int binarysearch(int A[],int size, int x) {
    //Variable declaration
    int l,r,m;
    l=0; 
    r=size;

    //Binary Search implementation
    while(l<=r) {
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

//Main Function
int main() {

    //Declaring a memory-efficient array
    int i,n,k,pos;
    scanf("%d", &n);
    int A[n];

    //Inputting the values of the array
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);

    //Calling the search function
    pos = binarysearch(A,n-1,k);
    printf("%d\n", pos);
    
    return 0;
}
