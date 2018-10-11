//https://practice.geeksforgeeks.org/problems/implement-atoi/1

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int atoi(string s)
{
    int num=0,flag = 0, start = 0;
    if(s[start] == '-')
        start = 1;
    for(int i=start;i<s.size();i++)
    {
        if(!isdigit(s[i]))
        {
            flag = 1;
            break;
        }
        num = num*10 + (s[i]-'0');
    }
    if(flag)
        return -1;
    else
    {
        if(s[0] == '-')
            return -num;
        return num;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<atoi(s)<<endl;
    }
    return 0;
}