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
    else if (root->data > x)
    {
        root->left = insert(root->left, x);
    }
    return root;
}
Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
        
    }
    return curr;
}
Node *DeltNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data > x)
    {
        root->left = DeltNode(root->left, x);
    }
    else if (root->data < x)
    {
        root->right = DeltNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = DeltNode(root->right, succ->data);
        }
        
    }
    return root;
}
int main()
{
    struct Node *root = new Node(11);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 20);
    root = DeltNode(root, 7);
    InorderTraversal(root);
    return 0;
}