//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

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

Node* rotate_list(Node *head, int k)
{
    Node *itr = head;
    for(int i=0;i<k-1;i++)
        itr=itr->next;
    if(itr->next == NULL)
        return head;
    Node *tail = itr;
    Node *newhead = itr->next;
    cout<<"tail:"<<tail->data<<endl;
    cout<<"newhead:"<<newhead->data<<endl;
    tail->next = NULL;
    itr = newhead;
    while(itr->next != NULL)
        itr = itr->next;
    itr->next = head;
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
    int k;
    cin>>k;
    print_list(head);
    head = rotate_list(head, k);
    print_list(head);
    return 0;
}