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
    int count = 0;

    if (head == NULL)
        std::cout << "Empty list\n";

    else
    {
        struct Node *temp = head;
        do
        {
            std::cout << temp->data << " -> ";
            count++;
            temp = temp->next;
        } while (temp != head);
        std::cout << head->data << "\n";
    }
    std::cout << "Total nodes in linked list = " << count << "\n";
}

int main()
{
    Node *head = NULL;
    push(&head, 24);
    push(&head, 4);
    push(&head, 89);
    push(&head, 1);

    head->next->next->next->next = head;

    std::cout << "Given circular linked list: ";
    print(head);
    std::cout << "\n";
}