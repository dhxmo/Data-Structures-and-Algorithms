#include <iostream>
#include <queue>
using namespace std;

// define a binary tree node
class Node
{
public:
    int data;
    Node *left, *right;
};

// Helper to add a new node
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/*  Time Complexity: O(N)
    Auxiliary Space: O(N) 
*/

int height(Node *root)
{
    return (root) ? max(height(root->left), height(root->right)) + 1 : 0;
}

int iterativeHeight(Node *root)
{
    int height = 0;
    queue<Node *> que;

    if (root)
        que.push(root);

    while (que.size())
    {
        int size = que.size();
        while (size--)
        {
            if (que.front()->left)
                que.push(que.front()->left);
            if (que.front()->right)
                que.push(que.front()->right);
            que.pop();
        }
        height++;
    }

    return height;
}
// Driver code
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

    cout << "Height of binary tree: " << iterativeHeight(root) << endl;

    return 0;
}