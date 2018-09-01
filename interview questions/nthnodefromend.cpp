//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

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

Node *finder(Node *current, int n, int &k)
{
    if(current->next == NULL)
    {
        k++;
        return current;
    }
    Node *nthnode = finder(current->next, n, k);
    if(k == n)
        return nthnode;
    k++;
    return current;
}

Node* find_nth(Node *head, int n)
{
    int i = 0;
    Node *nthnode = finder(head, n, i);
    if(i < n)
        return NULL;
    return nthnode;
}



int main()
{
    int n,k,x;
    cin>>n>>k;
    Node *head = NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head = add_to_end(head, x);
    }
    print_list(head);
    Node *nthnode = find_nth(head, k);
    if(nthnode == NULL)
        cout<<-1<<endl;
    else
        cout<<nthnode->data<<endl;
    return 0;
}