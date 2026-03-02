#include<stdio.h>
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void bubble_sort_rec(int arr[],int n)
{
    if(n==1)
    {
        return;
    }
    for(int j=0;j<=n-2;j++)
    {
        if(arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    bubble_sort_rec(arr,n-1);
}
int main()
{
    int arr[]={3,7,1,9,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    bubble_sort_rec(arr,n);
    display(arr,n);
    return 0;
}
