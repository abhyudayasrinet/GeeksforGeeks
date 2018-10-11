//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int _size,N;
        cin>>_size>>N;
        Graph *g = new Graph(_size);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        cout<<g->isCyclic()<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};
*/
/*You are required to complete this method*/

bool dfs(int v, vector <bool> vis, list<int> adj[])
{
    // cout<<v<<endl;
    if(vis[v]) {
        // cout<<"cycle"<<endl;
        return true;
    }
        
    vis[v] = true;
    list<int>::iterator itr = adj[v].begin();
    while(itr!=adj[v].end())
    {
        if(dfs(*itr, vis, adj))
            return true;
        itr++;
    }
    return false;
}

bool Graph :: isCyclic()
{
    
    for(int i=0;i<V;i++){
        vector <bool> vis(V, false);
        if(dfs(i,vis,adj))
            return true;
    }
    return false;
}