//https://practice.geeksforgeeks.org/problems/minimum-swaps/1

// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);
// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You are required to complete this method */
int minSwaps(int A[], int N){
    int *b = new int[N];
    for(int i=0;i<N;i++)
        b[i] = A[i];
    sort(b, b+N);
    vector <vector <int>> adj(N, vector <int> ());
    for(int i=0;i<N;i++)
    {
        int lo = 0, hi = N-1, mid;
        while(lo <= hi)
        {
            mid = (lo+hi)/2;
            if(b[mid] == A[i])
                break;
            else if(b[mid] > A[i])
                hi = mid-1;
            else
                lo = mid+1;
        }
        adj[i].push_back(mid);
    }
    vector <bool> vis(N, false);
    int curr, next, c, count=0;
    for(int i=0;i<N;i++)
    {
        curr = i;
        vis[curr] = true;
        next = adj[curr][0];
        c = 1;
        while(!vis[next])
        {
            vis[next] = true;
            next = adj[next][0];
            c++;
        }
        count += (c-1);
    }
    return count;
}
