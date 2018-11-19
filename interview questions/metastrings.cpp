//https://practice.geeksforgeeks.org/problems/meta-strings/0

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
        string a,b;
        cin>>a;
        cin>>b;
        if(a.size() != b.size())
        {
            cout<<0<<endl;
            continue;
        }
        vector <int> a_index;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] != b[i])
            {
                a_index.push_back(i);
            }
        }
        if(a_index.size() != 2)
        {
            cout<<0<<endl;
            continue;
        }
        string c = a;
        char ch = a[a_index[0]];
        a[a_index[0]] = a[a_index[1]];
        a[a_index[1]] = ch;
        if(a == b)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}