#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == element)
        {
            printf("Element %d found at index %d \n", element, mid);
            return mid;
        }
        if(element > arr[mid] )
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("Element not found \n");
    return -1;
}

int main()
{
    int arr[] = {1,3,5,10,23,37,45,69,80,1000}, element = 1000;
    int size = sizeof(arr)/sizeof(int);
    binarySearch(arr, size, element);
    return 0;
}
