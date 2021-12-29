#include <iostream>

struct Node
{
    int data;
    struct Node *next;
    Node(int key) {
        this->data = key;
    }
};

void push(struct Node **head, int new_data)
{
    struct Node *newNode = new Node(new_data);
    newNode->next = (*head);
    *head = newNode;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

Node *copyList(Node *head)
{
    if(head == NULL)
        return head;

    struct Node *temp = new Node(head->data);
    temp->next = copyList(head->next);

    return temp;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    std::cout << "Original list: ";
    printList(head);

    struct Node *copiedList = copyList(head);
    std::cout << "Copy list: ";
    printList(copiedList);

    return 0;
}