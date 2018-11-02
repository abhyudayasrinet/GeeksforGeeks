//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1


#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
typedef struct Node Node;
struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};
int KthSmallestElement(Node *root, int k);
Node *insert_node(Node *root, Node* node)
{
    Node *pTraverse = root;
    Node *currentParent = root;
 
    while(pTraverse)
    {
        currentParent = pTraverse;
 
        if( node->data < pTraverse->data )
        {
            pTraverse->lCount++;
            pTraverse = pTraverse->left;
        }
        else
        {
            pTraverse = pTraverse->right;
        }
    }
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        currentParent->left = node;
    }
    else
    {
        currentParent->right = node;
    }
 
    return root;
}
Node* binary_search_tree(Node *root, int keys[], int const size)
{
    int iterator;
    Node *new_node = NULL;
 
    for(iterator = 0; iterator < size; iterator++)
    {
        new_node = (Node *)malloc( sizeof(Node) );
 
        /* initialize */
        new_node->data   = keys[iterator];
        new_node->lCount = 0;
        new_node->left   = NULL;
        new_node->right  = NULL;
 
        /* insert into BST */
        root = insert_node(root, new_node);
    }
 
    return root;
}
 
 int main(void)
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
    int ele[n];
	for(int i=0;i<n;i++){
		cin>>ele[i];
	}
    int k;
	cin>>k;
    Node* root = NULL;
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));
        printf("%d",KthSmallestElement(root, k));
	}
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};*/

Node *inorder(Node *root, int &i, int k)
{
    if(root == NULL)
        return root;
    Node *left = inorder(root->left, i, k);
    if(left != NULL)
        return left;
    i++;
    if(i==k)
        return root;
    Node *right = inorder(root->right, i, k);
    if(right != NULL)
        return right;
}

int KthSmallestElement(Node *root, int k)
{
    int i=0;
    Node *node = inorder(root, i, k);
    return node->data;  
}