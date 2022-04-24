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
Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (root->data < x)
    {
        root->right = insert(root->right, x);
    }
    else if(root->data>x)
    {
        root->left=insert(root->left,x);
    }
    return root;      
}
int main()
{
    struct Node *root = new Node(11);
    
    root=insert(root,8);
    root=insert(root,15);
    root=insert(root,7);
    root=insert(root,9);
    root=insert(root,20);
    InorderTraversal(root);

    return 0;
}