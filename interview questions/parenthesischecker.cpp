//https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

#include <iostream>
#include <string>
#include <stack>
using namespace std;
//“{“,”}”,”(“,”)”,”[“,”]”
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        stack <char> st;
        int flag = 0;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch == '[' || ch == '(' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty()) 
                {
                    if(ch == ')')
                    {
                        if(st.top() == '(')
                            st.pop();
                        else
                            flag = 1;
                    }
                    else if(ch == ']')
                    {
                        if(st.top() == '[')
                            st.pop();
                        else
                            flag = 1;
                    }
                    else
                    {
                        if(st.top() == '{')
                            st.pop();
                        else
                            flag = 1;
                    }
                }
                else
                    flag = 1;
            }
            if(flag)
                break;
        }
        if(flag || !st.empty())
            cout<<"not balanced"<<endl;
        else
            cout<<"balanced"<<endl;
    }
    return 0;
}