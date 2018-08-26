//https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0

#include <cstdio>
#include <iostream>
using namespace std;

int a[10000];
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
        int temp;
        bool flag = true;
        for(int i=0;i<n-1;i++)
        {
            if(flag) //a < b
            {
                if(a[i] > a[i+1])
                {
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
            else // a > b
            {
                if(a[i] < a[i+1])
                {
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
            flag = !flag;
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}