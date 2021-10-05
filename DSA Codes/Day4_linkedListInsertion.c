#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct node *next;
};
int linkedlistTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr= ptr->next;
    }
    return 0;
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

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
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next =NULL;
    return head;
};

struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
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

    printf("Linked list before insertion is: \n");
    linkedlistTraversal(head);

    //head = insertAtFirst(head, 66);
    //head = insertAtIndex(head, 77, 1);
    //head = insertAtEnd(head, 88);
    head = insertAfterNode(head, second, 99);
    printf("Linked list after insertion is: \n");
    linkedlistTraversal(head);

    return 0;
}
