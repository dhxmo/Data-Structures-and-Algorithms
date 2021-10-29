/* 
Given pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing the links between nodes. */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        // simplification for (*this).data
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void pushIntoLL(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    /* Iterative Method 

        1. Initialize three pointers prev as NULL, curr as head and next as NULL.
        2. Iterate through the linked list. In loop, do following. 
            Before changing next of current, store next node 
            next = curr->next
            Now change next of current. This is where actual reversing happens 
            curr->next = prev 
            Move prev and curr one step forward 
            prev = curr 
            curr = next 

        Time Complexity: O(N)
        Space Complexity: O(1)
    */
    void iterativeReverse()
    {
        // initialize current, previous and next pointers
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        // iterate through the LL
        while (current != NULL)
        {
            // store next
            next = current->next;

            //reverse pointer
            current->next = prev;

            //move pointers ahead
            prev = current;
            current = next;
        }

        // redefine head to the LL's end
        head = prev;
    }

    // Time Complexity: O(N)
    // Space Complexity: O(1)
    void recursiveReverse(Node *prev, Node *curr)
    {
        // empty ll, return
        if (!curr)
        {
            return;
        }

        if (!curr->next)
        {
            // make last element the head
            head = curr;
            // point last element's pointer to the element previous to it
            curr->next = prev;
            return;
        }
        else
        {
            // pass recursively to the curr and the curr's next
            recursiveReverse(curr, curr->next);
            // once function returns, point curr's next to the previous
            curr->next = prev;
        }
    }
};

int main()
{
    LinkedList ll;
    ll.pushIntoLL(79);
    ll.pushIntoLL(7);
    ll.pushIntoLL(47);
    ll.pushIntoLL(56);
    ll.pushIntoLL(548);
    ll.pushIntoLL(795);
    ll.pushIntoLL(5);
    ll.pushIntoLL(54);

    cout << "Given linked list: \n";
    ll.print();
    cout << endl;

    ll.iterativeReverse();
    // ll.recursiveReverse(NULL, ll.head);

    cout << "Reversed linked list: \n";
    ll.print();
    cout << endl;

    return 0;
}

/* recursive
       head
        1 -> 2 -> 3 -> null
prev  curr

       head
        1 -> 2 -> 3 -> null
      prev  curr

       head
        1 -> 2 -> 3 -> null
            prev curr  

since curr->next = null 
        curr = head

                 head
        1 -> 2 -> 3 -> null
            prev curr  

        curr->next = prev

                 head
        1 -> 2 <- 3
            prev curr  

return to 2

        curr->next = prev

                 head
        1 <- 2 <- 3 -> null
       prev curr  

return to 1

        curr->next = prev

                   head
  null <- 1 <- 2 <- 3 -> null
  prev   curr

 */