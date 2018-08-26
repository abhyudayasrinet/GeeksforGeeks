//https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
#include <cstdio>
#include <iostream>
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
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        int max = a[0];
        int current = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] + current > 0)
            {
                current = a[i] + current;
                if(current > max)
                    max = current;
            }
            else
            {
                current = 0;
                if(a[i] > max)
                    max = a[i];
            }
        }
        cout<<max<<endl;
    }
    return 0;
}