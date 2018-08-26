//https://practice.geeksforgeeks.org/problems/unsorted-array/0

#include <cstdio>
#include <iostream>
using namespace std;

int a[1000000];
int x[1000000];
int y[1000000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        x[0] = a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i] > x[i-1])
                x[i] = a[i];
            else
                x[i] = x[i-1];
        }
        y[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] < y[i+1])
                y[i] = a[i];
            else
                y[i] = y[i+1];
        }

        // for(int i=0;i<n;i++)
        //     cout<<x[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<y[i]<<" ";
        // cout<<endl;
        int flag = 0;
        for(int i=1;i<n-1;i++)
        {
            if(x[i-1] <= a[i] && a[i] <= y[i+1])
            {
                // cout<<x[i-1]<<" "<<y[i+1]<<endl;
                flag = 1;
                cout<<a[i]<<endl;
                break;
            }
        }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}