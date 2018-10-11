//https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string ans = "";
        int i=0,flag = 0;
        while(true) 
        {
            flag = 0;
            i=0;
            ans = "";
            while(i<s.size())
            {
                if(s[i] == s[i+1])
                {
                    flag = 1;
                    i++;
                    continue;
                }
                if(i>0 && s[i] == s[i-1])
                {
                    flag = 1;
                    i++;
                    continue;
                }
                ans += s[i];
                i++;
            }
            s = ans;
            if(!flag)
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}