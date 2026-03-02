#include<stdio.h>
void display(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        while (i > 0 && arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }
}
int main()
{
    int arr[]={4,7,5,9,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    insertion_sort(arr,n);
    display(arr,n);
}