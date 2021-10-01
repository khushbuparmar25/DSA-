#include <stdio.h>

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++ )
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");
}
int indInsertion(int arr[], int size, int capacity, int index, int element)
{
    if(size >= capacity)
    {
        return -1;
    }
    for(int i = size; i>= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int arr[50] = {5,19,1,30}, size=4, index=3, capacity, element = 25 ;
    display(arr, size);
    indInsertion(arr, size, capacity, index, element);
    size= size+1;
    display(arr, size);
    return 0;
}
