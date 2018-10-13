//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector <vector<int>> dp(n+1, vector <int> (k+1, 0));
        for(int i=1;i<=k;i++)
            dp[1][i] = i;
        for(int i=0;i<=n;i++)
            dp[i][1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                dp[i][j] = INT_MAX;
                for(int x=1;x<=j;x++)
                {
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
                }
            }
        }
        cout<<dp[n][k]<<endl;
    }
    return 0;
}