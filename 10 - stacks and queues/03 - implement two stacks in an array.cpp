/* 
Create a data structure twoStacks that represents two stacks. 
Implementation of twoStacks should use only one array, i.e., 
both stacks should use the same array for storing elements. 
Following functions must be supported by twoStacks.
push1(int x) –> pushes x to first stack 
push2(int x) –> pushes x to second stack
pop1() –> pops an element from first stack and return the popped element 
pop2() –> pops an element from second stack and return the popped element
Implementation of twoStack should be space efficient.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

/*
This method efficiently utilizes the available space. It doesn’t cause
an overflow if there is space available in arr[]. The idea is to start
two stacks from two extreme corners of arr[]. stack1 starts from the
leftmost element, the first element in stack1 is pushed at index 0.
The stack2 starts from the rightmost corner, the first element in stack2
is pushed at index (n-1). Both stacks grow (or shrink) in opposite direction.
To check for overflow, all we need to check is for space between top elements
of both stacks.

Time Complexity: 
    Push operation : O(1)
    Pop operation : O(1)
Auxiliary Space : O(N). 
 */
class TwoStacks
{
    int *arr;
    int size, top1, top2;

public:
    // contructor
    TwoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

// Function to push an integer into stack 1
void TwoStacks::push1(int x)
{
    // if there's space for new element
    if (top1 < top2 - 1)
    {
        // increment pointer of first stack
        top1++;
        // add element
        arr[top1] = x;
    }
    else
    {
        cout << "Stack Overflow";
        exit(1);
    }
}

// Function to push an integer into stack 2
void TwoStacks::push2(int x)
{
    if (top1 < top2 - 1)
    {
        top2--;
        arr[top2] = x;
    }
    else
    {
        cout << "Stack Overflow";
        exit(1);
    }
}

// Function to pop an element from the first stack
int TwoStacks::pop1()
{
    if (top1 >= 0)
    {
        int x = arr[top1];
        top1--;
        return x;
    }
    else
    {
        cout << "Stack Underflow";
        exit(1);
    }
}

// Function to pop an element from the second stack
int TwoStacks::pop2()
{
    if (top2 < size)
    {
        int x = arr[top2];
        top2++;
        return x;
    }
    else
    {
        cout << "Stack Underflow";
        exit(1);
    }
}

int main()
{
    TwoStacks ts(7);
    ts.push1(78);
    ts.push1(18);
    ts.push1(755);
    ts.push2(10);
    ts.push2(1);
    ts.push2(75);
    ts.push2(92);

    cout << "Popped element from stack1 is "
         << ts.pop1();

    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2() << endl;
    return 0;
}