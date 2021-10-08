#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
};

void doublyLLTraversal(struct Node * head)
{
    struct Node *ptr = head;

    while(ptr != NULL)
    {
        printf("Elements :%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deletionAtFirst(struct Node * head)
{
    struct Node * ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
};

struct Node * deleteAtEnd(struct Node * head)
{
    struct Node * ptr = head;
    if(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
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
    third->next = NULL;


    printf("Doubly Linked list before deletion: \n");
    doublyLLTraversal(head);

    //head = deletionAtFirst(head);
    //head = deleteAtEnd(head);
    head = deleteAtIndex(head,2);
    printf("Doubly Linked list after deletion: \n");
    doublyLLTraversal(head);

    return 0;
}
