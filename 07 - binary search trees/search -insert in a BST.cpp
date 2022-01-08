/* Search and Insert Nodes into a Binary Search Tree */

#include <iostream>
using namespace std;

// data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
};

// Function to create a new node
Node *newNode(int key)
{
    Node *node = new Node;
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

/* recursive function to insert a key into a BST
    Time Complexity - O(h) where h is the BST height
                    for height balanced trees - logN
    Space Complexity - O(h) - space used by the call stack */
void insertRecursive(Node *&root, int key)
{
    if (root == NULL)
    {
        root = newNode(key);
        return;
    }

    // if given key is less than root, recur to the left subtree
    if (key < root->data)
    {
        insertRecursive(root->left, key);
    }
    else
    {
        insertRecursive(root->right, key);
    }
}

/* Recursive function to search in a given BST 
    Time Complexity - O(h) where h is the BST height
                    for height balanced trees - logN
    Space Complexity - O(h) - space used by the call stack
*/

void searchRecursive(Node *root, int key, Node *parent)
{
    if (root == nullptr)
    {
        cout << "Key not found";
        return;
    }

    if (root->data == key)
    {
        if (parent == nullptr)
        {
            cout << "Node with key " << key << " is root node.";
        }
        else if (key < parent->data)
        {
            cout << "Key " << key << " is the left node of the node with key " << parent->data;
        }
        else
        {
            cout << "Key " << key << " is the right node of the node with key " << parent->data;
        }

        return;
    }

    if (key < root->data)
    {
        return searchRecursive(root->left, key, root);
    }

    return searchRecursive(root->right, key, root);
}

/* Iterative function to insert a key into a BST
    Time Complexity - O(h) where h is the height of the BST
    Space Complexity - O(1)
 */

void insertIterative(Node *&root, int key)
{
    // start with the rrot node
    Node *curr = root;

    // pointer to store the parent of the current node
    Node *parent = nullptr;

    // if tree is empty, create new node and set as root
    if (root == nullptr)
    {
        root = newNode(key);
        return;
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
}

/* Iterative function to search a key in a BST
    Time Complexity - O(h) where h is the height of the BST
    Space Complexity - O(1) */

void searchIterative(Node *root, int key)
{
    // start at the root
    Node *curr = root;

    // pointer to store the parent of the current node
    Node *parent = curr;

    while (curr != nullptr && curr->data != key)
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

    if (curr == nullptr)
    {
        cout << "Key Not Found \n";
        return;
    }

    if (parent == nullptr)
    {
        cout << "The node with key " << key << " is the root node.";
    }
    else if (key < parent->data)
    {
        cout << "Key " << key << " is the left node of node with key " << parent->data;
    }
    else
    {
        cout << "Key " << key << " is the right node of node with key " << parent->data;
    }
}

int main()
{
    int keys[] = {95, 5, 8, 132, 564, 201, 54};

    Node *root = nullptr;
    for (int key : keys)
    {
        // insertRecursive(root, key);
        insertIterative(root, key);
    }

    cout << "Binary Search Tree in order: ";
    inorder(root);
    cout << endl;

    searchRecursive(root, 132, nullptr);
    cout << endl;

    searchIterative(root, 201);
    cout << endl;

    return 0;
}