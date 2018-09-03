//https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

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

Node *pairwise_swap(Node *head)
{
    Node *node1 = head, *node2 = head->next, *temp;
    temp = node2->next;
    node2->next = node1;
    node1->next = temp;
    head = node2;
    Node *prev = node1;

    node1 = prev->next;
    if(node1 == NULL)
        return head;
    node2 = prev->next->next;
    while(node1 != NULL && node2 != NULL)
    {
        temp = node2->next;
        node2->next = node1;
        node1->next = temp;
        prev->next = node2;

        prev = node1;
        node1 = prev->next;
        if(node1 == NULL)
            break;
        node2 = prev->next->next;
    }
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
    print_list(head);
    head = pairwise_swap(head);
    print_list(head);
    return 0;
}
