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



void preorder(Node *root,map <char, vector <Node*>> &m)
{
    if(root == NULL)
        return;
    if(m.find(root->data) == m.end())
    {
        m[root->data] = vector <Node*> ();
        m[root->data].push_back(root);
    }
    else
        m[root->data].push_back(root);
    // cout<<root->data<<" ";
    preorder(root->left, m);
    preorder(root->right, m);
}


void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    // cout<<root->data<<" ";
    inorder(root->right);
}

bool duplicate(Node* root1, Node* root2, int &depth)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL && root2 != NULL)
        return false;
    if(root1 != NULL && root2 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    depth++;
    // cout<<root1->data<<" "<<root2->data<<endl;
    return duplicate(root1->left, root2->left, depth) && duplicate(root1->right, root2->right, depth);
}

bool dupSub(Node *root)
{
    map <char, vector <Node*>> m;
    preorder(root, m);

    map <char, vector <Node*>>::iterator itr = m.begin();
    while(itr != m.end())
    {
        // cout<<itr->first<<" "<<itr->second.size()<<endl;
        if(itr->second.size() > 1)
        {
            for(int i=0;i<itr->second.size();i++)
            {
                for(int j=i+1;j<itr->second.size();j++)
                {
                    int depth = 0;
                    bool val = duplicate(itr->second[i], itr->second[j], depth);
                    if(val && depth > 1)
                        return true;
                }
            }
        }
        itr++;
    }
    return false;
}