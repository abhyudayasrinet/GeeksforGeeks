//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int maxPathSum(struct Node *root);
void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return ;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
					break;
			case 'R':root->right=newNode(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right)
;}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
							break;
					case 'R':root->right=newNode(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		//inorder(root);
		//cout<<endl;
		cout<<maxPathSum(root)<<endl;		
	}
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int helper(Node *root, int &maxval)
{
    if(root->left == NULL && root->right == NULL)
        return root->data;
    
    int left_val=NULL, right_val=NULL;
    if(root->left != NULL)
        left_val = helper(root->left);
    if(root->right != NULL)
        right_val = helper(root->right);
    
    if(left_val != NULL && right_val != NULL)
    {
        if(maxval < left_val + right_val + root->data)
        {
            maxval = left_val + right_val + root->data;
        }
    }
    if(left_val == NULL)
        return root->data + right_val;
    if(right_val == NULL)
        return root->data + left_val;
    return max(root->data + left_val, root->data + right_val);
}

int maxPathSum(struct Node *root)
{
    int maxval = INT_MIN;
    helper(root, &maxval);
    return maxval;
}