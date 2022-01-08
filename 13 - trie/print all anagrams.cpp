/* Given an array of strings, return all groups of strings that are anagrams. The groups must 
be created in order of their appearance in the original array.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 
    Time Complexity: O(n * m(log m)),  
        where m is the length of a word. A single traversal through the array is needed.
    Space Complexity: O(n). 
        There are n words in a string. The map requires O(n) space to store the strings.
 */
vector<vector<string>> printAnagramsHash(vector<string> &words)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> umap;

    for (auto x : words)
    {
        // save in a variable to save state of the array
        string temp = x;
        // sort the string
        sort(x.begin(), x.end());
        // push into unordered map
        // key: sorted string
        // value: the original string
        umap[x].push_back(temp);
    }

    // iterate over the unordered map
    for (auto x : umap)
    {
        ans.push_back(x.second);
    }

    return ans;
}

/* TODO - a trie solution */

int main()
{
    vector<string> wordArr = {"cat", "dog", "tac", "god", "act", "gdo"};

    vector<vector<string>> res = printAnagramsHash(wordArr);

    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";

        cout << endl;
    }

    return 0;
}