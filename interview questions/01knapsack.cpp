//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,W;
        cin>>n>>W;
        vector <int> val(n, 0);
        vector <int> wt(n, 0);
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        vector<vector<int>> dp(n+1, vector <int> (W+1, 0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(wt[i-1] <= j)
                {
                    dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        cout<<dp[n][W]<<endl;
    }
    return 0;
}