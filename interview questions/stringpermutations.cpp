//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


vector <string> ans;

void get_(string s, map <char,int> m, int n)
{
    
    if(s.size() == n)
    {
        // cout<<s<<endl;
        ans.push_back(s);
        return;
    }
    map<char,int>::iterator itr = m.begin();
    while(itr!=m.end())
    {
        // cout<<s<<" "<<itr->first<<" - "<<itr->second<<endl;
        for(int i=0;i<itr->second;i++)
        {
            // s = s + itr->first;
            map <char,int> m2 = m;
            m2[itr->first]--;
            get_(s + itr->first, m2, n);
        }
        itr++;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        string s;
        cin>>s;
        map <char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        string str="";
        get_(str,m, s.size());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}