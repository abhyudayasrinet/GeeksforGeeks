//https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarysearch(int x, vector <int> a)
{
    int low = 0;
    int high = a.size() - 1;
    int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(a[mid] == x)
            return true;
        else if(a[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        vector <int> a;
        vector <int> sq;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
            sq.push_back(x*x);
        }
        // sort(a.begin(), a.end());
        sort(sq.begin(), sq.end());
        int flag = 0;
        for(int i=a.size()-1;i>=2;i--)
        {
            int low = 0;
            int high = i-1;
            while(low<high)
            {
                if(sq[low] + sq[high] == sq[i])
                {
                    flag = 1;
                    break;
                }
                else if(sq[low] + sq[high] > sq[i])
                    high--;
                else
                    low++;
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}