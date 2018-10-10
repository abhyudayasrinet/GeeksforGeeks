//https://practice.geeksforgeeks.org/problems/coin-piles/0

#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector <int> a(n);
        int min_ = INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] < min_)
                min_ = a[i];
        }
        int cut_ = min_ + k, ans = INT_MAX, count_;
        // cout<<cut_<<endl;
        for(int i=0;i<n;i++)
        {
            cut_ = a[i] + k;
            count_ = 0;
            for(int j=0;j<n;j++)
            {
                if(a[j] > cut_) {
                    // cout<<a[i]<<endl;
                    count_ += (a[j] - cut_);
                }
                else if(a[j] < a[i])
                    count_ += a[j];
            }
            // cout<<i<<" "<<count_<<endl;
            if(count_ < ans)
                ans = count_;
        }
        cout<<ans<<endl;
    }
    return 0;
}