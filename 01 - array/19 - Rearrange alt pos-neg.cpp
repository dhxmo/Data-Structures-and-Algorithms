/* Given an array of positive and negative numbers, arrange them in an alternate fashion such 
that every positive number is followed by negative and vice-versa maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they 
appear at the end of the array. If there are more negative numbers, they too appear in the end of the array. */

#include <iostream>
using namespace std;

class Rearrange
{
public:
    void rotate(int arr[], int start, int end)
    {
        int temp = arr[end];

        // shift everything by one
        for (int i = end - 1; i >= start; i--)
        {
            arr[i + 1] = arr[i];
        }
        // make the last index value as the first
        arr[start] = temp;
    };

    // Time Complexity - O(N^2)
    // Space Complexity - O(1)
    int *suboptimal(int arr[], int n)
    {
        // i tracks negative numbers
        // j tracks positive numbers
        // k traverses through the array
        int i = 0, j = 0, k = 0;

        while (k < n && j < n && i < n)
        {
            // negative values at even indexes
            if (k % 2 == 0)
            {
                // check if number is positive
                if (arr[k] >= 0)
                {
                    // find first negative number
                    i = k;
                    j = k;
                    while (i < n && arr[i] >= 0)
                    {
                        i++;
                    }

                    if (i >= n)
                    {
                        break;
                    }
                    else
                    {
                        // rotate from current index to where the number is
                        rotate(arr, j, i);
                    }
                }
            }
            // for odd index
            else
            {
                // if negative number at odd index
                if (arr[k] < 0)
                {
                    i = k;
                    j = k;
                    // find the first positive number
                    while (j < n && arr[j] < 0)
                    {
                        j++;
                    }

                    if (j >= n)
                    {
                        break;
                    }
                    else
                    {
                        // rotate from current index to where the number is
                        rotate(arr, i, j);
                    }
                }
            }

            k++;
        }

        return arr;
    };

    /* 
        Use Quick sort technique.

        1. Take the pivot element as 0 and do the first round of Quick Sort.
        2. After above step you will have all the negative elements on left and all the positive elements on the right.
        3. Then just the every alternate element in the left half 
        (negative elements) with the elements in the right (positive elements)
     */

    // Rearranges the array but linear time
    // Time Complexity - O(N)
    // Space Complexity - O(1)
    void optimal(int arr[], int n)
    {
        int pivot = 0;
        int left = 0;
        int right = n - 1;

        while (right > left)
        {
            // move left up to the first positive number
            while (arr[left] < 0 && left < right)
            {
                left++;
            }

            // move right down to the first negative number
            while (arr[right] > 0 && left < right)
            {
                right--;
            }

            // swap and continue
            if (left < right)
            {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
        // all negative elements will be on the left and
        // positive on the right

        // start at 1 cuz we want the positive numbers in the odd places
        left = 1;
        int high = 0;
        // traverse through the negative numbers and bring it to the first positive number
        while (arr[high] < 0)
        {
            high++;
        }
        // point right to the first positive number
        right = high;

        while (arr[left] < 0 && right < n)
        {
            int temp = arr[left];
            // put the positive number in odd indixes
            arr[left] = arr[right];
            arr[right] = temp;
            // iterate up
            left += 2;
            right++;
        }
    };
};

int main()
{
    int arr1[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 2, -3, -4, -5, 6, -7, -8, 9, 10, -11, -12, -13, 14};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Rearrange rearrange;
    rearrange.suboptimal(arr1, size1);
    rearrange.optimal(arr1, size1);

    for (int elem : arr1)
    {
        cout << elem << " ";
    }
    cout << endl;

    for (int elem : arr2)
    {
        cout << elem << " ";
    }
    cout << endl;
}

/* 
swap rearranges the order in the array so we use rotate

arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}

even indixes should have negative numbers
odd indixes should have positive numbers

we traverse from j to find positive numbers
we traverse from i to find negative numbers

k       i       j               arr
0 - neg -> k++
1       1       1  
    (find the first positive number)
                2    
              rotate          -5, 5, -2, 2, 4, 7, 1, 8, 0, -8
        
2 - neg    
3 - pos
4       4       4 
        9               
      rotate                  -5, 5, -2, 2, -8, 7, 1, 8, 0, 4
5 - neg
6 - pos....

(i || j || k) >= n
 */