//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

#include <iostream>
#include <climits>
#include <map>
#include <vector>
using namespace std;
int MAX = 100000;
int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

map <int,int> m;
int dfs(int i, vector <int> a)
{
    if(m.find(i) != m.end())
        return m[i];
    if(i >= a.size())
        return MAX;
    // cout<<i<<endl;
    if(i == a.size()-1) {
        // cout<<"jumps:"<<c<<endl;
        return 0;
    }
    
    int jumps = MAX;
    for(int j=1;j<=a[i];j++)
    {
        if(i+j < a.size()) {
            // cout<<"from "<<i<<" to "<<i+j<<endl;
            // if(val != INT_MAX)
            jumps = min(jumps, dfs(i+j, a) + 1);
            // cout<<"from "<<i<<" to "<<i+j<<" "<<jumps<<endl;
        }
    }
    m[i] = jumps;
    return jumps;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        int n;
        cin>>n;
        vector <int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int c,min_ = MAX;
        for(int i=1;i<=a[0];i++)
        {
            // cout<<"start:"<<i<<endl;
            c = dfs(0+i,a)+1;
            if(c < min_)
                min_ = c;
        }
        if(min_ == MAX)
            cout<<-1<<endl;
        else
            cout<<min_<<endl;
    }
    return 0;
}