/* Write a function that moves the largest item on a given list to be the
ﬁnal node on the list. */
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

void largestToFinal(struct Node *head)
{
    // get two pointers, one for the highest number and another to iterate over the linked list
    Node *highestNode = head, *iterativeNode = head;

    // iterate over the list
    while (iterativeNode->next != NULL)
    {
        // move the highest node pointer up only if the next node is greater than the current node
        if (iterativeNode->next->data > highestNode->data)
            highestNode = highestNode->next;

        // move iteration pointer up
        iterativeNode = iterativeNode->next;
    }

    // assign pointer to get the node previous to the highest data
    Node *prevNode = head;
    while (prevNode->next->data != highestNode->data)
        prevNode = prevNode->next;

    // all pointers are in place
    // bridge over highest node
    prevNode->next = highestNode->next;
    // link last node to the highest node
    iterativeNode->next = highestNode;
    // make highest the new last node
    highestNode->next = NULL;
}

int main()
{

    /* Start with the empty list */
    Node *head = NULL;

    /* Created Linked list is 1 -> 5 -> 2 -> 3 -> 4 -> X */
    pushIntoList(&head, 4);
    pushIntoList(&head, 3);
    pushIntoList(&head, 2);
    pushIntoList(&head, 5);
    pushIntoList(&head, 1);

    printList(head);

    largestToFinal(head);
    printList(head);

    return 0;
}