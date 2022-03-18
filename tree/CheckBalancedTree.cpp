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
int BalancedTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = BalancedTree(root->left);
    if (lh == -1)
    {
        return -1;
    }
    int rh = BalancedTree(root->right);
    if (rh == -1)
    {
        return -1;
    }
    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    else
    {
        return max(lh, rh) + 1;
    }
    return 0;
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
    if (BalancedTree(root) == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}