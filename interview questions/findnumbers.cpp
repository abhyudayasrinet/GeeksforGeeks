//https://practice.geeksforgeeks.org/problems/finding-the-numbers/0

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        map <int,int> m;
        for(int i=0;i<2*n+2;i++)
        {
            cin>>x;
            if(m.find(x) != m.end())
            {
                m.erase(x);
            }
            else
            {
                m[x] = 1;
            }
        }
        map<int,int>::iterator itr = m.begin();
        while(itr!=m.end())
        {
            cout<<itr->first<<" ";
            itr++;
        }
        cout<<endl;
    }
    return 0;
}