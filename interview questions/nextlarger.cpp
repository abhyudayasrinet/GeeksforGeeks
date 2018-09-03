//https://practice.geeksforgeeks.org/problems/next-larger-element/0

#include <iostream>
#include <stack>
using namespace std;

int a[10000];
int r[10000];
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
        r[n-1] = -1;
        stack <int> s;
        s.push(a[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(a[i] < s.top())
            {
                r[i] = s.top();
            }
            else
            {
                while(!s.empty() && a[i] > s.top())
                {
                    s.pop();
                }
                if(!s.empty())
                {
                    r[i] = s.top();
                }
                else
                    r[i] = -1;
                
            }
            s.push(a[i]);
        }
        for(int i=0;i<n;i++)
            cout<<r[i]<<" ";
        cout<<endl;
    }
    return 0;
}