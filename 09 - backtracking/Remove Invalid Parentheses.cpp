/* 
Given a string s that contains parentheses and letters, 
remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.
 */

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class removeInvalidParens
{
public:
    vector<string> res;
    // map to prevent string duplication
    unordered_map<string, int> mp;

    // function to get how many parentheses can be removed
    int getMinValid(string s)
    {
        stack<char> st;
        int i = 0;
        while (i < s.size())
        {
            // if open parens, push into stack
            if (s[i] == '(')
                st.push('(');
            // if closing parens
            else if (s[i] == ')')
            {
                // if stack non-empty and has open parens
                // pop open parens out
                if (st.size() > 0 && st.top() == '(')
                    st.pop();
                else
                    // else add close parens to the stack
                    st.push(')');
            }
            i++;
        }
        // return size of the stack to get the min removals needed in the string
        return st.size();
    }

    void solve(string s, int minInvalid)
    {
        // to prevent duplicates in the final answer
        // if the string has already appeared
        // no need to consider it again
        if (mp[s] != 0)
            return;
        // else if the tsring is coming in for the first time
        // increase its count
        else
            mp[s]++;

        // base case
        if (minInvalid < 0)
            return;
        // if stack is empty, then valid parentheses string
        if (minInvalid == 0)
        {
            // check that stack is in fact 0
            if (!getMinValid(s))
                // push to result vector
                res.push_back(s);
            return;
        }

        // iterate through string
        for (int i = 0; i < s.size(); i++)
        {
            // isolate left of the current selection
            string left = s.substr(0, i);
            // isolate right of the current selection
            string right = s.substr(i + 1);
            // recurse for the string without the current parens
            // reduce one count to accomodate the exclusion
            solve(left + right, minInvalid - 1);
        }
        return;
    }

    vector<string> removeInvalidParentheses(string s)
    {
        solve(s, getMinValid(s));
        return res;
    }
};

int main()
{
    string expression = "lee(t)(co)de)";

    removeInvalidParens rm;
    vector<string> ans2 = rm.removeInvalidParentheses(expression);

    for (auto str : ans2)
        cout << str << endl;

    return 0;
}