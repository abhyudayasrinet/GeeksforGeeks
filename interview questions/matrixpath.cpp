//https://practice.geeksforgeeks.org/problems/path-in-matrix/0

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <vector <int>> m(n, vector <int> (n,0));
        vector <vector <int>> dp(n, vector <int> (n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>m[i][j];
                if(i==0)
                    dp[i][j] = m[i][j];
            }
        }
        int max_ = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    dp[i][j] = m[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                else if(j==n-1)
                    dp[i][j] = m[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                else
                    dp[i][j] = m[i][j] + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
                if(i==n-1 && max_ < dp[i][j])
                    max_ = dp[i][j];
            }
        }
        cout<<max_<<endl;
    }
    return 0;
}