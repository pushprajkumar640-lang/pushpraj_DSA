#include<stdio.h>
void display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertion_sort_rec(int arr[], int n, int i)
{   
    if(i==n)  return;
        while (i > 0 && arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
        insertion_sort_rec(arr,n,i+1);
}
int main()
{
    int arr[]={2,5,0,7,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    insertion_sort_rec(arr,n,0);
    display(arr,n);
}