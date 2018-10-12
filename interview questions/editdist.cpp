//https://practice.geeksforgeeks.org/problems/edit-distance/0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int min(int a, int b)
{
    if(a<b)
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
        vector <vector<int>> dp(n1+1, vector <int> (n2+1, 0));
        for(int i=0;i<=n1;i++)
            dp[i][0] = i;
        for(int j=0;j<=n2;j++)
            dp[0][j] = j;

        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        cout<<dp[n1][n2]<<endl;
    }
    return 0;
}