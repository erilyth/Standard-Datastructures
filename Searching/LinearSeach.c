//Standard Header files for Input-Output
#include <stdio.h>
#include <stdlib.h>

//Linear Search function
void linearSearch(int arr[], int n, int key) {
  int i;
  for(i = 0; i < n; i ++) {
    if(arr[i] == key) {
      printf("Key found at position %d",i);
      break;
    }
  }
}

//Main Function
int main() {
  int n;
  scanf("%d",&n);
  int arr[n],key,x;
  printf("Enter the value of the key");
  scanf("%d",&key);
  linearSearch(arr,n,key);
  return 0;
}
