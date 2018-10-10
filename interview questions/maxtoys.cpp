//https://practice.geeksforgeeks.org/problems/maximize-toys/0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k;
        vector <int> a;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());
        int count_ = 0;
        for(int i=0;i<n;i++)
        {
            if(k > a[i])
            {
                k -= a[i];
                count_++;
            }
        }
        cout<<count_<<endl;
    }
    return 0;
}