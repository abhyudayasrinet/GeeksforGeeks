//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int min_heap[1000000];
int max_heap[1000000];
int min_heap_size = 0;
int max_heap_size = 0;

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

void minHeapify(int i)
{
    if(i >= min_heap_size)
        return;

    int l = left(i);
    int r = right(i);
    int small = i;
    if(l < min_heap_size && min_heap[small] > min_heap[l])
        small = l;
    if(r < min_heap_size && min_heap[small] > min_heap[r])
        small = r;
    if(i != small)
    {
        swap(min_heap[small], min_heap[i]);
        minHeapify(small);
    }
}

int removeMinHeapRoot()
{
    if(min_heap_size == 1)
    {
        min_heap_size--;
        return min_heap[0];
    }

    //remove root node, replace with last entry, reduce size, heapify
    int root = min_heap[0];
    // cout<<"size:"<<min_heap_size<<endl;
    // cout<<root<<"-"<<min_heap[min_heap_size-1]<<endl;
    min_heap[0] = min_heap[min_heap_size-1]; 
    min_heap_size--;
    minHeapify(0);

    return root;
}

void insertMinHeap(int x)
{
    min_heap[min_heap_size] = x;
    min_heap_size++;
    int i=min_heap_size-1;
    while(i!=0 && min_heap[parent(i)] > min_heap[i]) //fix the heap
    {
        swap(min_heap[i], min_heap[parent(i)]);
        i = parent(i);
    }
}

void maxHeapify(int i)
{
    if(i >= max_heap_size)
        return;
    int l = left(i);
    int r = right(i);
    int large = i;
    if(l < max_heap_size && max_heap[large] < max_heap[l])
        large = l;
    if(r < max_heap_size && max_heap[large] < max_heap[r])
        large = r;
    if(large != i)
    {
        swap(max_heap[large], max_heap[i]);
        maxHeapify(large);
    }
}

int removeMaxHeapRoot()
{
    if(max_heap_size == 1)
    {
        max_heap_size--;
        return max_heap[0];
    }

    int root = max_heap[0];
    max_heap[0] = max_heap[max_heap_size-1];
    max_heap_size--;
    maxHeapify(0);

    return root;
}

void insertMaxHeap(int x)
{
    max_heap[max_heap_size] = x;
    max_heap_size++;
    int i=max_heap_size-1;
    while(i!=0 && max_heap[parent(i)] < max_heap[i]) //fix the heap
    {
        swap(max_heap[i], max_heap[parent(i)]);
        i = parent(i);
    } 
}

void processNumber(int x)
{
    if(max_heap_size == 0)
    {
        insertMaxHeap(x);
        return;
    }

    if(x > max_heap[0]) //insrt to maxheap 
    {
        insertMinHeap(x);
        // for(int k=0;k<min_heap_size;k++)
        //     cout<<min_heap[k]<<" ";
        // cout<<endl;
    }
    else
    {
        insertMaxHeap(x);
    }

    //resize heaps
    if(min_heap_size > max_heap_size + 1)
    {
        // cout<<"shifting min to max"<<endl;
        int root = removeMinHeapRoot();
        insertMaxHeap(root);
    }
    else if(max_heap_size > min_heap_size + 1)
    {
        int root = removeMaxHeapRoot();
        insertMinHeap(root);
    }
}

int getMedian()
{
    int n = max_heap_size + min_heap_size; 
    if(n%2 == 0)
    {
        return (max_heap[0] + min_heap[0])/2;
    }
    else
    {
        if(max_heap_size > min_heap_size)
            return max_heap[0];
        else
            return min_heap[0];
    }
}

void printheaps()
{
    cout<<"min_heap:";
    for(int i=0;i<min_heap_size;i++)
        cout<<min_heap[i]<<" ";
    cout<<endl;
    cout<<"max_heap:";
    for(int i=0;i<max_heap_size;i++)
        cout<<max_heap[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,x;
    cin>>n;
    // n = 10;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        // x = i;
        // cout<<"process "<<x<<endl;
        processNumber(x);
        // printheaps();
        cout<<getMedian()<<endl;
    }
    return 0;
}