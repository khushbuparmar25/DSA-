#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

int linkedlistTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
};

struct Node * deleteFirstNode(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
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

struct Node * deleteLast(struct Node * head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;

};

struct Node * deleteAtValue(struct Node * head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
};

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *) malloc(sizeof(struct Node));
    first = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 25;
    second->next = third;

    third->data = 50;
    third->next = NULL;

    printf("Linked list before deletion is: \n");
    linkedlistTraversal(head);

    //head = deleteFirstNode(head);
    //head = deleteAtIndex(head, 2);
    //head = deleteLast(head);
    head = deleteAtValue(head, 25);
    printf("Linked list after deletion is: \n");
    linkedlistTraversal(head);

    return 0;
}
