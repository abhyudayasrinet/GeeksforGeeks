//https://practice.geeksforgeeks.org/problems/rotten-oranges/0
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;


int a[100][100];
int v[100][100];
int d[100][100];
struct node {
    int i;
    int j;
    int d;
    node(int r, int c, int dst)
    {
        i = r;
        j = c;
        d = dst;
    }
};
queue<node*> q; 
int r,c;

void bfs(int start_i, int start_j)
{
    // q.push(new node(start_i,start_j,0));
    q.push(new node(start_i+1,start_j,1));
    q.push(new node(start_i,start_j+1,1));
    q.push(new node(start_i-1,start_j,1));
    q.push(new node(start_i,start_j-1,1));

    int i,j,dst;
    while(!q.empty())
    {
        node *top = q.front();
        q.pop();
        i = top->i;
        j = top->j;
        dst = top->d;
        // cout<<i<<" "<<j<<endl;
        if(i == -1 || j == -1 || i == r || j == c)
            continue;
        if(a[i][j] == 0 || a[i][j] == 2)
            continue;
        if(v[i][j] && d[i][j] <= dst)
            continue;
        v[i][j] = 1;
        d[i][j] = dst;
        // cout<<dst<<endl;
        q.push(new node(i+1,j,dst+1));
        q.push(new node(i,j+1,dst+1));
        q.push(new node(i-1,j,dst+1));
        q.push(new node(i,j-1,dst+1));
    }
       
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        memset(a, 0, sizeof(a[0][0])*100*100);
        memset(v, 0, sizeof(v[0][0])*100*100);
        memset(d, 0, sizeof(d[0][0])*100*100);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(a[i][j] == 2)
                {
                    bfs(i,j);    
                }
            }
        }
        int ans = -1,flag = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(!v[i][j] && a[i][j] == 1) 
                {
                    ans = -1;
                    flag = 1;
                    break;
                }
                    
                if(v[i][j])
                {
                    if(d[i][j] > ans)
                        ans = d[i][j];
                }
            }
            if(flag)
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}