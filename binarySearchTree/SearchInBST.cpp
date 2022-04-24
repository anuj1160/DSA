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
bool search(Node* root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==x)
    {
        return true;
    }
    else if(root->data<x)
    {
        return search(root->right,x);
    }
    else{
        return search(root->left,x);
    }
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
    // InorderTraversal(root);
    cout<<search(root,25);
    return 0;
}