//https://practice.geeksforgeeks.org/problems/find-largest-word-in-dictionary/0

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <string> v;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        string x;
        cin>>x;
        string ans = "";
        for(int k=0;k<v.size();k++)
        {
            int m = x.size();
            int n = v[k].size();
            int i = 0, j = 0;
            while(i < m && j < n)
            {
                if(x[i] == v[k][j])
                {
                    i++;
                    j++;
                }
                else
                    i++;
            }
            if(j == n)
            {
                if(v[k].size() > ans.size())
                {
                    ans = v[k];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}