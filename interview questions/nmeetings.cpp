//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

#include <iostream>
#include <vector>
using namespace std;

int s[1000];
int e[1000];
int m[1000];

void merge(int i, int mid, int j)
{
    // cout<<"merge: "<<i<<" "<<mid<<" "<<j<<endl;
    int left_n = mid-i+1;
    int right_n = j-mid;
    // cout<<"left_n: "<<left_n<<endl;
    // cout<<"right_n: "<<right_n<<endl;
    vector <int> left_s(left_n);
    vector <int> left_e(left_n);
    vector <int> right_s(right_n);
    vector <int> right_e(right_n);
    vector <int> left_m(left_n);
    vector <int> right_m(right_n);
    int tmp_i=0;
    for(int k=i;k<=mid;k++)
    {
        left_s[tmp_i] = s[k];
        left_e[tmp_i] = e[k];
        left_m[tmp_i] = m[k];
        tmp_i++;
    }
    tmp_i=0;
    for(int k=mid+1;k<=j;k++)
    {
        right_s[tmp_i] = s[k];
        right_e[tmp_i] = e[k];
        right_m[tmp_i] = m[k];
        tmp_i++;
    }

    // for(int x=0;x<left_n;x++)
    // {
    //     cout<<left_s[x]<<"-"<<left_e[x]<<endl;
    // }

    // for(int x=0;x<right_n;x++)
    // {
    //     cout<<right_s[x]<<"-"<<right_e[x]<<endl;
    // }

    int k=i,tmp_j=0;
    tmp_i=0;
    while(tmp_i<left_n && tmp_j<right_n)
    {
        // cout<<"tmp: " <<tmp_i<<" "<<tmp_j<<endl;
        if(left_e[tmp_i] < right_e[tmp_j])
        {
            e[k] = left_e[tmp_i];
            s[k] = left_s[tmp_i];
            m[k] = left_m[tmp_i];
            tmp_i++;
        }
        else
        {
            e[k] = right_e[tmp_j];
            s[k] = right_s[tmp_j];
            m[k] = right_m[tmp_j];
            tmp_j++;
        }
        k++;
    }
    while(tmp_i<left_n)
    {
        e[k] = left_e[tmp_i];
        s[k] = left_s[tmp_i];
        m[k] = left_m[tmp_i];
        tmp_i++;
        k++;
    }
    while(tmp_j<right_n)
    {
        e[k] = right_e[tmp_j];
        s[k] = right_s[tmp_j];
        m[k] = right_m[tmp_j];
        tmp_j++;
        k++;
    }
}

void merge_sort(int i, int j)
{
    if(i<j)
    {
        // cout<<i<<" "<<j<<endl;
        merge_sort(i, (i+j)/2);
        merge_sort( ((i+j)/2) + 1, j);
        merge(i, (i+j)/2, j);
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
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            m[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            cin>>e[i];
        }
        merge_sort(0,n-1);
        // for(int i=0;i<n;i++)
        // {
        //     cout<<m[i]<<":"<<s[i]<<"-"<<e[i]<<endl;
        // }

        int end_time = 0,c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] >= end_time)
            {
                end_time = e[i];
                c++;
                cout<<m[i]+1<<" ";
            }
        }
        cout<<endl;
    }
}