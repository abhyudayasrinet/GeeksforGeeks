//https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

#include <bits/stdc++.h>
using namespace std;
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};
struct Node* insert(struct Node* root,char data)
{
    if(root==NULL){
    root= new struct Node;
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
    }
    else if(root->data<data)
    root->right=insert(root->right,data);
    else if(root->data>data)
    root->left=insert(root->left,data);
  return root;
}
struct Node* insertString(struct Node* root,string s, int *j)
{
    if((*j)>=s.length())
    return NULL;
	          if(s[*j]=='(')
	          (*j)++;
	         if(s[*j]!='('&&s[*j]!=')'){
	             
	             char n=0;
	             n = s[*j];
             (*j)++;
	          root=insert(root,n);
	          //cout<<"root->data="<<root->data<<endl;
	         // (*j)++;
	          if(s[*j]==')'){
                root->left=NULL;
              root->right=NULL;
              //cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL";
              //cout<<"root->right=NULL";
              return root;
	          }
	         }
             if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
	            //  cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL";
	          root->left=NULL;
	          }
              else{
                //    cout<<"root->left->parent->data="<<root->data<<endl;
	          root->left=insertString(root->left,s,j);
              }
//cout<<"right";
              while(s[*j]==')')
	          (*j)++;
	          if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
      //        cout<<"root->data="<<root->data<<endl;
        //      cout<<"root->right=NULL";
	          root->right=NULL;
	          (*j)++;
	          }
	          else{
          //    cout<<"root->right->parent->data"<<root->data<<endl;
              root->right=insertString(root->right,s,j);
	          }
return root;
}
void print(struct Node* root)
{
    if(root==NULL)
        return;
    print (root->left);
    cout<<root->data<<endl;
    print(root->right);
}
bool dupSub(Node *root);
int main() {
	//code
	int i,j,k,T ,level;
	char s[500];
	   cin>>T;
	   for(i=0;i<T;i++)
	   {
	     // cin>>level;
	      cin>>s;
	      int j=0;
	      struct Node* root=NULL;
	      root=insertString(root,s,&j);
	   
        cout<<dupSub(root)<<endl;
	  
	   }
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/
/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/


//34-35 - 


string preorder;
string inorder;

void preorder(Node *root)
{
    if(root == NULL)
        return NULL;
    preorder += root->data;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if(root == NULL)
        return NULL;
    inorder(root->left);
    inorder += root->data;
    inorder(root->right);
}

bool verify_inorder(string str)
{
    
}

bool dupSub(Node *root)
{
    preorder = "";
    inorder = "";
    preorder(root);
    inorder(root);

    for(int i=0;i<preorder.size();i++)
    {
        for(int j=0;j<preorder.size();j++)
        {
            if(i!=j)
            {
                int x = i, y = j,c=0;
                while(preorder[x] == preorder[y])
                {
                    x++;
                    y++;
                    c++;
                }
                if(c > 2)
                {
                    if(verify_inorder(preorder.substr(i, c)))
                        return 1;
                }
            }
        }
    }
}