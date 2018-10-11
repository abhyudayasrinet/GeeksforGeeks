//https://practice.geeksforgeeks.org/problems/longest-common-substring/0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int &a, int &b)
{
    if(a > b)
        return a;
    return b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2;
        cin>>n1>>n2;
        string a,b;
        cin>>a>>b;

        vector <vector <int>> m(n1+1, vector <int> (n2+1,0));
        int max_ = 0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                m[i][j] = (a[i-1] == b[j-1] ? m[i-1][j-1] + 1 : 0);
                max_ = max(m[i][j], max_);
            }
        }

        cout<<max_<<endl;
    }
    return 0;
}

