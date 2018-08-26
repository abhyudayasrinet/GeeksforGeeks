//https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
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
        int s = 0;
        for(int i = 0; i < n-1; i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        int max = (n*(n+1))/2;
        cout<<(max-s)<<endl;
    }
    return 0;
}