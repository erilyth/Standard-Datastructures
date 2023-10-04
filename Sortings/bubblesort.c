#include <stdio.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int data[100],i,n,step,temp;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        printf("%d. Enter element: ",i+1);
        scanf("%d",&data[i]);
    }
    for(step=0;step<n-1;++step)
    {
    for(i=0;i<n-step-1;++i)
    {
        if(data[i]>data[i+1])   /* To sort in descending order, change > to < in this line. */
        {
            swap(&data[i],&data[i+1]);
        }
    }
    }
    printf("In ascending order: ");
    for(i=0;i<n;++i)
         printf("%d  ",data[i]);
    return 0;
}
