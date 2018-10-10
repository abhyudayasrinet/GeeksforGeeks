//https://practice.geeksforgeeks.org/problems/geek-collects-the-balls/0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int max(long long int a, long long int b)
{
    if(a>b)
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
        // if(n1 == 0)
            // break;
        vector <long long int> a(n1);
        vector <long long int> sum_a(n1);
        for(int i=0;i<n1;i++)
        {
            cin>>a[i];
        }
        // cout<<"X"<<endl;
        // cin>>n2;
        vector <long long int> b(n2);
        vector <long long int> sum_b(n2);
        for(int i=0;i<n2;i++)
        {
            cin>>b[i];
        }
        int n = n1 < n2 ? n1 : n2;
        sum_a[0] = a[0];
        sum_b[0] = b[0];
        int i=1,j=1;
        for(;i<n1 && j<n2;)
        {
            if(a[i] < b[j])
            {
                // cout<<i<<" "<<a[i]<<" "<<j-1<<" "<<b[j-1]<<endl;
                sum_a[i] = sum_a[i-1] + a[i];
                if(a[i] == b[j-1])
                {
                    // cout<<"4"<<endl;
                    sum_b[j-1] = max(sum_b[j-1], sum_a[i]);
                }
                i++;
            }
            else if(a[i] > b[j])
            {
                // cout<<"2"<<endl;
                sum_b[j] = sum_b[j-1] + b[j];
                
                if(b[j] == a[i-1])
                {
                    sum_a[i-1] = max(sum_a[i-1], sum_b[j]);
                }
                j++;
            }
            else
            {
                // cout<<"3"<<endl;
                sum_a[i] = max(sum_a[i-1], sum_b[j-1]) + a[i];
                sum_b[j] = max(sum_a[i-1], sum_b[j-1]) + b[j];
                i++;
                j++;
            }
        }
        // for(int x = 0;x<n;x++)
        //     cout<<sum_a[x]<<" ";
        // cout<<endl;
        // for(int x = 0;x<n;x++)
        //     cout<<sum_b[x]<<" ";
        // cout<<endl;
        // int j=i;
        while(i < n1) {
            sum_a[i] = sum_a[i-1] + a[i];
            i++;
        }
        // j=i;
        while(j < n2) {
            sum_b[j] = sum_b[j-1] + b[j];
            j++;
        }
        cout<<max(sum_a[n1-1], sum_b[n2-1])<<endl;
    }
    return 0;
}