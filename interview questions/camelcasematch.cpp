//https://practice.geeksforgeeks.org/problems/camelcase-pattern-matching/0

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map <string, vector<string>> dict;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            string abrv="";
            for(int j=0;j<s.size();j++)
            {
                if(isupper(s[j]))
                {
                    abrv += s[j];
                }
            }
            // cout<<abrv<<endl;
            // if(dict.find(s) == dict.end())
            // {
            //     dict[s] = vector <string> ();
            //     dict[s].push_back(s);
            // }
            dict[abrv].push_back(s);
        }

        cin>>s;

        map<string, vector<string>>::iterator itr = dict.begin();
        int flag = 0;
        while(itr!=dict.end())
        {
            if(itr->first.find(s) == 0)
            {
                for(int i=0;i<itr->second.size();i++)
                    cout<<itr->second[i]<<" ";
                flag = 1;
                // break;
            }
            itr++;
        }
        if(!flag)
            cout<<"No match found";
        cout<<endl;
    }
    return 0;
}