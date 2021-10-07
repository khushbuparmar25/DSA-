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
    ptr->data = data;
	ptr->next = head;
	ptr->prev=NULL;

	head = ptr;
	return head;
}

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

    head = insertAtFirst(head, 80);
    printf("Doubly Linked list after insertion: \n");
    doublyLLTraversal(head);

    return 0;
}
