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
bool ChildrenSum(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->data;
    }
    if (root->right != NULL)
    {
        sum += root->right->data;
    }
    return (root->data == sum && ChildrenSum(root->left) && ChildrenSum(root->right));
}
int main()
{
    struct Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->right = new Node(9);
    // root->left->right = new Node(20);
    root->right->left = new Node(3);
    // root->left->left = new Node(78);
    //    InorderTraversal(root);
    if(ChildrenSum(root))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}