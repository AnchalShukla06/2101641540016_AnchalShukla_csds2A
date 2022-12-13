#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node* address;
} Node;

void insertAtEnd(Node** head,int data)
{
    Node* temp = (Node*)calloc(1,sizeof(Node));
    temp->data = data;
    if(!*head)
        *head = temp;
    else
    {
        Node* s = *head;
        while(s->address)
            s = s->address;
        s->address = temp;
    }
}

void deletionAtEnd(Node** head)
{
    if(!(*head)->address)
    {
        free(*head);
        *head =  NULL;
    }
    else
    {
        Node* s = *head;
        while(s->address->address)
            s = s->address;
        free(s->address);
        s->address = NULL;
    }
}

void printLinkedList(Node* head)
{
    if(!head)
        printf("Empty Linked List...\n");
    else
    {
        while(head)
        {
            printf("%d ",head->data);
            head = head->address;
        }
        printf("\n");
    }
}

int main()
{
    Node* head = NULL;
    
    printLinkedList(head);

    insertAtEnd(&head,10);
    printLinkedList(head);

    insertAtEnd(&head,20);
    printLinkedList(head);

    insertAtEnd(&head,30);
    printLinkedList(head);

    insertAtEnd(&head,40);
    printLinkedList(head);

    insertAtEnd(&head,50);
    printLinkedList(head);

    deletionAtEnd(&head);
    printLinkedList(head);

    return 0;
}