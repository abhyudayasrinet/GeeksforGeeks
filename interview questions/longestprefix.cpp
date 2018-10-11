//https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0

#include <iostream>
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
        vector <string> s;
        string x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            s.push_back(x);
        }

        int flag = 0,i;
        for(i=0;i<s[0].size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i >= s[0].size())
                {
                    flag = 1;
                    break;
                }
                if(s[0][i] != s[j][i])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
        {
            if(i==0)
                cout<<-1<<endl;
            else
                cout<<s[0].substr(0,i)<<endl;
        }
        else
            cout<<s[0]<<endl;
    }
    return 0;
}