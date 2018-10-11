//https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        map <char,int> m;
        int c = 0, max_c = 0,start_i = 0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i]) == m.end())
            {
                c++;
            }
            else
            {
                if(m[s[i]] >= start_i)
                {
                    start_i = m[s[i]]+1;
                    c = i - start_i + 1;
                }
                else
                {
                    c++;
                }
            }
            if(c > max_c)
                max_c = c;
            m[s[i]] = i;
        }
        cout<<max_c<<endl;
    }
    return 0;
}