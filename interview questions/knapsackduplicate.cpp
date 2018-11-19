//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0

#include <iostream>
#include <vector>
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
        int n,w;
        cin>>n>>w;
        vector <int> val(n,0);
        vector <int> wt(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>wt[i];
        }

        vector <vector <int>> dp(n+1, vector <int> (w+1, 0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(wt[i-1] <= j)
                {
                    dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j-wt[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=w;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<dp[n][w]<<endl;
    }
    return 0;
}