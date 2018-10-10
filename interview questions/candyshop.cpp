//https://practice.geeksforgeeks.org/problems/shop-in-candy-store/0

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
        int n,k;
        cin>>n>>k;
        vector <int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a.begin(), a.end());
        int c =0,min_cost =0;
        int i=0;
        while(c<a.size())
        {
            c+=k+1;
            min_cost += a[i];
            i++;
        }
        int max_cost = 0;
        i = a.size()-1,c=0;
        while(c<a.size())
        {
            c+=k+1;
            max_cost += a[i];
            i--;
        }
        cout<<min_cost<<" "<<max_cost<<endl;
    }
    return 0;
}