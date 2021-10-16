/* Given a string s and a dictionary of words dict of length n,
add spaces in s to construct a sentence where each word is a valid
dictionary word. Each dictionary word can be used more than once.
Return all such possible sentences. */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
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

// Dynamic programming
// Time complexity: O(n^2)
// Space complexity: O(n)
unordered_map<string, vector<string>> dp;
vector<string> wordBreakDP(string str, vector<string> &wordDict)
{
    // memoization
    // if string is repeating character, dp holds subproblem solutions
    if (dp.find(str) != dp.end())
        return dp[str];

    vector<string> result;

    // look through dictionary for hits in string
    for (string word : wordDict)
    {
        if (str.substr(0, word.length()) == word)
        {
            // if hit found, return substring
            if (word.length() == str.length())
                // push into result array
                result.push_back(word);

            // push remaining substring into recursive call
            else
            {
                // recursively call word end to string end
                // store the subproblem solutions in temp variable 
                vector<string> tmp = wordBreakDP(str.substr(word.length()), wordDict);
                // append strings returned to result
                for (string t : tmp)
                    result.push_back(word + " " + t);
            }
        }
    }

    // add cached results
    dp[str] = result;

    return result;
}

int main()
{
    vector<string> dict = {"cats", "cat", "and", "sand", "dog"};
    string str = "catsanddog";
    wordBreakBacktrack(str);

    vector<string> result = wordBreakDP(str, dict);
    for (auto str : result)
        cout << str << " \n";
        
    return 0;
}