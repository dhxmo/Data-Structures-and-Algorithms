/* 
There is BST given with root node with key part as integer only. 
You need to find the inorder successor and predecessor of a given key. 
In case, if the either of predecessor or successor is not found print -1.
*/

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

void findPreSuc(struct Node *root, struct Node *&pre, struct Node *&suc, int key)
{
    // base case
    if (root == NULL)
        return;

    // if key is at root
    if (root->data == key)
    {
        // max value in left subtree is predecessor
        if (root->left != NULL)
        {
            struct Node *temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        // min value in right subtree is successor
        if (root->right != NULL)
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    // if key smaller than root, move into left subtree
    if (root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    // else move into right subtree
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main()
{
    int key = 50;

    int keys[] = {50, 30, 20, 40, 70, 60, 80, 90};

    Node *root = NULL, *pre = NULL, *suc = NULL;
    for (int key : keys)
    {
        insertNode(root, key);
    }

    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << "Predecessor of " << key << " is " << pre->data << endl;
    else
        cout << "No Predecessor" << endl;

    if (suc != NULL)
        cout << "Successor of " << key << " is " << suc->data << endl;
    else
        cout << "No Successor" << endl;
    return 0;
}