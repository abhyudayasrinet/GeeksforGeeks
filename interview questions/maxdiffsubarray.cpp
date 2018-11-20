//https://practice.geeksforgeeks.org/problems/max-absolute-difference/0

#include <iostream>
#include <vector>
#include <climits>
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
        int n;
        cin>>n;
        vector <int> a(n, 0);
        for(int i=0;i<n;i++)
            cin>>a[i];

        int max_ = a[0], curr_sum = a[0];
        vector <int> maxLeft(n,0);
        maxLeft[0] = a[0];
        // cout<<a[0]<<" ";
        for(int i=1;i<n;i++)
        {
            curr_sum = max(curr_sum + a[i], a[i]);
            max_ = max(max_, curr_sum);
            maxLeft[i] = max_;
            // cout<<maxLeft[i]<<" ";
        }
        // cout<<endl;

        vector <int> maxRight(n, 0);
        maxRight[n-1] = a[n-1];
        curr_sum = a[n-1];
        max_ = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            curr_sum = max(curr_sum + a[i], a[i]);
            max_ = max(max_, curr_sum);
            maxRight[i] = max_; 
        }
        // for(int i=0;i<n;i++)
        //     cout<<maxRight[i]<<" ";
        // cout<<endl;

        vector <int> minLeft(n, 0);
        minLeft[0] = a[0];
        curr_sum = -a[0];
        max_ = -a[0];
        for(int i=1;i<n;i++)
        {
            curr_sum = max(-a[i], curr_sum + (-a[i]));
            max_ = max(max_, curr_sum);
            minLeft[i] = -max_;
        }
        // for(int i=0;i<n;i++)
        //     cout<<minLeft[i]<<" ";
        // cout<<endl;


        vector <int> minRight(n,0);
        minRight[n-1] = a[n-1];
        curr_sum = -a[n-1];
        max_ = -a[n-1];
        for(int i = n-2;i>=0;i--)
        {
            curr_sum = max(curr_sum + (-a[i]), -a[i]);
            max_ = max(max_, curr_sum);
            minRight[i] = -max_;
        }
        // for(int i=0;i<n;i++)
        //     cout<<minRight[i]<<" ";
        // cout<<endl;

        int ans = INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            int val1 = abs(minLeft[i] - maxRight[i+1]);
            int val2 = abs(maxLeft[i] - minRight[i+1]);
            if(val1 >= val2 && val1 > ans)
                ans = val1;
            if(val1 < val2 && val2 > ans)
                ans = val2;
        }
        cout<<ans<<endl;
    }
    return 0;
}