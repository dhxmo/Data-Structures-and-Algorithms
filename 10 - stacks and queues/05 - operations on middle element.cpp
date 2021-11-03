/* 
How to implement a stack which will support following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element.
*/

#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
};

struct myStack
{
    struct Node *head;
    struct Node *mid;
    int count;
};

struct myStack *createNewStack()
{
    myStack *ms = new myStack();
    ms->count = 0;
    return ms;
}

void push(struct myStack *ms, int data)
{
    struct Node *curr = new Node();
    curr->data = data;

    // add to the beginning
    curr->prev = NULL;
    // add the node in front of head
    curr->next = ms->head;
    // new node has been added
    ms->count++;

    // if one node present, point mid to that node
    if (ms->count == 1)
        ms->mid = curr;
    else
    {
        // create a doubly linked list and point head to curr
        ms->head->prev = curr;
        // even number of nodes, mid shifts up by one
        if (!(ms->count & 1))
            ms->mid = ms->mid->prev;
    }

    // curr becomes the head of the list
    ms->head = curr;
}

int pop(struct myStack *ms)
{
    // Stack underflow
    if (ms->count == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    // store head in a temp variable
    struct Node *temp = ms->head;
    int x = ms->head->data;

    // head needs to be deleted, hence shifted forward
    ms->head = ms->head->next;

    // if doubly ll not empty, prev of head = NULL
    if (ms->head != NULL)
        // break the pointer to prev node
        ms->head->prev = NULL;
    // reduce count
    ms->count--;

    // if counter is odd after node has been deleted
    if ((ms->count) & 1)
        // move mid pointer down
        ms->mid = ms->mid->next;

    free(temp);
    return x;
}

int findMiddle(myStack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    return ms->mid->data;
}

int deleteMiddle(struct myStack *ms)
{
    // stack underflow
    if (ms->count == 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }

    // save mid node of the stack in a variable
    struct Node *mid = ms->mid;
    int x = mid->data;

    // decrement value as mid is to be deleted
    ms->count--;

    // if only one element left in the stack
    if (ms->count == 1)
    {
        // head was the last deleted element
        // head moves to the final element's next
        ms->head = ms->head->next;
        // mid moves to the last element, which is the head
        ms->mid = ms->head;
    }
    else if (ms->count > 0)
    {
        // to delete mid element = bypass mid
        // move mid's prev node's next pointer to mid's next node
        ms->mid->prev->next = ms->mid->next;
        // move mid's next node's prev pointer to mid's prev node
        ms->mid->next->prev = ms->mid->prev;

        // if odd number of nodes left
        if ((ms->count) & 1)
            // mid is moved up
            ms->mid = ms->mid->next;
        else
            // for even nodes, mid is moved down
            ms->mid = ms->mid->prev;
    }

    free(mid);
    return x;
}

void print(struct myStack *ms)
{
    struct Node *curr = ms->head;
    if (ms->count == 0)
    {
        cout << "Stack is empty\n";
        return;
    }
    for (int i = 0; i < ms->count; i++)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    myStack *ms = createNewStack();
    push(ms, 1);
    push(ms, 2);
    push(ms, 3);
    push(ms, 4);
    push(ms, 5);
    push(ms, 6);
    push(ms, 7);

    cout << "Stack is : ";
    print(ms);
    cout << endl;

    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << endl;

    cout << "Stack is : ";
    print(ms);
    cout << "Middle Element is " << findMiddle(ms) << endl;
    cout << "Deleting Middle Element" << endl;
    deleteMiddle(ms);
    cout << endl;

    cout << "Stack is : ";
    print(ms);
    cout << "Middle Element is " << findMiddle(ms) << endl;

    return 0;
}