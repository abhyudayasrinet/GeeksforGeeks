//https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array/0

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>m>>n>>k;
        vector <int> a(m,0);
        for(int i=0;i<m;i++)
            cin>>a[i];
        vector <int> b(n,0);
        for(int j=0;j<n;j++)
            cin>>b[j];

        int i=0,j=0,c=0,curr;
        while(c!=k && i<m && j<n)
        {
            // cout<<a[i]<<" "<<b[j]<<endl;
            if(a[i] < b[j])
            {
                curr = a[i];
                i++;
            }
            else
            {
                curr = b[j];
                j++;
            }
            // cout<<curr<<endl;
            c++;
        }
        while(c!=k && i<m)
        {
            curr = a[i];
            c++;
            i++;
        }
        while(c!=k && j<n)
        {
            curr = b[j];
            c++;
            j++;
        }
        cout<<curr<<endl;
    }
    return 0;
}