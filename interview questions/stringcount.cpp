//https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0


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
        int a = 1;
        int a1b = n;
        int a1b1c = n*(n-1);
        int a1b2c = (n*(n-1)*(n-2))/2;
        int a1c = n;
        int a2c = (n*(n-1))/2;
        cout<<a+a1b+a1b1c+a1b2c+a1c+a2c<<endl;
    }
    return 0;
}