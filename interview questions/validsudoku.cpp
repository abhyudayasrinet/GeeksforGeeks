//https://practice.geeksforgeeks.org/problems/is-sudoku-valid/0

#include <iostream>
using namespace std;

bool isValid(int grid[9][9], int curr_i, int curr_j, int val)
{
    for(int i=0; i<9;i++)
    {
        if(i != curr_i && val == grid[i][curr_j])
            return false;
    }

    for(int j=0;j<9;j++)
    {
        if(j != curr_j && val == grid[curr_i][j])
            return false;
    }
    int start_i, start_j;
    if(curr_i >= 0 && curr_i < 3)
        start_i = 0;
    else if(curr_i >= 3 && curr_i < 6)
        start_i = 3;
    else if(curr_i >= 6 && curr_i < 9)
        start_i = 6;
    
    if(curr_j >= 0 && curr_j < 3)
        start_j = 0;
    else if(curr_j >= 3 && curr_j < 6)
        start_j = 3;
    else if(curr_j >= 6 && curr_j < 9)
        start_j = 6;
    
    for(int i=start_i;i<start_i+3;i++)
    {
        for(int j=start_j;j<start_j+3;j++)
        {
            if(i != curr_i && j != curr_j && val == grid[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int grid[9][9])
{
    int curr_i = -1, curr_j = -1;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid[i][j] == 0)
            {
                curr_i = i;
                curr_j = j;
                break;
            }
        }
        if(curr_i != -1)
            break;
    }
    if(curr_i == -1 && curr_j == -1)
        return true;

    for(int i=1;i<=9;i++)
    {
        grid[curr_i][curr_j] = i;
        if(isValid(grid, curr_i, curr_j, i))
        {
            if(solve(grid))
                return true;
        }
        grid[curr_i][curr_j] = 0;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int grid[9][9] = {0};
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<solve(grid)<<endl;
    }
    return 0;
}