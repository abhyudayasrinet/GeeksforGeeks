//https://practice.geeksforgeeks.org/problems/replace-os-with-xs/0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool flood_fill(int i, int j, vector <vector <char>>& a, vector <vector <bool>> &mark, vector <vector <bool>> &visited)
{
    
    if(i < 0 || j < 0 || i >= a.size() || j >= a[0].size())
        return false;
    
    if(visited[i][j])
        return true;

    if(a[i][j] == 'X')
        return true;

    bool val = true;
    visited[i][j] = true;    
    val = val && flood_fill(i+1, j, a, mark, visited);
    val = val && flood_fill(i, j+1, a, mark, visited);
    val = val && flood_fill(i-1, j, a, mark, visited);
    val = val && flood_fill(i, j-1, a, mark, visited);
    return val;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        vector <vector <char>> a(m, vector <char> (n, '.'));
        vector <vector <bool>> mark(m, vector <bool> (n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j] == 'O')
                {
                    vector <vector <bool>> visited(m, vector <bool> (n, false));
                    mark[i][j] = flood_fill(i, j, a, mark, visited);
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mark[i][j] || a[i][j] == 'X')
                    cout<<'X'<<" ";
                else
                    cout<<'O'<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}