#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isFull(struct  stack * ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack * ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push (struct stack * ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Stack OverFlow \n");
    }
    else
    {
        ptr->top ++;
        ptr->arr[ptr->top] = val;
        printf("Element %d has been pushed to the stack successfully \n", val);
    }
}

int pop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underFlow \n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("Element %d has been popped from the stack successfully \n", val);
        return val;
    }
}

int main()
{
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    push(sp, 1);
    push(sp, 2);

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    pop(sp);

    return 0;
}
