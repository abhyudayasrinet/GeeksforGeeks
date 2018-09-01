//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
//incorrect test cases in the question

#include <iostream>
#include <stack>
using namespace std;


struct Node
{
    int data;
    Node *bottom;
    Node *next;
};

void print_list(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        Node *itr = head->bottom;
        while(itr != NULL) {
            cout<<itr->data<<"->";
            itr = itr->bottom;
        }
        head = head->next;
        cout<<endl;
    }
    cout<<endl;
}

Node* add_to_list(Node *head, int n, int x)
{
    Node *newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;
    newnode->bottom = NULL;
    if(head == NULL)
    {
        head = newnode;
        return head;
    }
    Node *itr = head;
    int i = 0;
    for(;i<n && itr->next != NULL;i++)
    {
        itr = itr->next;
    }
    if(itr->next == NULL && i!=n)
    {
        itr->next = newnode;
        return head;
    }
    Node *bt_itr = itr;
    while(bt_itr->bottom != NULL)
    {
        bt_itr = bt_itr ->bottom;
    }
    bt_itr->bottom = newnode;
    return head;
}

Node* flatten_list(Node *head)
{
    Node *list1 = head;
    Node *list2 = head->next;
    head->next = NULL;
    Node *l2_nextnode;
    while(list2 != NULL)
    {
        Node *nextlist = list2->next;
        list2->next = NULL;
        while(list1->bottom != NULL && list2 != NULL)
        {
            cout<<list2->data<<" "<<list1->bottom->data<<endl;
            if(list2->data < list1->bottom->data)
            {
                l2_nextnode = list2->bottom;
                list2->bottom = list1->bottom;
                list1->bottom = list2;
                list1 = list1->bottom;
                list2 = l2_nextnode;
            }
            else
            {
                list1 = list1->bottom;
            }
        }
        if(list2 != NULL)
            list1->bottom = list2;
        // cout<<"out"<<endl;
        // print_list(head);
        list1 = head;
        list2 = nextlist;
    }
    return head;
}

int a[1000];
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    Node *head = NULL;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            cin>>x;
            head = add_to_list(head,i,x);
        }
    }
    print_list(head);
    head = flatten_list(head);
    print_list(head);
    return 0;
}