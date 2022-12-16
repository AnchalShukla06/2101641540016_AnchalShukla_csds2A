#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *address;
    
    Node(int x)
    {
        data = x;
        address = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);


void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->address;
    }
    cout << endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->address = new Node(data);
            tail1 = tail1->address;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->address = new Node(data);
            tail2 = tail2->address;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

  

Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* ansHead = new Node(0), *ansPointer = ansHead;
    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            ansPointer->address = head1;
            ansPointer = head1;
            head1 = head1->address;
        }
        else
        {
            ansPointer->address = head2;
            ansPointer = head2;
            head2 = head2->address;
        }
    }
    while(head1)
    {
        ansPointer->address = head1;
        ansPointer = head1;
        head1 = head1->address;
    }
    while(head2)
    {
        ansPointer->address = head2;
        ansPointer = head2;
        head2 = head2->address;
    }
    return ansHead->address;
}