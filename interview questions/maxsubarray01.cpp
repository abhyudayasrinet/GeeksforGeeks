//https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

#include <cstdio>
#include <iostream>
#include <map>
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
        {
            cin>>a[i];
        }
        map <int,int> m;
        int curr_sum = 0;
        int max_len = 0;
        for(int i=0;i<n;i++)
        {
            curr_sum += (a[i] == 1 ? 1 : -1);
            if(curr_sum == 0)
            {
                if(i+1 > max_len) {
                    max_len = i+1;
                }
            }

            if(m.find(curr_sum) != m.end())
            {
                if(i - (m[curr_sum] + 1) + 1 > max_len)
                {
                    max_len =(i - (m[curr_sum] + 1) + 1 );
                }
            }
            else
                m[curr_sum] = i;
        }
        cout<<max_len<<endl;
    }
    return 0;
}