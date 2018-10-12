//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000  
int findIslands(int A[MAX][MAX],int N,int M);
int A[MAX][MAX];
int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(A,0,sizeof A);
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		cin>>A[i][j];
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete this method*/

void dfs(int i, int j, int A[MAX][MAX], vector <vector<bool>> &vis, int c, int N, int M)
{
    if(i>=N || j>=M || i<0 || j<0)
        return;
    if(A[i][j] == 0)
        return;
    if(vis[i][j])
        return;
    
    vis[i][j] = true;

    dfs(i-1,j-1,A,vis,c,N,M);
    dfs(i-1,j,A,vis,c,N,M);
    dfs(i-1,j+1,A,vis,c,N,M);
    dfs(i,j+1,A,vis,c,N,M);
    dfs(i+1,j+1,A,vis,c,N,M);
    dfs(i+1,j,A,vis,c,N,M);
    dfs(i+1,j-1,A,vis,c,N,M);
    dfs(i,j-1,A,vis,c,N,M);
}

int findIslands(int A[MAX][MAX], int N, int M)
{
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=0;j<M;j++)
    //     {
    //         cout<<A[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector <vector <bool>> vis(N, vector <bool> (M, false));

    int c = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j] == 1 && !vis[i][j]) {
                dfs(i,j, A, vis, c, N, M);
                c++;
            }
        }
    }
    
    return c;
}