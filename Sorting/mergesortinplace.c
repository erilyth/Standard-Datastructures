//Including header files
#include <stdio.h>
#include <stdlib.h>

//Merge function
void merge(int A[], int start, int end) {
	
	//Variable declaration and initialisation
	int l,r,val,i,j,k,reml,remr,temp;
	reml=(start+end)/2-start+1;
	remr=end-start+1-reml;
	val=start; 
	l=start; 
	r=(start+end)/2+1;


	while(reml>0 && remr>0) {
		if(A[l]<A[r]) {
			A[val++]=A[l++];
			reml--;
		}
		else {
			temp=A[r];
			remr--;
			for(j=r-1; j>=l; j--)
				A[j+1]=A[j];
			l++; 
			r++;
			A[val++]=temp;
		}
			
	}

	while(reml>0) {
		A[val++]=A[l++];
		reml--;
	}

	while(remr>0) {
		A[val++]=A[r++];
		remr--;
	}

	return;
}

void mergesort(int A[], int start, int end) {
	
	if(end>start) {
		mergesort(A,start,(start+end)/2);
		mergesort(A,(start+end)/2+1,end);
		merge(A,start,end);
	}
	
	return;
}

//Main Function
int main() {
	//Varible declaration
	int i,j,a,n;
	scanf("%d", &n);
	int A[n];
	
	//INputting the elements of the array
	for(i=0;i<n;i++)
		scanf("%d", &A[i]);
	
	//Calling the mergesort function
	mergesort(A,0,n-1);
	
	//Outputting the sorted elements of the array
	for(i=0;i<n;i++)
		printf("%d ", A[i]);
	printf("\n");
	
	return 0;
}
