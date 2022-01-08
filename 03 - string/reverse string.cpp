/* Write a function that reverses a string. 
The input string is given as an array of characters s. */

#include <iostream>
#include <vector>
using namespace std;

class Reverse
{
public:
    void reverseString(vector<string> &strArr)
    {
        int n = strArr.size();

        int i = 0;
        int j = n - 1;
        int mid = (i + j) / 2;

        while (i <= mid && j >= mid + 1)
        {
            swap(strArr[i++], strArr[j--]);
        }
    }
};

int main()
{
    vector<string> str = {"H", "a", "n", "n", "a", "h"};

    Reverse rev;
    rev.reverseString(str);

    for (auto elem : str)
    {
        cout << elem << " ";
    }

    cout << endl;

    return 0;
}