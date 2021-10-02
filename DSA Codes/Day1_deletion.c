#include <stdio.h>

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++ )
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");
}
void indDeletion(int arr[], int index, int size)
{
    for(int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    printf("\n");
}
 int main()
{
    int arr[100] = {5, 10, 2, 15}, size = 4, index = 2;
    display(arr, size);
    indDeletion(arr, index, size);
    size= size - 1;
    display(arr, size);
    return 0;
}
