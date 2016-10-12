//Include header files
#include <stdio.h>
#include <stdlib.h>
//Include time header file for random variable
#include <time.h>

//Global variable n declared
int n;

int partition(int A[], int start, int end, int pivot) {
	
	//Variable declaration
	int i,j,a,b,c,piv,temp;
	
	//Variable initialisation
	piv=A[pivot];
	temp=A[pivot];
	A[pivot]=A[end];
	A[end]=temp;
	int place=start;
	
	//Quick Sort implementation
	for(i=start; i<=end; i++) {	
		if(A[i]<=piv) {
			temp=A[place];
			A[place]=A[i];
			A[i]=temp;
			place++;
		}
	}

	return place-1;
}

void quick(int A[], int start, int end) {
	

	int newpiv,random;
	
	if(start<end) {
		//Random Variable initialisation
		srand(time(NULL));
		random=rand();
		random=start+random%(end-start);
		//Pivot declaration
		newpiv=partition(A,start,end,random);
		quick(A,start,newpiv-1);
		quick(A,newpiv+1,end);
	}
}

//Main functionn declaration
int main() {
	//Variable initialisation
	int i;
	scanf("%d", &n);
	//Memory efficient way to declare array
	int A[n];
	
	//Inputting the values of the array
	for(i=0; i<n; i++)
		scanf("%d", &A[i]);
	
	//Quicksort function calling
	quick(A,0,n-1);
	
	//Printing the Sorted values
	for(i=0;i<n;i++)
		printf("%d ", A[i]);
	printf("\n");
	
	return 0;
}
