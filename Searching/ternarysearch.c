//Including Header Files
#include <stdio.h>
#include <stdlib.h>

//Ternary Search Functions
int ternarysearch(int A[], int l, int r, int x) {
    //Ternary search function variables
    int lmid,rmid;
    lmid=(2*l+r)/3; rmid=(l+2*r)/3;
    
    while(lmid!=rmid) {
        if(x<=A[lmid])
            r=lmid;
        else if(x>A[rmid])
            l=rmid;
        else {
            l=lmid; r=rmid;
        }
        lmid=(2*l+r)/3; rmid=(l+2*r)/3;
    }

    if(x==A[r])
        return r;
    return -1;
}

//Main Function
int main() {
    
    //Declaring a memory efficient array
    int i,n,k,pos;
    scanf("%d", &n);
    int A[n];
    
    //Inputting the values of the array
    for(i=0; i<n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    
    //Calling the ternary search function
    pos = ternarysearch(A,0,n-1,k);
    printf("%d\n", pos);
    return 0;
}
