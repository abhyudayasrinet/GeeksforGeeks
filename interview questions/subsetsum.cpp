//https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        int sum = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            sum += a[i];
        }
        if(sum%2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            vector <vector <bool>> dp(n+1, vector <bool> (sum/2+1, false));
            for(int i=0;i<=n;i++)
                dp[i][0] = true;
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=sum/2;j++)
                {
                    if(j >= a[i-1])
                        dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }

            if(dp[n][sum/2])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}