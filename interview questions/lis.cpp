//https://www.geeksforgeeks.org/?p=12832

#include <cstdio>
#include <iostream>
using namespace std;

int a[1000];
int s[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s[i] = 1;
    }
    int max = s[0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i] > a[j])
                s[i] = s[j] + 1;
        }
        if(s[i] > max)
            max = s[i];
    }
    cout<<max<<endl;
    return 0;    
}