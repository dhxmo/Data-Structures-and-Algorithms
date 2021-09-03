/* 
Given pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing the links between nodes. */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void pushIntoList(struct Node **head, int data)
{
    struct Node *temp = new Node();
    /* put in the data  */
    temp->data = data;
    /* link the old list off the new node */
    temp->next = (*head);
    /* move the head to point to the new node */
    (*head) = temp;
}

void printList(struct Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/* 
Time Complexity : O(N) Traversal of list is done only once and it has 
                 ‘n’ elements
Auxiliary Space : O(N/K) For each Linked List of size n, n/k or 
                 (n/k)+1 calls will be made during the recursion.
*/

struct Node *reverseKGroup(struct Node *head, int k)
{
    // base case
    if (!head)
        return NULL;
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverseKGroup(next, k);

    /* prev is new head of the input list */
    return prev;
}

int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    pushIntoList(&head, 9);
    pushIntoList(&head, 8);
    pushIntoList(&head, 7);
    pushIntoList(&head, 6);
    pushIntoList(&head, 5);
    pushIntoList(&head, 4);
    pushIntoList(&head, 3);
    pushIntoList(&head, 2);
    pushIntoList(&head, 1);

    cout << "\nGiven linked list \n";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "\nReversed Linked list in groups of " << k << endl;
    printList(head);
    cout << endl;

    return 0;
}
