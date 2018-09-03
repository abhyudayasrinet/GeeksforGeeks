//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
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

Node* add_numbers(Node *head1, Node *head2)
{
    int a,b,carry = 0,val;
    Node *newnum = NULL;
    while(head1 != NULL && head2 != NULL)
    {
        a = head1->data;
        b = head2->data;
        val = a + b + carry;
        if(val >= 10) {
            val -= 10;
            carry = 1;
        }
        else
            carry = 0;
        newnum = add_to_end(newnum, val);
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1 != NULL)
    {
        a = head1->data;
        val = a + carry;
        if(val >= 10)
        {
            val -= 10;
            carry = 1;
        }
        else
            carry = 0;
        newnum = add_to_end(newnum, val);
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        a = head2->data;
        val = a + carry;
        if(val >= 10)
        {
            val -= 10;
            carry = 1;
        }
        else
            carry = 0;
        newnum = add_to_end(newnum, val);
        head2 = head2->next;
    }
    if(carry)
        newnum = add_to_end(newnum, carry);
    return newnum;
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
    head1 = add_numbers(head1, head2);
    print_list(head1);
    return 0;
}