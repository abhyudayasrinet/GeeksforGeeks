//https://practice.geeksforgeeks.org/problems/circular-tour/1

#include <iostream>
using namespace std;


int p[1000];
int d[1000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>p[i]>>d[i];
        }

        int current=1,start=0,ans=0;
        int current_petrol = p[start] - d[start];
        while(start != current || current_petrol < 0)
        {
            cout<<start<<" "<<current<<" "<<current_petrol<<endl;
            while(current_petrol < 0 && start != current) //+ p[current] - d[current] >= 0)
            {
                cout<<"remove:"<<start<<endl;
                current_petrol -= (p[start] - d[start]);
                start = (start+1)%n;

                if(start == 0)
                {
                    ans = -1;
                    break;
                }
            }
            if(ans == -1)
                break;

            current_petrol += p[current] - d[current];
            current = (current+1)%n;
        }
        if(ans != -1)
            cout<<start<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}