//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0

#include <iostream>
using namespace std;


int a[100][100];
int m,n;

bool valid(int i, int j)
{
    if(i < 0 || j < 0 || i >= m || j >= n)
        return false;
    return true;
}
void flood(int i, int j, int k)
{
    // cout<<i<<" "<<j<<endl;
    int orig = a[i][j];
    a[i][j] = k;
    if(valid(i+1, j) && a[i+1][j] == orig)
        flood(i+1, j, k);
    if(valid(i, j+1) && a[i][j+1] == orig)
        flood(i, j+1, k);
    if(valid(i-1, j) && a[i-1][j] == orig)
        flood(i-1, j, k);
    if(valid(i, j-1) && a[i][j-1] == orig)
        flood(i, j-1, k);

    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        int x,y,k;
        cin>>x>>y>>k;
        flood(x, y, k);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}