//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0


#include <iostream>
#include <string>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,x;
        cin>>s;
        cin>>x;

        int s_count[256] = {0};
        int x_count[256] = {0};

        for(int i=0;i<x.size();i++)
        {
            x_count[x[i]]++;
        }
        int count = 0, start = 0, start_index = -1, min_ = INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            s_count[s[i]]++;

            if(s_count[s[i]] <= x_count[s[i]] && x_count[s[i]] != 0)
                count++;

            if(count == x.size())
            {
                while(s_count[s[start]] > x_count[s[start]] || x_count[s[start]] == 0)
                {
                    if(s_count[s[start]] > x_count[s[start]])
                        s_count[s[start]]--;
                    start++;
                }

                int window_size = i - start + 1;
                if(window_size < min_)
                {
                    min_ = window_size;
                    start_index = start;
                }
            }
        }
        if(start_index == -1)
            cout<<-1<<endl;
        else
            cout<<s.substr(start_index, min_)<<endl;
    }
    return 0;
}