//https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0

#include <iostream>
#include <cstdio>
using namespace std;

int a[1000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        // int s = a[0];
        int low = 0, high = n-1,mid;
        while(low != high)
        {
            // cout<<low<<" "<<high<<endl;
            mid = (low+high)/2;
            
            if(mid%2 == 1)
            {
                if(a[mid] == a[mid-1])
                    low = mid + 1;
                else
                    high = mid;
            }
            else
            {
                if(a[mid] == a[mid+1])
                    low = mid + 2;
                else
                    high = mid;
            }
        }
        // cout<<low<<" "<<high<<endl;
        cout<<a[low]<<endl;
    }
    return 0;
}