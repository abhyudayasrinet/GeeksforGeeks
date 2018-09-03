//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
Node *newNode(int k)
{
    return new Node(k);
}
// Method that prints the bottom view.
void bottomView(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     bottomView(root);
     cout << endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */
// Method that prints the bottom view.
map <int,int> m_height;
map <int,int> m_val;

void inorder(Node *root, int height, int dist)
{
    if(root == NULL)
        return;
    
    inorder(root->left, height+1, dist-1);
    if(m_height.find(dist) == m_height.end())
    {
        m_height[dist] = height;
        m_val[dist] = root->data;
    }
    else
    {
        if(m_height[dist] <= height)
        {
            m_height[dist] = height;
            m_val[dist] = root->data;
        }
    }
    inorder(root->right, height+1, dist+1);
}

void bottomView(Node *root)
{
    m_height.clear();
    m_val.clear();
    inorder(root,0,0);
    map <int,int>::iterator itr = m_height.begin();
    while(itr != m_height.end())
    {
        cout<<m_val[itr->first]<<" ";
        itr++;
    }
    cout<<endl;
}
