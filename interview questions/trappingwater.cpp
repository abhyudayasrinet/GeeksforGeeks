// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a[1000];
int ml[1000];
int mr[1000];

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
        ml[0] = 0;
        for(int i=1;i<n;i++)
        {
            if(a[i] <= a[ml[i-1]])
                ml[i] = ml[i-1];
            else
                ml[i] = i;
        }

        mr[n-1] = n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] <= a[mr[i+1]])
                mr[i] = mr[i+1];
            else
                mr[i] = i;
        }
        
        int water = 0;
        for(int i=1;i<n-1;i++)
        {
            if(ml[i] != i && mr[i] != i)
            {
                water += (a[ml[i]] > a[mr[i]] ? a[mr[i]] : a[ml[i]]) - a[i];
            }
        }
        cout<<water<<endl;
    }
    return 0;
}