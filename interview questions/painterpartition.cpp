//https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0#ExpectOP

#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <utility>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

map <pair<int, int>, int> m;

int partition(vector <int> &v, int i, int k)
{
    if(m.find(make_pair(i,k)) != m.end())
        return m[make_pair(i,k)];
        
    if(i == v.size())
        return 0;

    if(k == 0)
    {
        int sum = 0;
        for(;i<v.size();i++)
        {
            sum += v[i];
        }
        return sum;
    }

    
    int current_sum = v[i], max_ = v[i], ans = INT_MAX;
    for(int j=i+1;j<v.size();j++)
    {
        int val = partition(v, j, k-1);
        // cout<<k<<" "<<j<<" "<<val<<endl;
        
        max_ = max(max_, val);
        ans = min(ans, max_);
        // cout<<max_<<" "<<ans<<endl;
        current_sum += v[j];
        max_ = current_sum;
    }
    ans = min(ans, max_);
    m[make_pair(i,k)] = ans;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        int k,n;
        cin>>k>>n;
        vector <int> v(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        cout<<partition(v, 0, k-1)<<endl;
    }
    return 0;
}