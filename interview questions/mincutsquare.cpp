//https://practice.geeksforgeeks.org/problems/min-cut-square/0
//constraints too large

#include <iostream>
#include <map>
#include <cstring>
#include <climits>
using namespace std;


int min(int a, int b)
{
    return a < b ? a : b;
}
// map <pair<int,int>, int> m;
int m[10000][10000];
int get(int a, int b)
{
    if(a==b)
        return 1;
    if(m[a][b] != 0)
        return m[a][b];
    // if(m.find(make_pair(a,b)) != m.end())
    //     return m[make_pair(a,b)];
    
    int min_ = INT_MAX;
    for(int i=1;i<=a/2;i++)
    {
        min_ = min(min_, get(a-i, b)+ get(i, b));
    }

    for(int j=1;j<=b/2;j++)
    {
        min_ = min(min_, get(a, b-j) + get(a, j));
    }
    // m[make_pair(a,b)] = min_;
    m[a][b] = min_;
    return min_;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // m.clear();
        memset(m, 0, sizeof(int)*10000*10000);
        int a,b;
        cin>>a>>b;

        cout<<get(a,b)<<endl;
    }
    return 0;
}


