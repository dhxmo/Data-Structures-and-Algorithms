/* Write a function findFirstLoopNode() that checks whether a given 
Linked List contains a loop. If the loop is present then it returns 
point to the first node of the loop. Else it returns NULL. */

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *push(int new_data)
{
    Node *newNode = new Node();
    newNode->data = new_data;
    newNode->next = NULL;
    return newNode;
}

Node *firstNodeOfLoop(struct Node *head)
{
    // if list is empty or has one node
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head, *fast = head;

    // detect loop using floyd's algorithm
    slow = slow->next;
    fast = fast->next->next;

    while (fast && fast->next)
    {
        if (slow == fast)
            break;

        slow = slow->next;
        fast = fast->next->next;
    }

    // if there's no loop
    if (slow != fast)
        return NULL;

    // reset slow to head and iterate till the two pointers are equal
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// hashing could be used to perform this operation
Node *firstNodeOfLoopM2(Node *head)
{
    unordered_set<Node *> set;

    Node *temp = head;

    while (temp != NULL)
    {
        if (set.find(temp) != set.end())
            return temp;
        else
            set.insert(temp);

        temp = temp->next;
    }

    return NULL;
}

int main()
{
    Node *head = push(5);
    head->next = push(59);
    head->next->next = push(1);
    head->next->next->next = push(421);
    head->next->next->next->next = push(1087);

    head->next->next->next->next->next = head->next->next;

    Node *result = firstNodeOfLoop(head);
    if (result == NULL)
        cout << "There is no loop in the given linked list";
    else
        cout << "The starting node of the loop = " << result->data << endl;

    Node *result2 = firstNodeOfLoopM2(head);
    if (result2 == NULL)
        cout << "There is no loop in the given linked list";
    else
        cout << "The starting node of the loop = " << result2->data << endl;

    return 0;
}