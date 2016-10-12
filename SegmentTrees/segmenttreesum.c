//Include header files
#include <stdio.h>
#include <stdlib.h>

//Segment tree consisting of sums

//Global variable declaration
int sumtree[100000]={0}; //The tree you construct
int val[100000]={0}; //Given array

//Makes the segment tree
int maketree(int start, int end, int index) {
	//Index is the position in the segment tree
	//Node 0 is the total sum, Node 1 is the left half sum, Node 2 is the right half sum and so on.....if n is the parent node then 2*n+1 and 2*n+2 are the left and right child nodes of the parent
	if(start==end) {
		sumtree[index]=val[start];
		return sumtree[index];
	}
	else {
	 	sumtree[index]=maketree(start,(start+end)/2,index*2+1)+maketree((start+end)/2+1,end,index*2+2);
		return sumtree[index];
	}
}

//Returnns the range of the sum
int rangesum(int start, int end, int fromwhere, int tillwhere, int index) {
	if(fromwhere>end || tillwhere<start) //The range you require is out of the range of the current index node
		return 0;
	else if(fromwhere<=start && tillwhere>=end) //The range you require is withing the range of current index node
		return sumtree[index];
	else //The range you require is partially within the range of current index node
		return rangesum(start,(start+end)/2,fromwhere,tillwhere,index*2+1)+rangesum((start+end)/2+1,end,fromwhere,tillwhere,index*2+2);
}

//Change value of the segment tree
void changeval(int start, int end, int pos, int valtoadd, int index) {
	if(start==end) {
		if(pos==start)
			sumtree[index]+=valtoadd;
		return;
	}
	if(pos>=start && pos<=end) { //Since the position to add value to in the array lies within the range of the current index node which is from start to end, we need to add valtoadd to the current index node and now we proceed to the subtrees where addition of this value may be required. 
		sumtree[index]+=valtoadd;
		changeval(start,(start+end)/2,pos,valtoadd,index*2+1);
		changeval((start+end)/2+1,end,pos,valtoadd,index*2+2);
		return;
	}
	if(pos<start || pos>end) //If the range of current index node does not have the position to change in it then we dont need to do anything
		return;
}

//Main function declaration
int main() {
	//Variable initialisation
	int i,j,k,a,b,c;
	for(i=0;i<10;i++)
		val[i]=i+1;
	//Make a segment tree
	maketree(0,9,0);
	printf("%d\n", rangesum(0,9,0,8,0)); 
	//Change the value of the segment tree
	changeval(0,9,8,10,0);
	printf("%d\n", rangesum(0,9,0,9,0));
	
	return 0;
}
