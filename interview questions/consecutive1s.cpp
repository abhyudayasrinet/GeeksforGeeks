//https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0

#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[2][101];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        dp[0][1] = 1;
        dp[1][1] = 1;
        for(int j=2;j<=n;j++)
        {
            dp[0][j] = (dp[0][j-1] + dp[1][j-1])%MOD;
            dp[1][j] = dp[0][j-1];
        }
        cout<<(dp[0][n] + dp[1][n])%MOD<<endl;
    }
    return 0;
}