//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n,0);
        vector <int> m(n+1,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        int ans1,ans2;
        for(int i=1;i<=n;i++)
        {
            if(m[i] == 2)
                ans1 = i;
            if(m[i] == 0)
                ans2 = i;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
	return 0;
}