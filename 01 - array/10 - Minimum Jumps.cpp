/* Given an array of N integers arr[] where each element represents 
the max number of steps that can be made forward from that element. 
Find the minimum number of jumps to reach the end of the array 
(starting from the first element). If an element is 0, then you 
cannot move through that element. Note: Return -1 if you can't 
reach the end of the array. */

#include <iostream>
#include <algorithm>
using namespace std;

int minJump(int arr[], int n);

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << minJump(arr, n) << endl;
}

// time complexity - O(N) | Space complexity - O(1)
int minJump(int arr[], int n)
{
    int maxReachable, jumps, stepsPossible;

    // start at the beginning
    maxReachable = arr[0];
    jumps = 1;
    stepsPossible = arr[0];

    for (int i = 1; i < n; i++)
    {
        // final case - when we reach the end, return the no. of jumps
        if (i == n - 1)
            return jumps;

        maxReachable = max(maxReachable, i + arr[i]);
        // with each iteration a step has been made, so decrement steps
        stepsPossible--;

        // if the steps possible is in the negative, 
        // then we can't move anywhere
        if (stepsPossible < 0)
            return -1;

        // when steps of the previous jump ends
        if (stepsPossible == 0)
        {
            // move to next jump
            jumps++;

            // if the index we're at, exceeds our overall reach
            if (i >= maxReachable)
                return -1;

            // total steps = how far we can go - where we're at
            stepsPossible = maxReachable - i;
        }
    }
    return jumps;
}

/* 
int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

on each step (i) - update maxReachable as max(oldMax, i + arr[i])
decrement step, as a step has been taken
if we reach the end of our steps on this jump,
     then move to the next jump
     initiate new step as 
     maxReach(how far we can go) minus i (where we're at)

i = 0      max = 1      steps = 1      jumps = 1
i = 1      max = 1+3    steps = 3      jumps = 2
i = 2      max = 2+5    steps = 2      jumps = 2
i = 3      max = 3+8    steps = 1      jumps = 2
i = 4      max = 4+9    steps = 9      jumps = 3
i = 5      max = 13     steps = 8      jumps = 3
        (as 2+5 < 13)
i = 6      max = 13     steps = 7      jumps = 3
i = 7      max = 14     steps = 6      jumps = 3
i = 8      max = 14     steps = 5      jumps = 3
i = 9      max = 14     steps = 4      jumps = 3
i = 10     -> return jump


int arr[] = {0, 1, 1, 1, 1}

i = 0      max = 0      steps = 0      jumps = 1
i = 1      max = 1+1    steps = -1      
if step < 0  -> return false

int arr[] = {1, 0, 0, 0, 0, 4}

i = 0      max = 1      steps = 1      jumps = 1
i = 1      max = 1      steps = 0      jumps = 2
if i > reach -> return false
*/