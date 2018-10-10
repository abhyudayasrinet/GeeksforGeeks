//https://practice.geeksforgeeks.org/problems/minimize-the-heights/0

#include <iostream>
#include <climits>
using namespace std;


int a[10000];

int swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        int min_= INT_MAX, max_=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] > max_)
                max_ = a[i];
            if(a[i] < min_)
                min_ = a[i];
        }
        if(max_ - min_ >= k)
        {
            max_ = max_ - k; 
            min_ = min_ + k;
            if(max_ < min_)
                swap(max_, min_);

            for(int i=0;i<n;i++)
            {
                if(a[i] + k <= max_ || a[i] - k >= min_)
                    continue;
                int inc_diff = a[i] + k - max_;
                int dec_diff = min_ - (a[i] - k);
                if(inc_diff > dec_diff)
                {
                    min_ = a[i] - k;
                }
                else
                {
                    max_ = a[i] + k;
                }
            }
        }
        cout<<(max_ - min_)<<endl;
    }
    return 0;
}