#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for(int i = 0; i < size; i++)
    {
        if(element==arr[i])
        {
            printf("Element %d found at index %d \n",element, i);
            return i;
        }
    }
    printf("Element not found \n");
    return -1;
}

int main()
{
    int arr[50] = {2,65,32,6,15,100}, element = 100;
    int size = sizeof(arr)/ sizeof(int);
    linearSearch(arr, size, element);
    return 0;
}
