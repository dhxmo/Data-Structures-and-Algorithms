#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <queue>
using namespace std;

/* Brute-force
Time Complexity: O(N * K).
The outer loop runs n-k+1 times and the inner loop runs k times for every
iteration of outer loop. So time complexity is O((n-k+1)*k)
which can also be written as O(N * K).

Space Complexity: O(1).
No extra space is required.
 */
void slidingWindowBrute(int arr[], int n, int k)
{
    int j, max;

    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];

        for (j = 1; j < k; j++)
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}

/*
Time Complexity: O(NlogN)
Space Complexity: O(k) as multiset is of size k
*/
void slidingWindowMS(int arr[], int size, int k)
{
    // greater comparator so the highest value is always on top
    multiset<int, greater<int>> ms;
    vector<int> ans;

    // insert elements of array to multiset
    for (int i = 0; i < k; i++)
        ms.insert(arr[i]);
    // push the greatest number in multiset to vector
    ans.push_back(*ms.begin());

    // iterate for the rest of the elements
    for (int i = k; i < size; i++)
    {
        // clear the multiset element for the newer batch of numbers
        // lower_bound to prevent deletion of duplicates
        ms.erase(ms.lower_bound(arr[i - k]));
        // insert element in ms
        ms.insert(arr[i]);
        // insert max element in ms to vector
        ans.push_back(*ms.begin());
    }

    for (auto i : ans)
        cout << i << " ";

    return;
}

/*
Time Complexity: O(N * log k). Heap can be built in log K over N elements
Space Complexity: O(k).
The space required to store k elements
 */
void slidingWindowMaxHeap(int arr[], int size, int k)
{
    // maxHeap to find max number in a sliding window
    // pair<int, int> contains (arr[i], index)
    priority_queue<pair<int, int>> maxHeap;
    vector<int> ans;

    // slide across the array
    for (int i = 0; i < size; i++)
    {
        // pop the root if its out of the range of the sliding window
        while (!maxHeap.empty() and maxHeap.top().second <= (i - k))
            maxHeap.pop();

        // push current element with index onto heap
        maxHeap.push(make_pair(arr[i], i));

        // store max in a window if we have a valid window
        // only if current pointer is at k-1 or more
        // do we have a valid window size
        if (i >= k - 1)
            // push the maximum of the maxHeap root to vector
            ans.push_back(maxHeap.top().first);
    }

    for (auto i : ans)
        cout << i << " ";

    return;
}

/*
Time Complexity: O(n) as each element is pushed and popped just once
Auxiliary Space: O(k)
 */
void slidingWindowDeque(int arr[], int size, int k)
{
    // deque must be in decreasing order
    // pair<int, int> contains (arr[i], index)
    deque<pair<int, int>> dq;
    vector<int> ans;

    for (int i = 0; i < size; i++)
    {
        // remove front element if it goes out of the window size
        if (!dq.empty() and dq.front().second <= (i - k))
            dq.pop_front();

        // to maintain elements in descending order
        while (!dq.empty() and dq.back().first < arr[i])
            dq.pop_back();

        // push current node to the end of the que
        dq.push_back(make_pair(arr[i], i));

        if (i >= k - 1)
            // push maximum of current window to vector
            ans.push_back(dq.front().first);
    }

    for (auto i : ans)
        cout << i << " ";

    return;
}

int main()
{
    int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    slidingWindowBrute(arr, n, k);
    cout << endl;

    slidingWindowMS(arr, n, k);
    cout << endl;

    slidingWindowMaxHeap(arr, n, k);
    cout << endl;

    slidingWindowDeque(arr, n, k);
    cout << endl;
    return 0;
}