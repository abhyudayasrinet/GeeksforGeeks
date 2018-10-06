//https://practice.geeksforgeeks.org/problems/rearrange-characters/0

#include <iostream>
#include <deque>
#include <map>
#include <string>
#include <vector>
using namespace std;

int left(int i)
{
    return 2*i+1;
}

int right(int i)
{
    return 2*i+2;
}

int parent(int i)
{
    return (i-1)/2;
}

void swap(char &a, char &b)
{
    char t = a;
    a = b;
    b = t;
}

void heapify(int i, int &heap_size, vector <char> &heap, map <char,int> m)
{
    if(i>=heap_size)
        return;
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l < heap_size && m[heap[l]] > m[heap[largest]])
        largest = l;
    if(r < heap_size && m[heap[r]] > m[heap[largest]])
        largest = r;
    if(largest != i)
    {
        swap(heap[largest], heap[i]);
        heapify(largest, heap_size, heap, m);
    }
}

void insert_to_heap(vector <char> &heap, int &heap_size, map<char,int> m, char ch)
{
    heap[heap_size] = ch;
    heap_size++;
    int i = heap_size-1;
    while(i!=0 && m[heap[parent(i)]] < m[heap[i]])
    {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

char removeRoot(int &heap_size, vector <char> &heap, map<char,int> m)
{
    char root;
    if(heap_size == 1)
    {
        root = heap[0];
        heap_size--;
        return root;
    }
    root = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;
    heapify(0, heap_size, heap, m);
    return root;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        map <char,int> m;
        vector <char> heap(600);
        int heap_size = 0;

        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        map <char,int>::iterator itr = m.begin();
        for(;itr!=m.end();itr++)
        {
            insert_to_heap(heap, heap_size, m, itr->first);
        }
        int x;
        int  flag = 0,reinsert = 0;
        char ch,root;
        while(heap_size != 0)
        {
            ch = heap[0];
            m[ch]--;
            if(m[ch] == 0) 
                removeRoot(heap_size, heap, m);
            else {
                reinsert = 1;
                root = removeRoot(heap_size, heap, m);
            }
            
            if(heap_size > 0)
            {
                ch = heap[0];
                m[ch]--;
                if(m[ch] == 0)
                    removeRoot(heap_size, heap, m);
                if(reinsert) {
                    insert_to_heap(heap, heap_size, m, root);
                    reinsert = 0;
                }
            }
            else if(heap_size == 0 && m[root] > 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}