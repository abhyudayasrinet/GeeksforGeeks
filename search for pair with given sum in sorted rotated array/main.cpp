#include <cstdio>
#include <iostream>
using namespace std;

//question: https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/

int a[] = {5,6,1,2,3,4};

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
