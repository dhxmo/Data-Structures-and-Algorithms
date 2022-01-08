/* How to implement stack ? */

#include <iostream>

#define SIZE 5

using namespace std;

class Stack
{
private:
    int num[SIZE];
    int top;

public:
    //default constructor
    Stack();
    int push(int);
    int pop();
    bool isEmpty();
    bool isFull();
    void displayItems();
    void swap(int, int);
};

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top == SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stack::push(int n)
{
    if (isFull())
    {
        return false;
    }
    num[++top] = n;
    return n;
}

int Stack::pop()
{
    int temp;

    if (isEmpty())
    {
        return false;
    }
    return num[top--];
}

void Stack::displayItems()
{
    int i;
    cout << "Stack is: ";
    for (i = 0; i < SIZE; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}

void Stack::swap(int i, int j)
{
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.swap(0, 4);

    while (!st.isEmpty())
    {
        cout << st.pop() << " ";
    }

    cout << endl;

    return 0;
}