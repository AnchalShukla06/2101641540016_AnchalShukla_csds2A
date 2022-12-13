#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node* address;
} Node;

void insert_at_End(Node** head,int data)
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

    insert_at_End(&head,10);
    printLinkedList(head);

    insert_at_End(&head,20);
    printLinkedList(head);

    insert_at_End(&head,30);
    printLinkedList(head);

    insert_at_End(&head,40);
    printLinkedList(head);

    insert_at_End(&head,50);
    printLinkedList(head);

    return 0;
}