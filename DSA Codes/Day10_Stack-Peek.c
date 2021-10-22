#include<stdio.h>
#include<stdlib.h>


 struct stack
 {
     int size;
     int top;
     int * arr;
 };

 void push (struct stack * ptr, int val)
{
    ptr->top ++;
    ptr->arr[ptr->top] = val;
    printf("Element %d has been pushed to the stack successfully \n", val);
}

 int peek(struct stack * sp, int i)
 {
     if(sp->top -i + 1 < 0)
     {
         printf("Invalid Position");
         return -1;
     }
     else
     {
         return (sp->arr[sp->top - i + 1]);
     }
 }

 int main()
 {
     struct stack *sp= (struct stack *)malloc(sizeof(struct stack));
     sp->size = 50;
     sp->top = -1;
     sp->arr = (int *) malloc(sp->size * sizeof(int));

     push(sp, 1);
     push(sp, 23);
     push(sp, 99);
     push(sp, 75);

     for(int j = 1; j <= sp->top + 1; j++)
     {
         printf("The value at position %d is %d \n", j, peek(sp, j));
     }
     return 0;
 }
