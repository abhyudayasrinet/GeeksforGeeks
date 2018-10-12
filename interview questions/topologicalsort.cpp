//https://practice.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10001];
int * topoSort(vector<int> graph[],int N);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(graph,0,sizeof graph);
        int N,E;
        cin>>E>>N;
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }
        int *res = topoSort(graph,N);
        bool valid =true;
        for(int i=0;i<N;i++)
        {
            int n=graph[res[i]].size();
            for(int j=0;j<graph[res[i]].size();j++)
            {
                for(int k=i+1;k<N;k++)
                {
                    if(res[k]==graph[res[i] ] [j] )
                        n--;
                }
            }
            if(n!=0)
            {
                valid =false;
                break;
            }
        }
        if(valid==false)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You need to complete this function */

int * topoSort(vector<int> graph[], int N)
{
    int *a = new int[N];
    queue<int> q;
    vector <list <int>> inv_adj(N,list <int> ());
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            inv_adj[graph[i][j]].push_back(i);
        }
    }
    vector <bool> vis(N, false);
    for(int i=0;i<N;i++)
    {
        // cout<<i<<endl;
        // list<int>::iterator itr = inv_adj[i].begin();
        // while(itr!=inv_adj[i].end())
        // {
        //     cout<<*itr<<" ";
        //     itr++;
        // }
        // cout<<endl;
        if(inv_adj[i].empty()) {
            q.push(i);
            vis[i] = true;
        }
    }

    int index = 0;
    while(!q.empty())
    {
        int curr = q.front();
        // cout<<curr<<endl;
        q.pop();
        vis[curr] = true;
        a[index] = curr; //print node
        index++;
        //remove outgoing edges
        for(int i=0;i<graph[curr].size();i++)
        {
            int f = graph[curr][i];
            list<int>::iterator itr = inv_adj[f].begin();
            while(*itr!=curr && itr!=inv_adj[f].end())
            {
                itr++;
            }
            if(itr != inv_adj[f].end())
                inv_adj[f].erase(itr);   
        }
        //add new no incoming edge nodes to queue
        for(int i=0;i<N;i++)
        {
            if(inv_adj[i].empty() && !vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    // for(int i=0;i<index;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    return a;
}