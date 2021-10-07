#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void circularLLTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Elements : %d \n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);

    //Another way for traversal
    //while(ptr->next != head)
    //{
    //    printf("Elements : %d \n", ptr->data);
    //    ptr = ptr->next;
    //}
}

struct Node * insertionAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;

    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
};

struct Node * insertAtIndex(struct Node *head, int data, int index)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

struct Node * insertAtEnd(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next != head)
    {
        p=p->next;
    }
    ptr->data = data;
    p->next = ptr;
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

    printf("Circular Linked list before insertion is: \n");
    circularLLTraversal(head);

    //head = insertionAtFirst(head, 50);
    //head = insertAtIndex(head, 99, 1);
    head = insertAtEnd(head, 100);
    printf("Circular Linked list after insertion is: \n");
    circularLLTraversal(head);
    return 0;
}
