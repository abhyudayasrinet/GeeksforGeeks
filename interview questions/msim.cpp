//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0

#include <cstdio>
#include <iostream>
using namespace std;

int a[1000];
int s[1000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s[i] = a[i];
        }
        int max = s[0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i] > a[j] && s[i] < s[j] + a[i]) 
                    s[i] = s[j] + a[i];
            }
            if(s[i] > max)
                max = s[i];
        }
        cout<<max<<endl;
    }
    return 0;
}