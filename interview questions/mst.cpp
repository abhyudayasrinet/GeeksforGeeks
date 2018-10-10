//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int spanningTree(vector <pair<int,int> > g[], int n);
int main()
{
	int t ;
	cin>>t;
	while(t--)
	{
	vector <pair<int,int> > adj[MAX];
    int n,e;
    int w, mC;
    cin >> n>> e;
    for(int i = 0;i < e;++i)
    {
    	int x,y;
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
  
    mC= spanningTree(adj, MAX);
    cout << mC << endl;
	}
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Finds the sum of weights of the edges of the Minimum Spanning Tree.
    Graph is represented as adjacency list using array of vectors.  MAX 
    is an upper  limit on number of vertices.
   g[u] represents adjacency list of vertex u,  Every element of this list 
   is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
  Note : Vertex numbers start with 1 and don't need to be contiguous.   */

vector <pair<int, pair <int,int>>> edges;
int id[MAX];
int root(int i)
{
    while(id[i] != i)
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void union_(int u, int v)
{
    int u_root = root(u);
    int v_root = root(v);
    id[u_root] = id[v_root];
}

int kruskal()
{
    int c =0;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if(root(u) != root(v))
        {
            c += w;
            union_(u,v);
        }
    }
    return c;
}

int spanningTree(vector <pair<int,int> > g[], int MAX)
{
    edges.clear();
	for(int i=0;i<MAX;i++)
    {
        id[i] = i;
        if(g[i].size() > 0)
        {
            for(int j=0;j<g[i].size();j++)
            {
                edges.push_back(make_pair(g[i][j].first, make_pair(i, g[i][j].second)));
            }
        }
    }
    sort(edges.begin(), edges.end());
    // for(int i=0;i<edges.size();i++)
    // {
    //     cout<<edges[i].first<<" "<<edges[i].second.first<<endl;
    // }
    int c = kruskal();
    return c;
}
