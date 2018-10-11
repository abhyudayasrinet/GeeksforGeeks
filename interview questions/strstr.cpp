//https://practice.geeksforgeeks.org/problems/implement-strstr/1

#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a;
        cin>>b;
        cout<<strstr(a,b)<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == x[0])
        {
            int j=0,k=i;
            while(j < x.size() && s[k] == x[j])
            {
                k++;
                j++;
            }
            if(j == x.size())
                return i;
        }
    }
    return -1;
}