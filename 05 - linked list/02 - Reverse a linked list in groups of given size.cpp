/* 
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed  
*/

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

/*  Time Complexity: O(N) where N is the number of nodes in the given list
    Space Complexity: O(1) */

Node* reverse(struct Node* head, int k)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;

    Node* newHead = NULL;
    
    Node* tail = NULL;
    Node* join = NULL;
    int t = 0;
 
    // Traverse till the end of the linked list
    while (curr) {
        t = k;
        join = curr;
        prev = NULL;
 
        // Reverse group of k nodes of the linked list
        while (curr && t--) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
 
        // Sets the new head of the input list
        if (!newHead)
            newHead = prev;
 
        /* Tail pointer keeps track of the last node
        of the k-reversed linked list. We join the
        tail pointer with the head of the next
        k-reversed linked list's head */
        if (tail)
            tail->next = prev;
 
        /* The tail is then updated to the last node
        of the next k-reverse linked list */
        tail = join;
    }
 
    /* newHead is new head of the input list */
    return newHead;
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
    head = reverse(head, k);

    cout << "\nReversed Linked list in groups of " << k << endl;
    printList(head);
    cout << endl;

    return 0;
}
