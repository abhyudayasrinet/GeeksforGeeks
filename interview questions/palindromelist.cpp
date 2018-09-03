//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

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

bool checker(Node **head, Node *current)
{
    if(current->next == NULL)
    {
        if((*head)->data == current->data)
        {
            *head = (*head)->next;
            return true;
        }
        else
            return false;
    }

    bool val = checker( head, current->next);
    if(val && ((*head)->data == current->data))
    {
        *head = (*head)->next;
        return true;
    }
    else
        return false;
}

bool check_palindrome(Node *head)
{
    Node *current = head;
    return checker(&current, head);
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
    cout<<check_palindrome(head)<<endl;
    return 0;
}