//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum = 0;
        vector <int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
        }    
        vector <vector <bool>> dp(n+1, vector <bool> (sum+1, false));
        for(int i=0;i<=n;i++)
            dp[i][0] = true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=a[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
        int min_diff = INT_MAX;
        for(int j=1;j<=sum;j++)
        {
            if(dp[n][j])
            {
                int subset1 = j;
                int subset2 = sum-j;
                if(abs(subset1 - subset2) < min_diff)
                    min_diff = abs(subset1 - subset2);
            }
        }
        cout<<min_diff<<endl;
    }
    return 0;
}