//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the grap
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int g[MAX][MAX];
void dijkstra(int graph[MAX][MAX], int ,int V);
int main()
{
   /* Let us create the example graph discussed above */
   int t;
int V;
   cin>>t;
   while(t--){
cin>>V;
  for(int i=0;i<V;i++)
  {
  	for(int j=0;j<V;j++)
  	{
  		cin>>g[i][j];
  	}
  }
  int s;
  cin>>s;
    dijkstra(g, s,V);
cout<<endl;
   }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */

vector <int> dist;
struct comp
{
    bool operator()(const int &lhs, const int &rhs)
    {
        return dist[lhs] > dist[rhs];
    }
};
void dijkstra(int graph[MAX][MAX], int s,int V)
{
    vector <int> vis(V, false);
    dist = vector <int> (V, INT_MAX);
    priority_queue<int, vector<int>, comp> pq;
    dist[s] = graph[s][s];
    pq.push(s);
    int vis_count = 0;
    while(vis_count != V && !pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        if(vis[curr])
            continue;
        vis[curr] = true;
        vis_count++;
        for(int i=0;i<V;i++)
        {
            if(!vis[i] && dist[curr] + graph[curr][i] < dist[i])
            {
                dist[i] = dist[curr] + graph[curr][i];
                pq.push(i);
            }
        }
    }
    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
}