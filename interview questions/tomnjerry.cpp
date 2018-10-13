//https://practice.geeksforgeeks.org/problems/tom-and-jerry/0

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> dp(n+1,0);
        dp[1] = 0;
        dp[0] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    if(dp[i-j] == 0)
                        dp[i] = 1;
                    if(i/j != j && dp[i-i/j] == 0)
                        dp[i] = 1;
                }
            }
        }
        // for(int i=0;i<=n;i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;
        cout<<dp[n]<<endl;
    }
}