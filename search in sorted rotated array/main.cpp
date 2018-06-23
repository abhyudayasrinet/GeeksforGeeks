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
    cout<<"Enter number to search: ";
    cin>>n;
    int pivot = length-1;
    for(int i=0;i<length-1;i++) 
    {
        if(a[i] > a[i+1]) {
            pivot = i;
            break;
        }
    }

    int left = binary_search(0,pivot,n);
    int right = binary_search(pivot+1, length, n);

    if(left >= 0)
        cout<<"Found at : "<<left+1<<endl;
    else if(right >= 0)
        cout<<"Found at : "<<right+1<<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}
