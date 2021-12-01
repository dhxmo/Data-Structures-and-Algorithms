/*
given pointers x and t to two disjoint circular lists, insert the list
pointed to by t into the list pointed to by x, at the point following x .
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

void insert(struct Node *x, struct Node *t)
{

    if (x == NULL)
        std::cout << "Empty list\n";

    else
    {
        x->next = t;
        struct Node *temp = x;

        std::cout << x->data << " -> ";
        temp = temp->next;

        do
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != t);
        std::cout << t->data << "\n";
    }
}

int main()
{
    Node *x = NULL;
    push(&x, 1);
    push(&x, 2);
    push(&x, 3);
    push(&x, 4);
    push(&x, 5);
    push(&x, 6);
    push(&x, 7);
    push(&x, 8);
    x->next->next->next->next->next->next->next->next = x;

    Node *t = NULL;
    push(&t, 10);
    push(&t, 20);
    push(&t, 30);
    push(&t, 40);
    t->next->next->next->next = t;

    std::cout << "First circular linked list: ";
    print(x);
    std::cout << "\n";

    std::cout << "Second circular linked list: ";
    print(t);
    std::cout << "\n";

    std::cout << "After running the insertion function, new linked list is: ";
    insert(x, t);
    std::cout << "\n";
}