//https://practice.geeksforgeeks.org/problems/count-the-triplets/0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        vector <int> m(1000001, 0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]] = 1;
        }
        // sort(a.begin(), a.end());
        int c = 0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(m[a[i]+a[j]])//if(binary_search(a.begin(), a.end(), a[i] + a[j]))
                    c++;
            }
        }
        if(c == 0)
            c = -1;
        cout<<c<<endl;
    }
}