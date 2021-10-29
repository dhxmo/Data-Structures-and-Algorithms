/* Given a binary tree, find its preorder, inorder and postorder traversal.
These are depth-first traversal for the tree.
 */

#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
};

// Helper to add a new node
struct Node *newNode(char data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* 
<root> <left> <right> 
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree
*/
void preOrderTraversal(struct Node *root)
{
    // base case to prevent infinite recursion
    if (root == NULL)
        return;

    cout << root->data << " ";

    //recursively call the left sub-tree
    preOrderTraversal(root->left);

    // recursively call the left sub-tree
    preOrderTraversal(root->right);
}

/* 
<left> <root> <right> 
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree
*/
void inOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";

    inOrderTraversal(root->right);
}

/* 
<left> <right> <root>
Time Complexity: O(n)
Space Complexity: O(h), where h is the height of the tree
 */
void postOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Driver code
int main()
{
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('F');
    root->right->right->left = newNode('G');

    cout << "Pre-Order traversal of the given binary tree: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-Order traversal of the given binary tree: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-Order traversal of the given binary tree: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
