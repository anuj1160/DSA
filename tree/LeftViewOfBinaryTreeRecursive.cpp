#include <bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void InorderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << "->";
    InorderTraversal(root->right);
}
int maxlevel=0;
void LeftView(Node* root,int level)
{
   if(root==NULL)
   {
       return ;
   }
   if(maxlevel<level)
   {
       cout<<root->data<<" ";
       maxlevel=level;
   }
   LeftView(root->left,level+1);
   LeftView(root->right,level+1);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->right->right = new Node(8);
    root->left->right = new Node(20);
    root->right->left = new Node(98);
    root->left->left = new Node(78);
    //    InorderTraversal(root);
    LeftView(root,1);
    return 0;
}