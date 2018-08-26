//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0

#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

list<int> lst;


void insert_to_list(int x)
{
    list<int>::iterator itr;
    if(lst.size() == 0) //no element
    {
        lst.push_back(x);
    }
    else
    {
        itr = lst.begin();
        while(itr != lst.end())
        {
            if(*itr > x)
            {
                lst.insert(itr, x);
                return;
            }
            ++itr;
        }
        lst.push_back(x);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>k>>n;
        lst.clear();
        for(int i=0;i<k-1;i++)
        {
            cin>>x;
            cout<<"-1 ";
            insert_to_list(x);
        }
        cin>>x;
        insert_to_list(x);
        cout<<lst.front()<<" ";
        for(int i=0;i<n-k;i++)
        {
            cin>>x;
            if(x < lst.front())
                cout<<lst.front()<<" ";
            else
            {
                insert_to_list(x);
                lst.pop_front();
                cout<<lst.front()<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}