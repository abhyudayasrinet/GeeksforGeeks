//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2;
        cin>>n1>>n2;
        string a,b;
        cin>>a>>b;

        vector <vector <int>> dp(n1+1, vector <int> (n2+1,0));
        int max_ = 0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(a[i-1] == b[j-1])
                    dp[i][j] = max(dp[i-1][j-1] + 1,dp[i][j]);
                if(dp[i][j] > max_)
                    max_ = dp[i][j];
            }
        }
        cout<<max_<<endl;
    }
    return 0;
}