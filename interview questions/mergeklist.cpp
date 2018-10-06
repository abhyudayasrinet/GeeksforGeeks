//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};

static void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref)    = new_Node;
}
 
 
// A utility function to print a linked list
void printList(struct Node *itr)
{
    while(itr != NULL)
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    // cout<<"x"<<endl;
    printf("");
}

void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {
        
        temp=Node;
        Node = Node->next;
        free(temp);
    }
  
}
Node * mergeKList(Node *arr[],int );
/* Driver program to test above function */
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	  
	   int N;
	   cin>>N;
       struct Node **arr = new Node *[N];
       for(int j=0;j<N;j++){
        //    cout<<"n:";
	        cin>>n; 
		    for(i=0;i<n;i++)
	    	{
			    cin>>x;
			    push(&arr[j], x);
			}
			reverse(&arr[j]);
		    //printList(arr[j]);
   		}
   		
   		Node *res = mergeKList(arr,N);
		printList(res);
		
	 
   }
   return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Linked list Node structure
struct Node
{
    int data;
    Node* next;
};*/ 
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
int heap[10000];
int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void insert_to_heap(int index, Node* arr[], int &heap_size)
{
    heap[heap_size] = index;
    heap_size++;
    int i = heap_size - 1;
    while(i!=0 && arr[heap[i]]->data < arr[heap[parent(i)]]->data)
    {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void heapify(int i, Node *arr[], int heap_size)
{
    if(i >= heap_size)
        return;

    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<heap_size && arr[heap[smallest]]->data > arr[heap[l]]->data)
        smallest = l;
    if(r<heap_size && arr[heap[smallest]]->data > arr[heap[r]]->data)
        smallest = r;
    if(smallest != i)
    {
        swap(heap[smallest], heap[i]);
        heapify(smallest, arr, heap_size);
    }
}

int get_root(int &heap_size, Node *arr[], int N)
{
    int root = heap[0];
    if(heap_size == 1)
    {
        heap_size--;
        return root;   
    }
    heap[0] = heap[heap_size-1];
    heap_size--;
    heapify(0, arr, heap_size);
    return root;
}


Node * mergeKList(Node *arr[], int N)
{
    int heap_size = 0;
    for(int i=0;i<N;i++) {
        // cout<<arr[i]->data<<endl;
        insert_to_heap(i, arr, heap_size);
    }
    // for(int i=0;i<heap_size;i++)
    // {
    //     cout<<heap[i]<<"-"<<arr[heap[i]]->data<<" ";
    // }
    // cout<<endl;

    Node *head = NULL;
    Node *tail = NULL;
    while(heap_size != 0)
    {
        int index = get_root(heap_size, arr, N);
        if(head == NULL)
        {
            head = tail = arr[index];
        }
        else
        {
            tail->next = arr[index];
            tail = arr[index];
        }
        arr[index] = arr[index]->next;
        if(arr[index] != NULL)
            insert_to_heap(index, arr, heap_size);
    }
    return head;
}