//https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

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
    node *itr = head;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    while(itr->next != NULL)
        itr = itr->next;
    itr->next = newnode;
    return head;
}

int print_middle(node *head)
{
    node *slow = head;
    node *fast = head;
    if(head->next == NULL)
        return head->data;

    while(true)
    {
        slow = slow->next;
        if(fast->next != NULL)
            fast = fast->next->next;
        else
            return slow->data;
        // cout<<"slow:"<<slow->data<<endl;
        // if(fast != NULL)
        //     cout<<"fast:"<<fast->data<<endl;
        if(fast == NULL || fast->next == NULL)
            return slow->data;
    }
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
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        node *head = NULL;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            head = add_to_end(head, x);
        }
        print_list(head);
        cout<<print_middle(head)<<endl;
    }
    return 0;
}