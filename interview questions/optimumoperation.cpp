//https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

#include <iostream>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int c = 0;
        while(n!=0)
        {
            if(n%2)
                n-=1;
            else
                n/=2;
            c++;
        }
        cout<<c<<endl;
    }
    return 0;
}