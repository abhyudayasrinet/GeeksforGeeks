#include <cstdio>
#include <iostream>
using namespace std;

int a[] = {5,6,1,2,3,4};

int binary_search(int start, int end, int num)
{
    int mid;
    while(start<=end)
    {
        mid = (start + end) / 2;
        if(a[mid] == num)
        {
            return mid;
        }
        if(a[mid] > num)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return -1;
}

int main()
{
    int length = sizeof(a) / sizeof(int);
    int n;
    cout<<"Enter sum to search: ";
    cin>>n;
    int pivot = length-1;
    for(int i=0;i<length-1;i++) 
    {
        if(a[i] > a[i+1]) {
            pivot = i;
            break;
        }
    }

    int low,high,flag=0;
    if(pivot == length-1)
    {
        low = 0;
        high = length-1;
    }
    else
    {
        low = pivot+1;
        high = pivot;
    }
    while(true) 
    {
        if(a[low] + a[high] == n)
        {
            cout<<"Found pair: "<<a[low]<<","<<a[high]<<endl;
            flag = 1;
            break;
        }
        else if(a[low] + a[high] < n)
        {
            low++;
            if(low == length) 
            {
                low = 0;
            }
        }
        else
        {
            high--;
            if(high == -1)
                high = length-1;
        }
        if(low == high)
            break;
    }
    if(!flag)
        cout<<"Not found"<<endl;
    return 0;
}
