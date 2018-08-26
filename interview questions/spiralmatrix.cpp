//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0

#include <iostream>
#include <cstdio>
using namespace std;

int a[100][100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        int top_right_i = 0;
        int top_right_j = n-1;
        int bot_right_i = m-1;
        int bot_right_j = n-1;
        int bot_left_i = m-1;
        int bot_left_j = 0;
        int top_left_i = 1;
        int top_left_j = 0;
        int direction = 0;
        int count = 0;
        int i=0,j=0;
        while(count<m*n)
        {
            // cout<<"current:"<<i<<","<<j<<endl;
            // cout<<"topright:"<<top_right_i<<","<<top_right_j<<endl;
            cout<<a[i][j]<<" ";
            count++;
            if(i == top_right_i && j == top_right_j && direction == 0)
            {
                direction = 1;
                top_right_i++;
                top_right_j--;
                // cout<<"top right"<<endl;
                // cout<<top_right_i<<","<<top_right_j<<endl;
            }
            else if(i == bot_right_i && j == bot_right_j && direction == 1)
            {
                direction = 2;
                bot_right_i--;
                bot_right_j--;
            }
            else if(i == bot_left_i && j == bot_left_j && direction == 2)
            {
                direction = 3;
                bot_left_i--;
                bot_left_j++;
            }
            else if(i == top_left_i && j == top_left_j && direction == 3)
            {
                direction = 0;
                top_left_i++;
                top_left_j++;
            }
            if(direction == 0)
                j++;
            else if(direction == 1)
                i++;
            else if(direction == 2)
                j--;
            else
                i--;
        }
        cout<<endl;
    }
    return 0;
}