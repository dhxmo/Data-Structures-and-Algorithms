/* Write an efficient program to print all the duplicates and 
their counts in the input string  */

#include <iostream>
#include <unordered_map>
using namespace std;

/* 
    Time Complexity: O(N) where N is the length of the string passed
                O(1) to insert and access any element
    Space Complexity: O(K) where K is the size of the map
 */
void printDuplicates(string str)
{
    unordered_map<char, int> map;
    for (int i = 0; i < str.length(); i++)
    {
        map[str[i]]++;
    }

    for (auto i : map)
    {
        if (i.second > 1)
            cout << i.first << ", count = " << i.second << "\n";
    }
}

int main()
{
    string str = "its a wonderful world";
    printDuplicates(str);
    return 0;
}