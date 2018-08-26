// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0

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
        int n,x,k;
        cin>>n;
        vector <int> a;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        cin>>k;
        sort(a.begin(), a.end());
        int index=0,i,j,temp;
        while(index<n)
        {
            i = index;
            j = i+k-1;
            if(j>=n)
                j = n-1;
            // cout<<i<<" "<<j<<endl;
            while(i<j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
            index += k;
        }
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}