/*
Given a string S consisting of N, lower case English alphabet, it is also given that a string is
encrypted by first replacing every substring of the string consisting of the same character with
the concatenation of that character and the hexadecimal representation of the size of the substring
and then revering the whole string, the task is to find the encrypted string.
*/

#include <iostream>
#include <sstream>
using namespace std;

string convertToHex(int num)
{
    stringstream st;
    st << hex << num;
    return st.str();
}

string encryptString(string S)
{
    int count = 0;
    char ch = S[0];
    string res = "";

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == ch)
            count++;
        else
        {
            res = convertToHex(count) + ch + res;
            count = 1;
            ch = S[i];
        }
    }

    if (count)
        res = convertToHex(count) + ch + res;

    return res;
}

int main()
{
    string s = "aaaaaaaaaaa";
    cout << "Encrypted string is : " << encryptString(s) << endl;
    return 0;
}