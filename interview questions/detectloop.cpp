//https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

#include <cstdio>
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node* add_to_end(node *head, int x)
{
    node *newnode = new node();
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    node *itr = head;
    while(itr->next != NULL)
        itr = itr->next;
    
    itr->next = newnode;
    return head;
}

void print_list(node *head, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data;
    cout<<endl;
}

node* make_loop(node *head, int k)
{
    if(k == -1)
        return head;
    node *curr = head;
    int i = 0;
    while(curr->next != NULL)
        curr = curr->next;
    node *tail = curr;
    curr = head;
    while(curr!=NULL)
    {
        if(i==k)
        {
            tail->next = curr;
            break;        
        }
        curr = curr->next;
        i++;
    }
    return head;
}

bool detect_loop(node *head)
{
    node *slow = head, *fast = head;
    while(true)
    {
        cout<<"slow:"<<slow->data<<endl;
        cout<<"fast:"<<fast->data<<endl;
        slow = slow->next;
        if(fast->next == NULL)
            return false;
        fast = fast->next->next;
        if(fast == NULL)
            return false;
        if(slow == fast)
        {
            cout<<slow->data<<endl;
            return true;
        }
            
    }
}

int main()
{
    int n,x,k;
    cin>>n;
    node *head = NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        head = add_to_end(head, x);
    }
    cin>>k;
    head = make_loop(head, k);
    // print_list(head, n);
    cout<<detect_loop(head)<<endl;
    return 0;
}