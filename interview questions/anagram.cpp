//https://practice.geeksforgeeks.org/problems/anagram/0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        vector <int> m_a(26,0);
        vector <int> m_b(26,0);
        for(int i=0;i<a.size();i++)
        {
            m_a[a[i]-'a']++;
        }
        for(int i=0;i<b.size();i++)
        {
            m_b[b[i]-'a']++;
        }
        int flag =0;
        for(int i=0;i<=25;i++)
        {
            if(m_a[i] != m_b[i])
            {
                flag = 1;
                break;
            }
        }

        if(!flag)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }
    return 0;
}