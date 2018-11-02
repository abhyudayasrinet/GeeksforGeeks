//https://practice.geeksforgeeks.org/problems/maximum-index/0/?ref=self

#include <iostream>
using namespace std;

void merge(int a[], int index[], int low, int mid, int high)
{
    int b[10000];
    int index_b[10000];
    int c[10000];
    int index_c[10000];
    int size_left = mid - low + 1;
    int size_right = high - mid;
    // cout<<"size_left:"<<size_left<<endl;
    // cout<<"size_right:"<<size_right<<endl;
    for(int i = 0, k = low; i < size_left; i++, k++)
    {
        b[i] = a[k];
        index_b[i] = index[k];
    }
    for(int i = 0, k = mid+1; i < size_right; i++, k++)
    {
        c[i] = a[k];
        index_c[i] = index[k];
    }
    int i = 0, j = 0, k = low;
    while(i < size_left && j < size_right)
    {
        // cout<<"i:"<<i<<" j:"<<j<<endl;
        // cout<<b[i]<<" "<<c[j]<<endl;
        if(b[i] <= c[j])
        {
            a[k] = b[i];
            index[k] = index_b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            index[k] = index_c[j];
            j++;
        }
        k++;
    }
    while(i < size_left)
    {
        a[k] = b[i];
        index[k] = index_b[i];
        i++;
        k++;
    }
    while(j < size_right)
    {
        a[k] = c[j];
        index[k] = index_c[j];
        k++;
        j++;
    }
}

void sort(int a[], int index[], int low, int high)
{
    
    if(low < high)
    {
        // cout<<low<<" "<<high<<endl;
        int mid = (low + high) / 2;
        sort(a, index, low, mid);
        sort(a, index, mid + 1, high);
        merge(a, index, low, mid, high);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[10000];
        int index[10000];
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            index[i] = i;
        }

        sort(a, index, 0, n-1);

        // for(int i = 0; i < n; i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<index[i]<<" ";
        // }
        // cout<<endl;


        int max_index[10000];
        max_index[n-1] = index[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(index[i] > max_index[i+1])
                max_index[i] = index[i];
            else
                max_index[i] = max_index[i+1];
        }
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<max_index[i]<<" ";
        // }
        // cout<<endl;

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(max_index[i] - index[i] > ans)
            {
                ans = (max_index[i] - index[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}