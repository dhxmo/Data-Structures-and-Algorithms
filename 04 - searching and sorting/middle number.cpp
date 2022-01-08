/*
    Given distinct numbers. Find the number with value in middle (Try to do it with minimum comparisons).
*/

#include <iostream>
#include <queue>
#include <vector>

class MiddleNumber
{
public:
    // Time Complexity: O(1)
    int middle(std::vector<int> arr)
    {
        // instantiate a priority que
        std::priority_queue<int> pq;

        // push numbers into priority que
        for (int i = 0; i < arr.size(); i++)
            pq.push(arr[i]);

        // determine half the length. Use int to deal with odd number
        int half_length = arr.size() / 2;

        // pop half the que off
        while (half_length > 0)
        {
            pq.pop();
            half_length--;
        }

        // return middle number
        return pq.top();
    }
};

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    MiddleNumber mn;
    int res = mn.middle(arr);

    std::cout << "Middle number of the given array: " << res << "\n";
    return 0;
}