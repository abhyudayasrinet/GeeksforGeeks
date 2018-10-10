//https://practice.geeksforgeeks.org/problems/largest-number-possible/0

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        if(s == 0) {
            cout<<-1<<endl;
            continue;
        }
        int digits = 0,d,newnum=0;
        string str = "";
        while(digits < n)
        {
            if(s > 9) {
                s -= 9;
                d = 9;
            }
            else if(s > 0) {
                d = s;
                s -= s;
            }
            else if(s == 0)
                d = 0;
            // cout<<d<<endl;
            digits++;
            str += ('0'+d);
            // newnum = newnum*10 + d;
        }
        if(s > 0)
            cout<<-1<<endl;
        else
            cout<<str<<endl;
    }
    return 0;
}