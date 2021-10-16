/* Given a string s and a dictionary of words dict of length n,
add spaces in s to construct a sentence where each word is a valid
dictionary word. Each dictionary word can be used more than once.
Return all such possible sentences. */

#include <iostream>
#include<vector>
using namespace std;

// backtracking solution
// time complexity: O(2^n) as there are 2^n combinations in the worst case
// space complexity: O(n^2) for the recursive stack
bool dictionary(string &word)
{
    string dict[] = {"cats", "cat", "and", "sand", "dog"};
    int n = sizeof(dict) / sizeof(dict[0]);
    for (int i = 0; i < n; i++)
    {
        if (dict[i].compare(word) == 0)
            return true;
    }
    return false;
}

void wordBreakUtil(string str, int size, string result)
{
    for (int i = 1; i <= size; i++)
    {
        // extract substring from 0 to i
        string prefix = str.substr(0, i);

        // if word in dictionary then check the rest of the string
        if (dictionary(prefix))
        {
            // if we've reached the end of the string
            if (i == size)
            {
                result += prefix;
                cout << result << endl;
                return;
            }
            // else ignore prefix and try next
            wordBreakUtil(str.substr(i, size - i), size - i, result + prefix + " ");
        }
    }
}

void wordBreakBacktrack(string str)
{
    wordBreakUtil(str, str.size(), "");
}

int main()
{
    string str = "catsanddog";
    wordBreakBacktrack(str);
    return 0;
}