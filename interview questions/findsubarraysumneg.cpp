//https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum/0

#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int a[1000];
int main()
{
    unordered_map<int,int> m;
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int curr_sum = 0;
    int i=0;
    while(i<n)
    {
        curr_sum += a[i];
        if(curr_sum == x)
        {
            cout<<0<<" "<<i<<endl;
            break;
        }

        if(m.find(curr_sum - x) != m.end())
        {
            cout<<m[curr_sum - x]+1<<" "<<i<<endl;
            break;
        }

        m[curr_sum] = i;
        i++;
    }
    return 0;
}