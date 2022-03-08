#include<bits/stdc++.h>
using namespace std;
struct Node{
    struct Node* left;
    struct Node* right;
    int data;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
};
void InorderTraversal(struct Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    InorderTraversal(root->left);
    cout<<root->data<<"->";
    InorderTraversal(root->right);
}
void PrintDis(Node *root,int k)
{
    if(root==NULL)
    {
        return ;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return ;
    }
    else{
        PrintDis(root->left,k-1);
        PrintDis(root->right,k-1);
    }
    // return ;
}

int main()
{
   struct Node* root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(5);   
   root->right->right=new Node(8);   
   root->left->right=new Node(20);   
   root->right->left=new Node(98);
   root->left->left=new Node(78);
//    InorderTraversal(root);
int k;
cin>>k;
  PrintDis(root,k);
    return 0 ;
}