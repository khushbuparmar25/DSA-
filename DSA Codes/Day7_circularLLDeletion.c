#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void circularLLTraversal(struct Node * head)
{
    struct Node *ptr = head;
    do
    {
        printf("Elements : %d \n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
};

struct Node * deleteAtStart(struct Node * head)
{
    struct Node * ptr = head;
    while(ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    head = ptr->next;
    return head;
};

struct Node * deleteAtIndex(struct Node * head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};

struct Node * deleteAtEnd(struct Node * head)
{
    struct Node * ptr = head->next;
    while((ptr->next)->next != head)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = head;
    return head;
};

int main()
{
    struct Node * head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *) malloc(sizeof(struct Node));
    first = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 2;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 25;
    second->next = third;

    third->data = 50;
    third->next = head;

    printf("Circular Linked list before deletion is: \n");
    circularLLTraversal(head);

    //head = deleteAtStart(head);
    //head = deleteAtEnd(head);
    head = deleteAtIndex(head, 2);
    printf("Circular Linked list after deletion is: \n");
    circularLLTraversal(head);

    return 0;
}
