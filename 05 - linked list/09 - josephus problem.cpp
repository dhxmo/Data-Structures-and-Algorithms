/*
Imagine that people have decided to kill someone by arranging themselves
in a circle and eliminating every kth person around the circle, closing ranks as each person drops out.
The problem is to ﬁnd out which person will be the last one remaining.
*/

#include <iostream>
#include <vector>

struct Node
{
    int data;
    struct Node *next;
    Node(int key)
    {
        this->data = key;
    }
};

// Function to return the safe position in a josephus problem
// Time complexity : O(N)
// Space complexity : O(N), as we make N recursive calls.
void josephusProblemArrayImp(std::vector<int> circleOfParticipants, int k, int startPos)
{
    // Base case
    if (circleOfParticipants.size() == 1)
    {
        // return the final participant's number
        std::cout << circleOfParticipants[0];
        return;
    }

    // the position to be removed is relative to where the counting starts
    // hop over k participants
    startPos = ((startPos + k) % circleOfParticipants.size());

    // start from the first position of the participants and go up by the calculated positions
    circleOfParticipants.erase(circleOfParticipants.begin() + startPos);

    // Recursive call with updated arguments
    josephusProblemArrayImp(circleOfParticipants, k, startPos);
}

void josephusProblemCLLImp(int n, int k)
{
    // create a circular linked list
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= n; i++)
    {
        // point temp to a new node
        temp->next = new Node(i);
        // move temp over to the new node
        temp = temp->next;
    }
    // point the last element to the first
    temp->next = head;

    Node *ptr1 = head, *ptr2 = head;
    // iterate till ptr1 isn't pointing at itself, ie., only one element remaining
    while (ptr1->next != ptr1)
    {
        // re-initialize count to 1 for every iteration
        int count = 1;

        // iterate for how many nodes need to be skipped
        while (count != k)
        {
            ptr2 = ptr1;
            // ptr1 tracks the node to be removed
            ptr1 = ptr1->next;
            count++;
        }

        // to eliminate ptr1, reassign ptr2's next to the node after ptr1
        // when down to 2, ptr2 points to ptr1->next which makes it point to itself
        ptr2->next = ptr1->next;
        // reassign ptr1 to the node after the eliminated node
        // when down to 2, ptr1 now points at ptr2->next which is ptr2
        ptr1 = ptr2->next;
    }

    std::cout << ptr1->data;
}

int main()
{
    int n, k, startPos;
    std::cout << "Enter values for total number of participants, number of people to skip and the starting position." << std::endl;
    std::cin >> n >> k >> startPos;

    // Calling the function that calculates the safe position.
    std::cout << "The participant at position ";
    josephusProblemCLLImp(n, k);
    std::cout << " gets to live.\n";


    // since vector is zero-indexed but the participant numbers will be 1-indexed
    // reduce k to allow correct iteration
    k--;

    // use n to populate a vector that represents the circle
    std::vector<int> circleOfParticipants;
    for (int i = 1; i <= n; i++)
    {
        circleOfParticipants.push_back(i);
    }

    // Calling the function that calculates the safe position.
    std::cout << "The participant at position ";
    josephusProblemArrayImp(circleOfParticipants, k, startPos);
    std::cout << " gets to live.\n";

    return 0;
}