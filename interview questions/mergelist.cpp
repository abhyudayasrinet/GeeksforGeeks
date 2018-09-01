//https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

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

Node* merge_list(Node *head1, Node *head2)
{
    Node *prv, *temp;
    if(head2->data < head1 -> data)
    {
        temp = head2->next;
        head2->next = head1;
        head1 = head2;
        head2 = temp;
    }
    Node *itr1 = head1->next, *itr2 = head2;
    prv = head1;
    while(itr1 != NULL && itr2 != NULL)
    {
        if(itr2->data < itr1->data)
        {
            prv->next = itr2;
            temp = itr2->next;
            itr2->next = itr1;
            itr2 = temp;
            prv = prv->next;
        }
        else
        {
            prv = itr1;
            itr1 = itr1->next;
        }
    }
    if(itr2 != NULL)
    {
        prv->next = itr2;
    }
    return head1;
}

int main()
{
    int n1,n2,x;
    cin>>n1>>n2;
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
    print_list(head1);
    print_list(head2);
    head1 = merge_list(head1, head2);
    print_list(head1);
    return 0;
}