/* Given a root node reference of a BST and a key, delete the node 
with the given key in the BST. Return the root node reference 
(possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
1. Search for a node to remove.
2. If the node is found, delete the node. */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// Function to create a new node
Node *newNode(int key)
{
    struct Node *node = new Node;
    node->data = key;
    node->left = node->right = NULL;

    return node;
}

// perform in-order traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // go to the left node and print data
    inorder(root->left);
    cout << root->data << " ";

    // go to the right
    inorder(root->right);
}

Node *insert(Node *root, int key)
{
    // start with the rrot node
    Node *curr = root;

    // pointer to store the parent of the current node
    Node *parent = nullptr;

    // if tree is empty, create new node and set as root
    if (root == nullptr)
    {
        return root = newNode(key);
    }

    // traverse the tree and find the parent node of the given key
    while (curr != nullptr)
    {
        // update parent to the current node
        parent = curr;

        if (key < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    // construct a node and assign to the appropriate parent pointer
    if (key < parent->data)
    {
        parent->left = newNode(key);
    }
    else
    {
        parent->right = newNode(key);
    }

    return parent;
}

Node *minValueNode(Node *node)
{
    struct Node *curr = node;

    // loop to find the leftmost leaf
    while (curr && curr->left == NULL)
    {
        curr = curr->left;
    }

    return curr;
}

/* Time Complexity: O(h) where h is the height of the BST. 
    The height of a skewed tree may become n and 
    the time complexity of delete operation may become O(n) */
Node *deleteNode(Node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // if key is lower than root's data, then node in the left subtree
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    // if key is higher than root's data, then node in the right subtree
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    // if key is the node to be deleted
    else
    {
        // node has no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        // node has only one or no child
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            delete temp;
        }

        else
        {
            // node with two children: get smallest in the right subtree
            Node *temp = minValueNode(root->right);

            // copy inorder successor
            root->data = temp->data;

            // delete inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int main()
{
    int keys[] = {20, 500, 10, 30, 600, 40};

    Node *root = NULL;
    root = insert(root, 100);
    for (int key : keys)
    {
        insert(root, key);
    }

    cout << "Binary Search Tree in order: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "Binary Search Tree in order: ";
    inorder(root);
    cout << endl;
}