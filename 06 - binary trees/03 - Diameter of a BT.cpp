/*  The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between 
two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends 
of the longest path are shaded (note that there is more than one path in each tree of length nine, 
but no path longer than nine nodes).  */

#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

/* 

The diameter of a tree T is the largest of the following quantities:

Return max of following three: 
1) Diameter of left subtree
2) Diameter of right subtree
3) Height of left subtree + height of right subtree + 1

Time Complexity: O(n^2)
*/
int height(struct Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(struct Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    // height of left and right sub tree
    int leftSubTreeHeight = height(root->left);
    int rightSubTreeHeight = height(root->right);

    // diameter of left and right sub tree
    int leftSubTreeDiameter = diameter(root->left);
    int rightSubTreeDiameter = diameter(root->right);

    return max(leftSubTreeHeight + rightSubTreeHeight + 1, max(leftSubTreeDiameter, rightSubTreeDiameter));
}


/* Time Complexity: O(N)
the diameter of a tree is maximum value of (left_height + right_height + 1) for each node. So we need to calculate this value (left_height + right_height + 1) for each node and update the result.
*/
int heightUtil(struct Node *root, int &height) {
    if (root == NULL)
        return 0;

    int leftSubTreeHeight = heightUtil(root->left, height);
    int rightSubTreeHeight = heightUtil(root->right, height);

    // update height
    // diameter is max value of the height of each subtree
    height = max(height, 1 + leftSubTreeHeight + rightSubTreeHeight);

    return 1 + max(leftSubTreeHeight, rightSubTreeHeight);

    
}

int diameterOptimized (struct Node *root) {
    if (root == NULL)
        return 0;
    int h = INT8_MIN;
    heightUtil(root, h);
    return h;
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int height = 0;

    cout << "Diameter of the binary tree: " << diameterOptimized(root) << endl;

    return 0;
}