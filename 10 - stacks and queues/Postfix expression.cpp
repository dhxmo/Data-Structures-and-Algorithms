/*
Given string S representing a postfix expression, the task is to evaluate the expression
and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.
*/

#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// Function to evaluate a postfix expression.
int evaluatePostfix(string S)
{
    stack<int> stack;

    for (int i = 0; i < S.length(); i++)
    {
        // if element is a valid number, push to stack
        if (S[i] >= '0' && S[i] <= '9')
        {
            stack.push(S[i] - '0');
        }
        // if element is an expression, operate
        else
        {
            // extract top two elements
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            // operate and push to stack
            switch (S[i])
            {
            case '+': // addition
                stack.push(b + a);
                break;
            case '-': // subtraction
                stack.push(b - a);
                break;
            case '*': // multiplication
                stack.push(b * a);
                break;
            case '/': // division
                stack.push(b / a);
                break;
            case '^': // exponent
                stack.push(pow(b, a));
                break;
            }
        }
    }

    return stack.top();
}

int main()
{
    string str = "231*+9-";
    cout << "Postfix evaluation of " << str << " = " << evaluatePostfix(str) << "\n";
    return 0;
}