//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0

#include <cstdio>
#include <iostream>
using namespace std;

int a[100];
int buy[100];
int sell[100];
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
        int max_profit=0,profit;
        buy[n-1] = n-1;
        sell[n-1] = n-1;
        for(int i=n-2;i>=0;i--)
        {
            profit = a[sell[i+1]] - a[i];
            // cout<<profit<<endl;
            if(profit > max_profit)
            {
                buy[i] = i;
                sell[i] = sell[i+1];
                max_profit = profit;
            }
            else
            {
                buy[i] = sell[i] = i;
                max_profit = 0;
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<buy[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<sell[i]<<" ";
        // cout<<endl;
        int i = 0;
        int flag = 0;
        while(i<n)
        {
            if(buy[i] == sell[i])
            {
                i++;
                continue;
            }
            cout<<"("<<buy[i]<<" "<<sell[i]<<")"<<" ";
            flag = 1;
            i = sell[i]+1;
        }
        if(!flag)
            cout<<"No Profit";
        cout<<endl;
    }
    return 0;
}