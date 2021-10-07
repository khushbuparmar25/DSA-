#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
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

struct Node * insertAtFirst(struct node *head, int data)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->prev = NULL;
    ptr->data = data;
    head = ptr;
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
};

struct Node * insertAtIndex(struct Node * head, int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->prev = p;
    ptr->next = p->next;
    (p->next)->prev = ptr;
    p->next = ptr;
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


    printf("Doubly Linked list before insertion: \n");
    doublyLLTraversal(head);

    //head = insertAtFirst(head, 80);
    //head = insertAtEnd(head, 66);
    head = insertAtIndex(head, 44, 1);
    printf("Doubly Linked list after insertion: \n");
    doublyLLTraversal(head);

    return 0;
}
