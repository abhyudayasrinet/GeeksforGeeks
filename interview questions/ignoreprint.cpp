//https://practice.geeksforgeeks.org/problems/string-ignorance/0

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin, s);
        vector <int> m(1000, 0);
        for(int i=0;i<s.size();i++)
        {
            // cout<<s[i]<<" "<<m[s[i]]<<endl;
            if(m[tolower(s[i])] == 0)
            {
                cout<<s[i];
                m[tolower(s[i])] = 1;
            }
            else
                m[tolower(s[i])] = 0;
        }
        cout<<endl;
    }
    return 0;
}