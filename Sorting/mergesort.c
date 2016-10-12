//Including header files
#include <stdio.h>
#include <stdlib.h>

//Merge sort function
void merge(int A[], int start, int end) {
	
	//Variable declaration
	int l,r,val,i,j,k;
	int C[10000];
	
	//Variable initialisation
	val=start; 
	l=start; 
	r=(start+end)/2+1;

	while(l<=(start+end)/2 && r<=end) {
		if(A[l]<A[r])
			C[val++]=A[l++];
		else
			C[val++]=A[r++];
	}

	while(l<=(start+end)/2)
		C[val++]=A[l++];
	while(r<=end)
		C[val++]=A[r++];
	
	for(j=start;j<=end;j++)
		A[j]=C[j];
	
	return;
}

void mergesort(int A[], int start, int end) {
	
	//Mergesort-Algorithm
	if(end>start) {
		mergesort(A,start,(start+end)/2);
		mergesort(A,(start+end)/2+1,end);
		merge(A,start,end);
	}

	return;
}

int main() {
	
	//Variable declaration
	int i,j,a,n;
	scanf("%d", &n);
	//Memory efficient way to declare an array
	int A[n];

	//Inputting the elements of the array
	for(i = 0; i < n; i ++)
		scanf("%d", &A[i]);
	
	//Mergesort function call
	mergesort(A,0,n-1);
	
	//SOrted array being displayed
	for(i = 0; i < n; i ++)
		printf("%d ", A[i]);
	printf("\n");
	
	return 0;
}
