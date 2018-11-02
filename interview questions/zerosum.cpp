//https://practice.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero/0

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
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
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int min_val = INT_MAX;
        for(int i=0,j=n-1;i<j;)
        {
            min_val = abs(a[i] + a[j]) < abs(min_val) ? a[i] + a[j] : min_val;
            if(a[i] + a[j] > 0)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        cout<<min_val<<endl;
        
    }
    return 0;
}