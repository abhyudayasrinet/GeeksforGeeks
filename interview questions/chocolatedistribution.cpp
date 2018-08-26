//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x;
        vector <int> a;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        cin>>m;
        sort(a.begin(),a.end());
        int min = a[m-1] - a[0];
        for(int i=1;i<n-m+1;i++)
        {
            if(min > a[i+m-1] - a[i])
                min = a[i+m-1] - a[i];
        }
        cout<<min<<endl;
    }
    return 0;
}