//https://practice.geeksforgeeks.org/problems/equilibrium-point/0

#include <cstdio>
#include <iostream>
using namespace std;

int a[1000];
int s1[1000];
int s2[1000];
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
        }
        s1[0]=a[0];
        for(int i=1;i<n;i++)
        {
            s1[i] = s1[i-1] + a[i];
            // cout<<s1[i]<<" ";
        }
        // cout<<endl;
        s2[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            s2[i] = s2[i+1] + a[i];
            // cout<<s2[i]<<" ";
        }
        // cout<<endl;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i])
            {
                ans = i+1;
                break;
            }
        }
        if(ans == 0)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}