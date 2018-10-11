//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

// bool m[10000][10000];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        int i,j;
        int start=0, end=0;
        for(int k=0;k<n;k++)
        {
            // cout<<"k:"<<k<<endl;
            //odd centered at k
            i = k-1;
            j = k+1;
            while(i>=0 && j<n && s[i]==s[j])
            {
                if(j-i+1 > end - start + 1)
                {
                    // cout<<start<<" "<<end<<endl;
                    start = i;
                    end = j;
                }
                i--;
                j++;
            }
            //even centered at k-1,k
            i = k-1;
            j = k;
            while(i>=0 && j<n && s[i] == s[j])
            {
                if(j-i+1 > end - start + 1)
                {
                    // cout<<start<<" "<<end<<endl;
                    start = i;
                    end = j;
                }
                i--;
                j++;
            }
        }

        for(int i=start;i<=end;i++)
            cout<<s[i];
        cout<<endl;
    }
    return 0;
}

// space O(n^2) solution
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         string s;
//         cin>>s;
//         int n = s.size();
//         int start_i = 0, end_j=0;
//         vector <vector<bool>> m(n, vector <bool> (n));
//         for(int i=0;i<n;i++)
//             m[i][i] = true;
//         for(int i=n;i>=1;i--) {
//             m[i-1][i] = s[i] == s[i-1];
//             if(m[i-1][i])
//             {
//                 start_i = i-1;
//                 end_j = i;
//             }
//         }

//         for(int k=2;k<n;k++)
//         {
//             for(int j=k,i=0;j<n && i<n;j++,i++)
//             {
//                 m[i][j] = s[i] == s[j] && m[i+1][j-1];
//                 if(m[i][j] && j-i+1 > end_j-start_i +1)
//                 {
//                     start_i = i;
//                     end_j = j;
//                 }
//             }
//         }
//         // for(int i=0;i<n;i++)
//         // {
//         //     for(int j=0;j<n;j++)
//         //     {
//         //         cout<<m[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         for(int i=start_i;i<=end_j;i++)
//             cout<<s[i];
//         cout<<endl;
//     }
//     return 0;
// }