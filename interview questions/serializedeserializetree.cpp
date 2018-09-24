//https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/

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
void serialize(Node *root,vector<int> &);
Node * deSerialize(vector<int> &);
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
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
     int N = n;
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
    vector<int> A;
    A.clear();
    serialize(root,A);
//    for(int i=0;i<A.size();i++)
//        cout<<A[i]<<" ";
//        cout<<endl;
    // inorder(root);
     //cout<<endl;
    Node *tree_made = deSerialize(A);
    inorder(tree_made);
    cout<<endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/

void addInorder(Node *root, vector <int> &A)
{
    if(root == NULL)
        return;
    
    addInorder(root->left, A);
    A.push_back(root->data);
    addInorder(root->right, A);
}

void addPreOrder(Node *root, vector <int> &A)
{
    if(root == NULL)
        return;
    
    A.push_back(root->data);
    addPreOrder(root->left, A);
    addPreOrder(root->right, A);
}

void serialize(Node *root,vector<int> &A)
{
    addInorder(root, A);
    addPreOrder(root, A);
}


Node *getTree(vector <int> orig_inorder, vector <int> preorder, vector <bool> &visited, int &curr)
{
    
    int current_node = preorder[curr];
    curr++;

    Node *newnode = newNode(current_node);

    int j,inorder_root, inorder_left, inorder_right;
    //get root
    for(j=0;j<orig_inorder.size();j++)
        if(orig_inorder[j] == current_node)
            inorder_root = j;

    visited[inorder_root] = true;
    
    //get left
    for(j=inorder_root-1;j>=0;j--)
        if(visited[j])
            break;
    inorder_left = j+1;
    if(inorder_root - inorder_left > 0)
        newnode->left = getTree(orig_inorder, preorder, visited, curr);
    
    //get right
    for(j=inorder_root+1;j<orig_inorder.size();j++)
        if(visited[j])
            break;
    inorder_right = j-1;
    
    if(inorder_right - inorder_root > 0)
        newnode->right = getTree(orig_inorder, preorder, visited, curr);

    return newnode;
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    int number_of_nodes = A.size()/2;
    vector <int> preorder;
    vector <int> inorder;
    vector <bool> visited;
    int i=0,j;
    for(;i<number_of_nodes;i++) {
        inorder.push_back(A[i]);
        visited.push_back(false);
    }
    for(;i<A.size();i++)
        preorder.push_back(A[i]);

    int curr=0;
    return getTree(inorder, preorder, visited, curr);
}