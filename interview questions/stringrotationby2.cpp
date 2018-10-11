//https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        string s = a+a;
        // cout<<s.substr(2, a.size())<<endl;
        // cout<<s.substr(a.size()-2, a.size()) <<endl;
        if(s.substr(2, a.size()) == b || s.substr(a.size()-2, a.size()) == b)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}