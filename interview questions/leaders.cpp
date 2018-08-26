//https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int a[1000];
int m[1000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> ans;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];            
        }
        m[n-1] = a[n-1];
        ans.push_back(a[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] > m[i+1])
            {
                m[i] = a[i];
                ans.push_back(a[i]);
            }
            else
                m[i] = m[i+1];
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}