/* 
    Given an array of integers, find the length of the longest sub-sequence such 
    that elements in the subsequence are consecutive integers, 
    the consecutive numbers can be in any order. 
 */

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

/* 
    Time complexity: O(nLogn)
    Auxiliary space : O(1)
 */
int longestSubSequenceSubOp(int arr[], int size)
{
    sort(arr, arr + size);
    int count = 1, maxCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i + 1] == arr[i] + 1)
            count++;
        else
        {
            if (maxCount < count)
                maxCount = count;
            count = 1;
        }
    }
    return maxCount;
}

/* 
    Time complexity: O(n)
    Auxiliary space : O(n)
 */
int longestSubSequenceOp(int arr[], int size)
{
    unordered_set<int> hashset;
    int maxCount = 0;

    // hash all array elements
    for (int i = 0; i < size; i++)
    {
        hashset.insert(arr[i]);
    }

    // check each possible sequence from the start
    // then update optimal length
    for (int i = 0; i < size; i++)
    {
        // check if the number to its left exists in the set (if current element is starting element of a sequence)
        if (hashset.find(arr[i] - 1) == hashset.end())
        {
            // next check for successive elements in the sequence
            int j = arr[i];
            while (hashset.find(j) != hashset.end())
                j++;

            //update maxCount
            maxCount = max(maxCount, j - arr[i]);
        }
    }

    return maxCount;
}

int main()
{
    int arr[] = {2, 6, 1, 9, 4, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Longest possible consecutive numbers in the given array = " << longestSubSequenceSubOp(arr, size) << endl;

    cout << "Longest possible consecutive numbers in the given array = " << longestSubSequenceOp(arr, size) << endl;

    return 0;
}