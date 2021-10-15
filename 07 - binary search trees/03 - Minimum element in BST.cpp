/* Given a Binary Search Tree. The task is to find the minimum element in this given BST. */

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

/* Iterative function to insert a key into a BST
    Time Complexity - O(h) where h is the height of the BST
    Space Complexity - O(1)
 */

void insertNode(Node *&root, int key)
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

int findMin(struct Node *root)
{
    struct Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int main()
{
    int keys[] = {95, 5, 8, 132, 564, 201, 54};

    Node *root = nullptr;
    for (int key : keys)
    {
        // insertRecursive(root, key);
        insertNode(root, key);
    }

    cout << "The minimum value in the given BST is: " << findMin(root) << endl;

    return 0;
}