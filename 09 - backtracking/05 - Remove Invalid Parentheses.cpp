/* 
Given a string s that contains parentheses and letters, 
remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.
 */

#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

int find_removals(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        // if open parens, push into stack
        if (str[i] == '(')
            st.push(str[i]);

        // if closing parens
        else if (str[i] == ')')
        {
            // if stack non-empty and has open parens
            // pop open parens out
            if (st.size() != 0 && st.top() == '(')
                st.pop();
            else
                // else add close parens to the stack
                st.push(')');
        }
    }

    // return size of the stack to get the min removals needed in the string
    return st.size();
}

void solve(string str, vector<string> &ans, unordered_map<string, bool> &mp, int removals)
{
    // if map of string is already computed, then return
    if (mp[str])
        return;
    // else process the current string
    else
    {
        mp[str] = true;
    }

    if (removals == 0)
    {
        // find removals needed on current string
        int removals_needed = find_removals(str);
        // if no removals needed, push to vector
        if (removals_needed == 0)
            ans.push_back(str);

        return;
    }

    // iterate over the string
    for (int i = 0; i < str.length(); i++)
    {
        // left substring of the current char
        string leftPart = str.substr(0, i);
        // right substring of the current char
        string rightPart = str.substr(i + 1);
        // join the two substrings
        // ie., the join string now doesn't have the current char
        string join = leftPart + rightPart;
        // recurse on new string
        solve(join, ans, mp, removals - 1);
    }
}

vector<string> removeInvalidParentheses(string str)
{
    unordered_map<string, bool> mp;

    // minimum number of paren removals needed for a balanced string
    int min_removals = find_removals(str);

    vector<string> ans;
    solve(str, ans, mp, min_removals);

    return ans;
}

int main()
{
    string expression = "()())()";
    vector<string> ans = removeInvalidParentheses(expression);

    for (auto str : ans)
        cout << str << endl;

    return 0;
}