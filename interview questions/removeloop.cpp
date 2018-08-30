//https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

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

void print_list(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
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

bool remove_loop(node *head)
{
    node *slow = head, *fast = head;
    while(true)
    {
        // cout<<"slow:"<<slow->data<<endl;
        // cout<<"fast:"<<fast->data<<endl;
        slow = slow->next;
        if(fast->next == NULL)
            return 0;
        fast = fast->next->next;
        if(fast == NULL)
            return 0;
        if(slow == fast)
        {
            // cout<<slow->data<<endl;
            break;
        }
    }
    if(slow == head && fast == head)
    {
        while(slow->next != head)
            slow = slow->next;
        slow->next = NULL;
        return 1;
    }
    slow = head;
    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return 1;
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
    print_list(head, n);
    remove_loop(head);
    print_list(head);
    return 0;
}