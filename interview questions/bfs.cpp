//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include<bits/stdc++.h>
using namespace std;
bool vis[1001];
vector<int> g[1001];
void bfs(int s,vector<int> adj[],bool vis[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(g,0,sizeof g);
        memset(vis,false,sizeof vis);
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        bfs(1,g,vis);
        cout<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You have to complete this function*/
void bfs(int s,vector<int> adj[],bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        cout<<c<<" ";
        for(int i=0;i<adj[c].size();i++)
        {
            if(!vis[adj[c][i]])
            {
                vis[adj[c][i]] = true;
                q.push(adj[c][i]);
            }
        }
    }
}