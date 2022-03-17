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
int LevelOrderLineByLine(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int maxi=1;
    while (q.size() > 1)
    {
        if(q.size()>maxi)
        {
            maxi=q.size();
        }
        
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            // cout << "\n";
            q.push(NULL);
            continue;
        }
        // cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
    return maxi;
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
    cout<<LevelOrderLineByLine(root)-1;
    return 0;
}