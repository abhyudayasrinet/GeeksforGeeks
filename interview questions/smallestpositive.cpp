//https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int a[100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> x(n+1,-1);
        int min_ = INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] > 0 && a[i] <= n)
                x[a[i]] = 1;
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(x[i] == -1)
            {
                ans = i;
                break;
            }
        }
        if(ans == 0)
            ans = n+1;
        cout<<ans<<endl;
    }
}