//https://practice.geeksforgeeks.org/problems/common-elements/0


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector <int> a(n1);
        vector <int> b(n2);
        vector <int> c(n3);
        for(int i=0;i<n1;i++)
            cin>>a[i];
        for(int i=0;i<n2;i++)
            cin>>b[i];
        for(int i=0;i<n3;i++)
            cin>>c[i];
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        map <int,int> ans;
        int flag = 0;
        for(int i=0;i<n1;i++)
        {
            if(binary_search(b.begin(), b.end(), a[i]) && binary_search(c.begin(), c.end(), a[i]))
            {
                ans[a[i]] = 1;
            }
        }
        map <int,int>::iterator itr = ans.begin();
        while(itr!=ans.end())
        {
            cout<<itr->first<<" ";
            itr++;
            flag = 1;
        }
        if(!flag)
            cout<<-1;
        cout<<endl;
    }
    return 0;
}