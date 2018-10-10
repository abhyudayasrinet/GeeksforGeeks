//https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

#include <iostream>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int curr[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int d;
        for(int i=9;i>=0;i--)
        {
            d = n/curr[i];
            if(d > 0)
            {
                for(int j=0;j<d;j++)
                {
                    cout<<curr[i]<<" ";
                }
            }
            n = n%curr[i];
        }
        cout<<endl;
    }
}