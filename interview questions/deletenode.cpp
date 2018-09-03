//https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1

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

void delete_node(Node *node)
{
    Node *curr = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    delete curr;
}

int main()
{
    int n,x;
    cin>>n; //use min 3
    Node *head = NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head = add_to_end(head, x);
    }
    print_list(head);
    Node *to_del = head->next->next; //make it point to 3rd node
    delete_node(to_del);
    print_list(head);
    return 0;
}