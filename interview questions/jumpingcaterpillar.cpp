//https://practice.geeksforgeeks.org/problems/jumping-caterpillars/0

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        // vector <int> a(k);
        // vector <bool> leaf(n, false);
        int leaf[n] = {0};
        int a[k];
        for(int i=0;i<k;i++)
            cin>>a[i];
        int c = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(i%a[j]==0) {
                    leaf[i] = 1;
                    break;
                }
            }
            if(!leaf[i])
                c++;
        }
        cout<<c<<endl;   
    }
}