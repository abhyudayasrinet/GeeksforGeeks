//https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        vector <int> a;
        // vector <bool> exists_(n,false);
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        int k;
        cin>>k;
        list <int> cache;
        int faults = 0,f;
        bool found;
        for(int i=0;i<a.size();i++)
        {
            // if(exists_[a[i]])
            // {
            found = false;
            list<int>::iterator it = cache.begin();
            while(*it != a[i] && it!=cache.end()) {
                it++;
            }
            if(it != cache.end())
                found = true;
            if(found) 
            {
                // cout<<"found:"<<a[i]<<endl;
                cache.erase(it);
                cache.push_back(a[i]);
            }
            else
            {
                // cout<<a[i]<<endl;
                faults++;
                if(cache.size() == k) {
                    cache.pop_front();
                }
                cache.push_back(a[i]);
            }
        }
        cout<<faults<<endl;
    }   
    return 0;
}