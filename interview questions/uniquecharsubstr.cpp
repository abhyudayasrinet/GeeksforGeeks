//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int k;
        cin>>k;
        
        map <char, int> m;
        for(char ch='a';ch<='z';ch++)
            m[ch] = 0;
        
        int unique = 0, i = 0, lo = 0;
        while(i < s.size() && unique < k)
        {
            if(m[s[i]] == 0)
                unique++;
            m[s[i]]++;
            // cout<<i<<" "<<m[s[i]]<<" "<<s[i]<<endl;
            i++;
        }
        if(unique != k)
        {
            cout<<-1<<endl;
            continue;
        }
        int max_ = i;
        for(;i<s.size();i++)
        {
            if(m[s[i]] == 0)
                unique++;
            m[s[i]]++;
            while(unique > k && lo <= i)
            {
                m[s[lo]]--;
                if(m[s[lo]] == 0)
                    unique--;
                lo++;
            }
            // cout<<i<<" "<<m[s[i]]<<" "<<s[i]<<" "<<unique<<" "<<lo<<endl;
            if(i - lo + 1 > max_)
                max_ = i - lo + 1;
        }
        cout<<max_<<endl;
    }
    return 0;
}