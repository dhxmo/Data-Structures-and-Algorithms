/* 
    Given a binary tree, the task is to create a new binary tree 
    which is a mirror image of the given binary tree.
 */

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// Helper to add a new node
struct Node *newNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";

    inorderTraversal(root->right);
}

/* 
Time Complexity: O(n)
Auxiliary Space: O(h), where h is the height of the tree
 */
void mirror(struct Node *root)
{
    if (root == NULL)
        return;

    else
    {
        struct Node *temp;

        // recursive call
        mirror(root->left);
        mirror(root->right);

        // swap pointers
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void mirrorIterative(struct Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    // run a BFS
    while (!q.empty())
    {
        // pop the top node
        struct Node *curr = q.front();
        q.pop();

        // swap left and right child
        swap(curr->left, curr->right);

        // push left and right children to que
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Inorder traversal of original tree: ";
    inorderTraversal(root);
    cout << endl;

    mirror(root);

    cout << "Inorder traversal of mirror tree: ";
    inorderTraversal(root);
    cout << endl;

    mirrorIterative(root);

    cout << "Inorder traversal of original tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}