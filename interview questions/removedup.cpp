//https://practice.geeksforgeeks.org/problems/remove-duplicates/0

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

char s[1000];
int main()
{
    int t;
    cin>>t;
    cin.get();
    while(t--)
    {
        cin.getline(s, 1000);
        int n = strlen(s);
        int min_char = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(s[i] < min_char)
                min_char = s[i];
        }
        vector <bool> m(256,false);
        string ans = "";
        int index;
        for(int i=0;i<n;i++)
        {
            index = s[i] - min_char;
            if(!m[index])
            {
                ans += s[i];
                m[index] = true;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}