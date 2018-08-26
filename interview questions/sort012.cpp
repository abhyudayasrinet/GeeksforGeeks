//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        int zero = 0, ones = 0, twos = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>x;
            switch(x)
            {
                case 0:
                    zero++;
                    break;
                case 1:
                    ones++;
                    break;
                case 2:
                    twos++;
                    break;
            }
        }
        while(zero--)
        {
            cout<<"0 ";
        }
        while(ones--)
        {
            cout<<"1 ";
        }
        while(twos--)
        {
            cout<<"2 ";
        }
        cout<<endl;
    }
    return 0;
}