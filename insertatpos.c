#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* address;
} Node;

void insert_at_Head(Node** head,int data)
{
    Node* temp = (Node*)calloc(1,sizeof(Node));
    temp->data = data;
    if(!*head)
        *head = temp;
    else
    {
        temp->address = *head;
        *head = temp;
    }
}

void insert_at_End(Node** head,int data)
{
    Node* temp = (Node*)calloc(1,sizeof(Node));
    temp->data = data;
    if(!*head)
        *head = temp;
    else
    {
        Node* s = *head;
        while(s->address!=NULL)
            s = s->address;
        s->address = temp;
    }
}

void insert_at_position(Node** head,int data,int data_before)
{
    Node* temp = (Node*)calloc(1,sizeof(Node));
    temp->data = data;
    if((*head)->data == data_before)
        insert_at_Head(head,data);
    else
    {
        Node* s = *head;
        while(s->address->data != data_before)
            s = s->address;
        temp->address = s->address;
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

    insert_at_position(&head,0,10);
    printLinkedList(head);

    insert_at_position(&head,15,20);
    printLinkedList(head);

    insert_at_position(&head,45,50);
    printLinkedList(head);

    return 0;
}