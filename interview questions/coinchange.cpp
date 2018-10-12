//https://practice.geeksforgeeks.org/problems/coin-change/0

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int count_ = 0;
map <pair<int,int>, int> mp;
int count_change(int n, int m, vector <int> a)
{
    if(mp.find(make_pair(m,n)) != mp.end())
        return mp[make_pair(m,n)];
    if(n<0 || m<0)
        return 0;
    if(m == 0)
        return 1;
    
    mp[make_pair(m,n)] = count_change(n-1, m, a) + count_change(n, m-a[n], a);
    return mp[make_pair(m,n)];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        int n,m;
        cin>>n;
        vector <int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>m;

        int total = count_change(n-1, m, a);
        cout<<total<<endl;
    }
    return 0;
}