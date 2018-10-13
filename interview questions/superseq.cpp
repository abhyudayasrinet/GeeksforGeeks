//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int n=a.size(), m = b.size();
        vector <vector <int>> dp(n+1, vector <int> (m+1, 0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(a[i-1] == b[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<dp[n][m]<<endl;
        cout<<a.size()-dp[n][m] + b.size()-dp[n][m] + dp[n][m]<<endl;
    }
    return 0;
}