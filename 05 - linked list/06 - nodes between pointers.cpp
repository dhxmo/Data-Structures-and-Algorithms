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

int nodesInBetween(Node *node1, Node *node2)
{
    int count = 0;

    Node *temp = node1->next;
    while (temp != node2)
    {
        count++;
        temp = temp->next;
    }

    return count;
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
    std::cout << "Total nodes between node " << x->data << " & " << t->data
              << " = " << nodesInBetween(x, t) << "\n";
}