//https://practice.geeksforgeeks.org/problems/minimize-the-sum-of-product/0

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <long long int> a(n);
        vector <long long int> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long int sum = 0;
        for(int i=0,j=n-1;i<n;i++,j--)
        {
            sum += a[i] * b[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}