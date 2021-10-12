/* Given an array of intervals where intervals[i] = [starti, endi],
 merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

/* simple approach

1. Sort the intervals based on increasing order of 
    starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the stack 
       top, push it.
   b. If the current interval overlaps with stack top and ending
       time of current interval is more than that of stack top, 
       update stack top with the ending time of current interval.
4. At the end, stack contains the merged intervals. 
*/

// define an interval structure and compare them
struct Interval
{
    int start, end;
};

bool compareIntervals(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

// Time complexity - O(n^2) worst case | usually O(NlogN)
// space complexity - O(N)
// void mergeIntervals(Interval arr[], int n)
// {
//     // final case
//     if (n <= 0)
//         return;

//     stack<Interval> st;

//     // sort in increasing time
//     sort(arr, arr + n, compareIntervals);

//     st.push(arr[0]);

//     for (int i = 0; i < n; i++)
//     {
//         // interval from stack top
//         Interval top = st.top();

//         // if current intervals aren't overlapping, push to stack
//         if (top.end < arr[i].start)
//         {
//             st.push(arr[i]);
//         }
//         // if ending of current is more
//         else if (top.end < arr[i].end)
//         {
//             top.end = arr[i].end;
//             // get previous off the stack
//             st.pop();
//             // push new interval
//             st.push(top);
//         }
//     }

//     // Print contents of stack
//     cout << "[";
//     while (!st.empty())
//     {
//         Interval t = st.top();
//         cout << " [" << t.start << "," << t.end << "] ";
//         st.pop();
//     }
//     cout << "]";

//     return;
// }

/* 1) Sort all intervals in increasing order of start time.
2) Traverse sorted intervals starting from first interval, 
   do following for every interval.
      a) If current interval is not first interval and it 
         overlaps with previous interval, then merge it with
         previous interval. Keep doing it while the interval
         overlaps with the previous one.         
      b) Else add current interval to output list of intervals. */

// time complexity - O(NlogN)  |  space compelxity - O(1)
void mergeIntervals(Interval arr[], int n)
{
    // sort using i1.start < i2.start comdition
    sort(arr, arr + n, compareIntervals);

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        // if current interval overlaps the previous one
        if (arr[index].end >= arr[i].start)
        {
            arr[index].end = max(arr[index].end, arr[i].end);
            arr[index].start = min(arr[index].start, arr[index].start);
        }
        else
        {
            // index moves up
            index++;
            // shift a value up
            arr[index] = arr[i];
        }
    }

    cout << "Merged intervals: ";
    cout << "[ ";
    for (int i = 0; i <= index; i++)
    {
        cout << "[ " << arr[i].start << ", " << arr[i].end << " ]";
    }
    cout << " ]" << endl;

    return;
}

int main()
{
    Interval arr[] = {{1, 3}, {2, 6}, {8, 20}, {15, 18}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}