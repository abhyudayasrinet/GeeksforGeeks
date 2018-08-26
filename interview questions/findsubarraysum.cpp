// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

#include <cstdio>
#include <iostream>
using namespace std;

int a[1000];
int s[1000];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i==0)
                s[i] = a[i];
            else
                s[i] = a[i] + s[i-1];
        }

        int curr_sum = 0;
        int start = 0,end = 0;
        int i = 0, flag = 0;
        while(i<n)
        {
            curr_sum = curr_sum + a[i];
            while(curr_sum > x)
            {
                curr_sum -= a[start];
                start++;
            }
            if(curr_sum == x)
            {
                cout<<start+1<<" "<<end+1<<endl;
                flag = 1;
                break;
            }
            i++;
            end = i;
        }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}