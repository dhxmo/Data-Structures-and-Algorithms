/*
Given a binary tree, we need to find maximum value we can get
by subtracting value of node B from value of node A, where A
and B are two nodes of the binary tree and A is an ancestor of B.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Helper to add a new node
struct Node *newNode(int data)
{
    Node *node = new Node(data);
    node->left = NULL;
    node->right = NULL;

    return node;
}

// define max globally
int max_diff;

int dfs(Node *root)
{
    // for no children, return the max difference found
    if (!root)
        return INT_MAX;

    // find the minimum in left and right sub tree of the current node
    int min_node_value = min(dfs(root->left), dfs(root->right));

    // subtract the current node with the min value and compare against the max difference
    max_diff = max(max_diff, root->data - min_node_value);

    return min(root->data, min_node_value);
}

int maxDiff(Node *root)
{
    max_diff = INT_MIN;
    dfs(root);
    return max_diff;
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    int max_difference = maxDiff(root);
    cout << "Maximum difference for the given tree = " << max_difference << endl;

    return 0;
}