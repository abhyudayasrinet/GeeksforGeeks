//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char x;
        queue <char> q;
        map<char,int> cnt;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(cnt.find(x) == cnt.end())
            {
                q.push(x);
                cnt[x] = 1;
            }
            else
            {
                cnt[x]++;
            }
            while(!q.empty() && cnt[q.front()] > 1)
                q.pop();
            if(q.empty())
                cout<<-1<<" ";
            else
                cout<<q.front()<<" ";
        }
        cout<<endl;
    }
    return 0;
}