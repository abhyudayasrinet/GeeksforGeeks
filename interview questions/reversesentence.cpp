//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

#include <iostream>
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
        vector <string> ans;
        int flag = 1;
        while(true)
        {
            int dot = s.find('.');
            if(dot == -1)
            {
                flag = 0;
                dot = s.size();
            }
            string word = s.substr(0,dot);
            ans.push_back(word);
            if(!flag)
                break;
            s = s.substr(dot+1);
        }
        for(int i=ans.size()-1;i>=1;i--)
        {
            cout<<ans[i]<<".";
        }
        cout<<ans[0]<<endl;
    }
    return 0;
}