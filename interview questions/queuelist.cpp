//https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
//front and rear not initialized properly in geeksforgeeks
#include <iostream>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

struct Queue
{
private:
    QueueNode *front;
    QueueNode *rear;
public :
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void push(int);
    int pop();    
};

/* The method push to push element into the queue*/
void Queue:: push(int x)
{
    QueueNode *newnode = new QueueNode();
    newnode->data = x;
    newnode->next = NULL;
    if(front == NULL)
    {
        front = newnode;
        rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}
/*The method pop which return the element poped out of the queue*/
int Queue :: pop()
{
    int data = front->data;
    QueueNode *temp = front;
    front = front->next;
    delete temp;
    return data;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue *sq = new Queue();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
}