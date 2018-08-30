//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

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


Node* rotate_by_k(Node *head, int k)
{
    Node *current = head, *nextnode, *prev = NULL, *tail = head, *newhead=NULL;
    for(int i=0;i<k && current != NULL;i++)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
    // tail->next = current;
    if(current != NULL)
        newhead = rotate_by_k(current, k);
    tail->next = newhead;
    return head;
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
    int k;
    cin>>k;
    print_list(head);
    head = rotate_by_k(head,k);
    print_list(head);
    return 0;
}