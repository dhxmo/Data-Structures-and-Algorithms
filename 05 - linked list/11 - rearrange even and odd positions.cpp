/* Write a function that rearranges a linked list to put the nodes in even
positions after the nodes in odd positions in the list, preserving the relative
order of both the evens and the odds. */

#include <iostream>

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
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "X\n";
}

// Time Complexity: O(n)
Node *reorder(struct Node *head)
{
    // base case
    if (!head)
        return head;

    // assign variables for traversal
    Node *odd = head;
    Node *even = head->next;

    // assign variables to separation
    Node *odd_head = head;
    Node *even_head = head->next;

    // traverse the linked list till even->next isn't null
    while (even && even->next)
    {
        // odd points to the next odd
        odd->next = odd->next->next;
        // even points to the next even
        even->next = even->next->next;

        // odd and even pointers moved up
        odd = odd->next;
        even = even->next;
    }

    // once traversal is done, point tail of odd list to even's head
    odd->next = even_head;
    return head;
}

int main()
{

    /* Start with the empty list */
    Node *head = NULL;

    pushIntoList(&head, 4);
    pushIntoList(&head, 3);
    pushIntoList(&head, 2);
    pushIntoList(&head, 8);
    pushIntoList(&head, 24);
    pushIntoList(&head, 7);
    pushIntoList(&head, 29);
    pushIntoList(&head, 52);


    printList(head);

    reorder(head);
    printList(head);

    return 0;
}