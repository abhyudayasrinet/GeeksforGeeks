//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1


#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
Node* LCA(Node *root, int , int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        int l,r;
        cin>>l>>r;
        cout<<LCA(root,l,r)->data<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/

Node *LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    
    if(root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if(root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}
Node* LCA(Node *root, int n1, int n2)
{
    vector <Node*> path1;
    vector <Node*> path2;
    Node *current = root;
    path1.push_back(current);
    while(current->data != n1)
    {
        if(n1 < current->data)
            current = current->left;
        else
            current = current->right;
        path1.push_back(current);
    }

    current = root;
    path2.push_back(current);
    while(current->data != n2)
    {
        if(n2 < current->data)
            current = current->left;
        else
            current = current->right;
        path2.push_back(current);
    }

    vector <Node*>::iterator itr1 = path1.begin(), itr2 = path2.begin();
    Node *lca;// = *path1;
    while(itr1 != path1.end() && itr2 != path2.end() && *itr1 == *itr2)
    {
        lca = *itr1;
        itr1++;
        itr2++;
    }
    return lca;
}