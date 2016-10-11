//Standard Header files for Input-Output
#include <stdio.h>
#include <stdlib.h>

//Linear Search function
void linearSearch(int arr[], int n, int key) {
  //Variable declaration
  int i;
  
  //Linear Search
  for(i = 0; i < n; i ++) {
    if(arr[i] == key) {
      printf("Key found at position %d",i);
      break;
    }
  }
  
}

//Main Function
int main() {
  //Memory-efficient array
  int n;
  scanf("%d",&n);
  int arr[n],key,x;
  
  //Key for element to search
  printf("Enter the value of the key");
  scanf("%d",&key);
  
  //Function call
  linearSearch(arr,n,key);
  return 0;
}
