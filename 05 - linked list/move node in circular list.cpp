/*
Given pointers x and t to nodes on a circular list, write a code fragment
that moves the node following t to the position following the node following
x on the list.
*/

#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int key)
    {
        this->data = key;
        this->next = NULL;
    }
};

void push(struct Node **head, int data)
{
    Node *temp = new Node(data);
    temp->next = (*head);
    *head = temp;
}

void print(struct Node *head)
{
    if (head == NULL)
        std::cout << "Empty list\n";

    else
    {
        struct Node *temp = head;
        do
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << head->data << "\n";
    }
}

void moveNode(struct Node *x, struct Node *t)
{
    // assign a variable to the node to be moved
    Node *temp = t->next;

    // as t->next has a reference as temp
    // t->next can be referenced to another node
    t->next = temp->next;

    // as temp->next has been referenced
    // node's next pointer gets moved to the node it's supposed to point to
    temp->next = x->next->next;

    // finally reference the preceding pointer to the new node
    x->next->next = temp;
}

int main()
{
    Node *head = NULL;
    push(&head, 89);
    push(&head, 1);
    push(&head, 65);
    push(&head, 256);
    push(&head, 3423);
    push(&head, 52);
    push(&head, 4231);
    push(&head, 15);

    head->next->next->next->next->next->next->next->next = head;

    std::cout << "Given circular linked list: ";
    print(head);
    std::cout << "\n";

    Node *x = head;
    Node *t = head->next->next->next->next->next;

    moveNode(x, t);

    std::cout << "Modified circular linked list: ";
    print(head);
    std::cout << "\n";
}