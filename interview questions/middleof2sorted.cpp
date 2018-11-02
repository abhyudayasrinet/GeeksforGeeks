//https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0
#include <iostream>
using namespace std;

int a[1000];
int b[1000];
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>b[i];
	    }
	    
	    int i=0,j=0,k=0,nth,nth2;
	    while(i<n && j<n && k<n)
	    {
	        if(a[i] < b[j]) 
            {
                nth = a[i];
                i++;
            }
	        else
            {
                nth = b[j];
                j++;
            }
	        k++;
            // cout<<i<<" "<<j<<" "<<k<<" "<<endl;
	    }
        // cout<<i<<" "<<j<<" "<<k<<" "<<nth<<endl;
        while(i<n && k < n)
        {
            nth = a[i];
            i++;
            k++;
        }
        while(j<n && k < n)
        {
            nth = b[j];
            j++;
            k++;
        }
        if(i<n && j<n)
        {
            if(a[i] < b[j])
                nth2 = a[i];
            else
                nth2 = b[j];   
        }
        else if(i < n)
        {
            nth2 = a[i];
        }
        else if(j < n)
        {
            nth2 = b[j];
        }
        cout<<nth + nth2<<endl;
	}
	return 0;
}   