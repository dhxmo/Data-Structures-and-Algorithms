/*
Sort the given Linked List using quicksort. which takes O(n^2) time in worst case
and O(nLogn) in average and best cases, otherwise you may get TLE.

Input:
In this problem, method takes 1 argument: address of the head of the linked list.
The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which
points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set *headRef to head of resultant linked list.

User Task:
The task is to complete the function quickSort() which should set the *headRef
to head of the resultant linked list.

Constraints:
1<=T<=100
1<=N<=200
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void push(struct node **head, int new_data)
{
    struct node *new_node = new node(new_data);
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void qs(struct node *head, struct node *tail = nullptr)
{
    if (!head || head == tail)
        return;

    struct node *prev = head, *curr = head->next;
    int pivot = head->data;

    // find values lower than the pivot
    while (curr != tail)
    {
        if (pivot > curr->data)
        {
            // prev acts as the boundary to numbers lessers than pivot
            // use prev->next to not affect the pivot value on first iteration
            swap(curr->data, prev->next->data);
            // move prev ahead
            prev = prev->next;
        }
        curr = curr->next;
    }
    // swap pivot at prev which is the boundary of numbers lesser than pivot
    swap(head->data, prev->data);

    // recurse
    qs(head, prev);
    if (prev != tail)
        qs(prev->next, tail);
}

void quickSort(struct node **head)
{
    qs(*head);
}

int main()
{
    node *head = NULL;
    push(&head, 24);
    push(&head, 4);
    push(&head, 89);
    push(&head, 1);

    printList(head);

    quickSort(&head);
    printList(head);
    return 0;
}