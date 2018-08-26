//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;


int a[10000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        deque <int> d;
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int i = 0;
        for(;i<k;i++)
        {
            while(!d.empty() && a[d.back()] < a[i])
                d.pop_back();
            d.push_back(i);
        }
        for(;i<=n;i++)
        {
            cout<<a[d.front()]<<" ";
            while(!d.empty() && d.front() <= i-k)
                d.pop_front();
            
            while(!d.empty() && a[d.back()] < a[i])
                d.pop_back();
            
            d.push_back(i);
        }
        cout<<endl;
    }
}