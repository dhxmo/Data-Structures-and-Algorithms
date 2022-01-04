/*
Given two strings, one is a text string and other is a pattern string. The task is to
print the indexes of all the occurences of pattern string in the text string.
For printing, Starting Index of a string should be taken as 1.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> search(string txt, string pattern)
{
    vector<int> ans;
    int x = pattern.length();

    // iterate over the text
    for (int i = 0; i < txt.length(); i++)
    {
        // isolate substring of pattern's length
        string s = txt.substr(i, x);

        if (s == pattern)
            // account for zero-index
            ans.push_back(i + 1);
    }

    return ans;
}

int main()
{
    string txt = "batmanandrobinarebat", pattern = "bat";
    vector<int> res = search(txt, pattern);

    if (!res.empty())
    {
        cout << "Pattern " << pattern << " shows up in the text " << txt << " at index: ";
        for (auto elem : res)
            cout << elem << " ";
        cout << endl;
    }
    else
    {
        cout << "There's no substring " << pattern << " in text " << txt << "\n";
    }

    return 0;
}