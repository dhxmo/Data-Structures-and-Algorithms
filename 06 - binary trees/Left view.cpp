/*
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is
set of nodes visible when tree is visited from Left side.
*/

#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printLeftView(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // number of nodes at current level
        int n = q.size();

        // Traverse all nodes of current level
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            // Print the left most element
            // at the level
            if (i == 1)
                cout << temp->data << " ";

            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(23);
    root->left->right = newNode(432);
    root->right->right = newNode(25);
    root->right->left = newNode(21);
    root->right->left->left = newNode(6497);

    printLeftView(root);
    return 0;
}