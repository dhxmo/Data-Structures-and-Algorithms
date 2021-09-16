#include <iostream>
#include <cstdlib>
using namespace std;

// capacity of queue
#define SIZE 10

class Queue
{
    int *arr;
    int capacity;
    int first;
    int last;
    int currentSize;

public:
    Queue(int size = SIZE); //contructor
    ~Queue();

    void dequeue();
    void enqueue(int key);
    int front();
    int back();
    int size();
    bool isEmpty();
    bool isFull();
};

// constructor
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    first = 0;
    last = -1;
    currentSize = 0;
}

// destructor - free allocated memory to queue
Queue::~Queue()
{
    delete[] arr;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow\nThe que is empty";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[first] << " from que" << endl;

    first = (first + 1) % capacity;
    currentSize--;
}

void Queue::enqueue(int key)
{
    if (isFull())
    {
        cout << "Overflow\n The que is at capacity";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << key << " to que" << endl;

    last = (last + 1) % capacity;
    arr[last] = key;
    currentSize++;
}

int Queue::front()
{
    if (isEmpty())
    {
        cout << "Undeflow\nQue is empty";
        exit(EXIT_FAILURE);
    }
    return arr[first];
}

int Queue::back()
{
    if (isEmpty())
    {
        cout << "Undeflow\nQue is empty";
        exit(EXIT_FAILURE);
    }
    return arr[last];
}

int Queue::size()
{
    return currentSize;
}

bool Queue::isEmpty()
{
    return (size() == 0);
}

bool Queue::isFull()
{
    return (size() == capacity);
}

int main()
{
    Queue que(3);

    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);

    cout << "The front element of the que is " << que.front() << endl;

    que.dequeue();
    que.dequeue();

    que.enqueue(100);
    que.enqueue(200);

    cout << "The front element of the que is " << que.front() << endl;
    cout << "The queue's size = " << que.size() << endl;

    if (que.isEmpty())
    {
        cout << "Que is empty\n";
    }
    else
    {
        cout << "Que is not empty\n";
    }

    return 0;
}