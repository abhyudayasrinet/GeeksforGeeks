//https://practice.geeksforgeeks.org/problems/form-a-palindrome/0

#include <cstdio>
#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <utility>
using namespace std;

int min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

map<pair<int,int>, int> m;

int get_palin(int i, int j, string s)
{
    if(m.find(make_pair(i,j)) != m.end())
    {
        return m[make_pair(i,j)];
    }
    if(i == j)
        return 0;
    if(i > j)
        return INT_MAX;
    if(i == j-1)
        return s[i] == s[j] ? 0 : 1;

    int val1;
    if(s[i] == s[j])
        val1 = get_palin(i+1,j-1,s);
    else
        val1 = min(get_palin(i+1,j,s), get_palin(i,j-1,s))+1;
    m[make_pair(i,j)] = val1;
    return val1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        m.clear();
        int c = 0, min_c = INT_MAX;
        c = get_palin(0,s.size()-1,s);
        cout<<c<<endl;
    }
    return 0;
}