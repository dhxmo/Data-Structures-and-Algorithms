/* Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.
 */

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

// Print nodes at the current level
void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Compute the height of the tree
int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        // compute height of each subtree
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight)
        {
            // number of levels = number of traversals + 1
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}

/* 
Time Complexity: O(N^2) in worst case. 
                For a skewed tree, printGivenLevel() takes O(n) time where n is the number of 
                nodes in the skewed tree. So time complexity of printLevelOrder() is 
                O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2). 
Space Complexity: O(N) in worst case. 
                For a skewed tree, printGivenLevel() uses O(n) space for call stack. 
                For a Balanced tree, the call stack uses O(log n) space, (i.e., the height of the balanced tree). 
 */
void printLevelOrderSubOp(Node *root)
{
    int h = height(root);
    int i;
    for (int i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
    }
}

/* 
Time Complexity: O(N) where N is the number of nodes in the binary tree 
Space Complexity: O(N) where N is the number of nodes in the binary tree 
 */

void printLevelOrderOp(Node *root)
{
    //base case
    if (root == NULL)
        return;

    // FIFO data structure
    queue<Node *> que;
    que.push(root);

    while (que.empty() == false)
    {
        // print the first item and remove
        Node *node = que.front();
        cout << node->data << " ";
        que.pop();

        // enqueue left child
        if (node->left != NULL)
        {
            que.push(node->left);
        }

        //enqueue right child
        if (node->right != NULL)
        {
            que.push(node->right);
        }
    }
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

    cout << "Level Order Traversal of binary tree is \n";
    // printLevelOrderSubOp(root);
    printLevelOrderOp(root);
    cout << endl;

    return 0;
}