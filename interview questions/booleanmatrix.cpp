//https://practice.geeksforgeeks.org/problems/boolean-matrix-problem/0

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[1000][1000];
bool row[1000];
bool col[1000];
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
        memset(row, 0, sizeof(bool)*1000);
        memset(col, 0, sizeof(bool)*1000);
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            if(a[i][j])
	            {
	                row[i] = true;
	                col[j] = true;
	            }
	        }
	    }
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(row[i] || col[j])
	                cout<<1<<" ";
	            else
	                cout<<0<<" ";
	        }
	        cout<<endl;
	    }
	    
	}
	return 0;
}