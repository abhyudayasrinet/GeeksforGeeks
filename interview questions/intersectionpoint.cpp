//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};


Node* add_to_end(Node *head, int x)
{
    Node *newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return head;
    }

    Node *itr = head;
    while(itr->next != NULL)
    {
        itr = itr->next;
    }

    itr->next = newnode;
    return head;
}

void print_list(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

int find_intersection(Node *head1, Node *head2)
{
    int n1 = 0, n2 = 0;
    Node *itr1 = head1, *itr2 = head2;
    while(itr1 != NULL)
    {
        n1++;
        itr1 = itr1->next;
    }
    while(itr2 != NULL)
    {
        n2++;
        itr2 = itr2->next;
    }
    int c = n2 > n1 ? n2 - n1 : n1 - n2;
    itr1 = head1;
    itr2 = head2;
    if(n2 > n1)
    {
        for(int i=0;i<c;i++)
            itr2 = itr2->next;
    }
    else
    {
        for(int i=0;i<c;i++)
            itr1 = itr1->next;
    }
    while(itr1 != NULL && itr2 != NULL && itr1 != itr2)
    {
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    if(itr1 == NULL || itr2 == NULL)
        return -1;
    return itr1->data;
}

int main()
{
    int n1,n2,n3,x;
    cin>>n1>>n2>>n3;
    Node *head1 = NULL, *head2 = NULL;
    for(int i=0;i<n1;i++)
    {
        cin>>x;
        head1 = add_to_end(head1, x);
    }
    for(int i=0;i<n2;i++)
    {
        cin>>x;
        head2 = add_to_end(head2, x);
    }
    Node *tail1 = head1, *tail2 = head2;
    while(tail1->next != NULL)
        tail1 = tail1->next;
    while(tail2->next != NULL)
        tail2 = tail2->next;
    for(int i=0;i<n3;i++)
    {
        cin>>x;
        Node *newnode = new Node();
        newnode->data = x;
        newnode->next = NULL;
        tail1->next = newnode;
        tail2->next = newnode;
        tail1 = newnode;
        tail2 = newnode;
    }
    print_list(head1);
    print_list(head2);
    cout<<find_intersection(head1, head2)<<endl;
    return 0;
}
