//https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

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
        itr = itr->next;
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

Node* sort012(Node *head)
{
    Node *ptr1 = head;
    Node *itr = head;
    Node *newhead = head, *nextnode, *prev;
    while(itr!=NULL)
    {
        nextnode = itr->next;
        if(itr->data == 0)
        {
            itr->next = newhead;
            newhead = itr;
            if(prev != NULL)
                prev->next = nextnode;
        }
        else if(itr->data == 1 && ptr1 != itr)
        {
            itr->next = ptr1->next;
            ptr1->next = itr;
            ptr1 = ptr1->next;
            if(prev != NULL)
                prev->next = nextnode;
        }
        else
        {
            prev = itr;
        }
        itr = nextnode;
    }
    return newhead;
}

int main()
{
    int n,x;
    cin>>n;
    Node *head = NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head = add_to_end(head, x);
    }
    print_list(head);
    head = sort012(head);
    print_list(head);
    return 0;
}