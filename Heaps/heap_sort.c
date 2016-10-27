#include<stdio.h>
#include<conio.h>
void crheap(int [], int);
void processheap(int [],int);
int main(void)
{
   int k[50],child,parent,q,key,n,t,i;
   clrscr();
   printf("\n enter the no. of elements: ");
   scanf(" %d",&n);
   printf("\n Now enter the array elements: ");
   for(i=1;i<=n;i++)
       scanf(" %d",&k[i]);
   crheap(k,n);
   processheap(k,n);
   return(0);
}
void crheap(int k[],int n)
{
 int i,q, parent,child,temp;
 for(q=2;q<=n;q++)
 {
  child=q;
  parent=(int)child/2;
  while(child >1 && k[child] > k[parent])
  {
    temp=k[child];
    k[child]= k[parent];
    k[parent]=temp;
    child=parent;
    parent=(int)child/2;
    if(parent < 1)
       parent=1;
  }
 }
 printf("\n Now the array in heap form is: ");
  for(i=1;i<=n;i++)
    printf(" %3d",k[i]);
}

void processheap(int k[],int n)
{
 int current,parent,child,i,maxnodes;
 for(maxnodes=n;maxnodes>=2;maxnodes--)
 {
  current=k[maxnodes];;
  k[maxnodes]=k[1];
  /* adjust the array to be a heap of size n-1 */
  parent=1;
  /* obtain the larger of the root's children */
  if (maxnodes-1 >= 3 && k[3] > k[2])
      child=3;
  else
      child = 2;
  /* move keys upwards to find place for current */
  while (child<=maxnodes-1 && k[child]>=current)
  {
   k[parent]=k[child];
   parent=child;
   child=child*2;
   if(child+1 <= maxnodes-1 && k[child+1] > k[child])
	 child = child + 1;
  }
  k[parent]=current;
 } /* end of for */
 printf("\n The sorted array is : ");
 for(i=1;i<=n;i++)
     printf("%4d",k[i]);
getch();
}
