//https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
        int flag=0;
        sort(a.begin(), a.end());
        string s;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int l = j+1;
                int r = n-1;
                while(l<r)
                {
                    if(a[i] + a[j] + a[l] + a[r] == k)
                    {
                        string t = to_string(a[i]) + " " + to_string(a[j]) + " " + to_string(a[l]) + " " + to_string(a[r]) + " $";
                        if(s.find(t) == string::npos)
                            s = s+t;
                        l++;
                        r--;
                        flag = 1;
                    }
                    else if(a[i] + a[j] + a[l] + a[r] < k)
                        l++;
                    else
                        r--;
                }
            }
        }
        if(!flag)
            cout<<-1;
        else
            cout<<s;
        cout<<endl;
    }
}

