//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
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

void reverser(Node *current, Node **newhead)
{
    cout<<"current:"<<current->data<<endl;
    Node *nextnode = current->next;
    if(nextnode == NULL)
    {
        *newhead = current;
        return;
    }
    current->next = NULL;
    reverser(nextnode, newhead);
    nextnode->next = current;
}

Node* reverse_list(Node *head)
{
    reverser(head, &head);
    return head;
}

//better solution
Node* reverse_2(Node* head)
{
    if(head->next == NULL) return head;
    Node* newHead = reverse_2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    int n,x;
    Node *head = NULL;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head = add_to_end(head, x);
    }
    print_list(head);
    head = reverse_list(head);
    print_list(head);
    return 0;
}
