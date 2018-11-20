//https://practice.geeksforgeeks.org/problems/word-boggle/0
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;


bool dfs_search(int i, int j, string& word, int index, vector<vector<char>>& board, vector <vector <bool>> &mark)
{
    if(index == word.size())
        return true;
    
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return false;
    if(mark[i][j])
        return false;
    
    mark[i][j] = true;
    bool result = false;
    if(board[i][j] == word[index])
    {
        result |= dfs_search(i+1, j, word, index+1, board, mark);
        result |= dfs_search(i, j+1, word, index+1, board, mark);
        result |= dfs_search(i-1, j, word, index+1, board, mark);
        result |= dfs_search(i, j-1, word, index+1, board, mark);

        result |= dfs_search(i-1, j-1, word, index+1, board, mark);
        result |= dfs_search(i+1, j+1, word, index+1, board, mark);
        result |= dfs_search(i+1, j-1, word, index+1, board, mark);
        result |= dfs_search(i-1, j+1, word, index+1, board, mark);
    }
    mark[i][j] = false;
    return result;
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    set <string> ans;
    vector <vector <bool>> mark(board.size(), vector <bool> (board[0].size(), false));
    for(int k=0;k<words.size();k++)
    {
        int flag = 0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(words[k].size() > 0) 
                {
                    if(board[i][j] == words[k][0] && dfs_search(i, j, words[k], 0, board, mark)) 
                    {
                        ans.insert(words[k]);
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    ans.insert(words[k]);
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
    }
    return vector <string> (ans.begin(), ans.end());
}


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <string> words;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            words.push_back(s);
        }
        int m;
        cin>>m>>n;
        vector <vector<char>> board(m, vector <char> (n, 'a'));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>board[i][j];
            }
        }
        vector <string> ans = findWords(board, words);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        if(ans.size() == 0)
            cout<<-1;
        cout<<endl;
    }
	return 0;
}