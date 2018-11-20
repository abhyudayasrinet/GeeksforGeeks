//https://practice.geeksforgeeks.org/problems/remove-b-and-ac-from-a-given-string/0

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[1000];
        // string a;
        // cin>>a;
        scanf("%s",a);
        int n = strlen(a);
        int i=0, j=0;
        while(i<n)
        {
            if(a[i] == 'a' && i < n-1 && a[i+1] == 'c')
            {
                i+=2;
            }
            else if(a[i] == 'b')
            {
                i++;
            }
            else
            {
                a[j] = a[i];
                j++;
                i++;
            }
        }
        a[j] = '\0';
        printf("%s\n", a);
    }
    return 0;
}