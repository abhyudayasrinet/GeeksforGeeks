//https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Function to get diameter of a binary tree */
int diameter(struct Node * tree);
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
     cout << diameter(root) << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int getMaxDepth(Node *root, int &max)
{
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    int left_val = -1, right_val = -1;
    if(root->left != NULL)
        left_val = getMaxDepth(root->left, maxval);
    if(root->right != NULL)
        right_val = getMaxDepth(root->right, maxval);

    if(left_val == -1)
        return right_val + 1;
    if(right_val == -1)
        return left_val + 1;

    if(left_val != -1 && right_val != -1 && maxval < left_val + right_val + 1)
        maxval = left_val + right_val + 1;
    
    return max(left_val, right_val) + 1;
}

int diameter(Node* node)
{
   int maxval = 0;
   getMaxDepth(root, &maxval);
   return maxval;
}