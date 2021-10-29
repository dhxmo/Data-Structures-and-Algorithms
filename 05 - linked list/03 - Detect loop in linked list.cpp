/* Given a linked list of N nodes. The task is to check if the linked list has a loop.
Linked list can contain self loop. */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int new_data)
{
    struct Node *newNode = new Node();
    newNode->data = new_data;
    newNode->next = (*head);
    *head = newNode;
}

/*
using Floyd's cycle-finding algorithm

Approach:
1. Traverse linked list using two pointers.
2. Move one pointer(slow_p) by one and another pointer(fast_p) by two.
If these pointers meet at the same node then there is a loop.
If pointers do not meet then linked list doesn’t have a loop.

Time complexity: O(n), Only one traversal of the loop is needed.
Auxiliary Space:O(1)
*/
bool detectLoop(struct Node *root)
{
    struct Node *slow_ptr = root, *fast_ptr = root->next;
    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        if (slow_ptr == fast_ptr)
            return true;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    return false;
}

/* In this method, a temporary node is created. The next pointer of
each node that is traversed is made to point to this temporary node.
This way we are using the next pointer of a node as a flag to indicate
whether the node has been traversed or not. Every node is checked
to see if the next is pointing to a temporary node or not.
In the case of the first node of the loop, the second time we traverse
it this condition will be true, hence we find that loop exists.
If we come across a node that points to null then the loop doesn’t exist.

Time complexity: O(n)
Auxiliary Space:O(1)
*/
bool detectLoop_Alt(Node *head)
{

    // Create a temporary node
    struct Node *temp = new Node;
    while (head != NULL)
    {
        // base case
        if (head->next == NULL)
        {
            return false;
        }

        // Check if next is already pointing to temp
        if (head->next == temp)
        {
            return true;
        }

        // Store the pointer to the next node
        // in order to get to it in the next step
        struct Node *nex = head->next;

        // Make next point to temp
        head->next = temp;

        // Get to the next node in the list
        head = nex;
    }

    return false;
}

int main()
{
    Node *head = NULL;
    push(&head, 24);
    push(&head, 4);
    push(&head, 89);
    push(&head, 1);

    head->next->next->next->next = head;
    if (detectLoop_Alt(head))
        cout << "Loop exists in the given list" << endl;
    else
        cout << "No loop exists in the given list" << endl;

    return 0;
}