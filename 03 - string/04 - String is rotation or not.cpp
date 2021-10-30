/* Given a string s1 and a string s2, write a snippet to say 
whether s2 is a rotation of s1? 
(eg given s1 = ABCD and s2 = CDAB, return true, 
given s1 = ABCD, and s2 = ACBD , return false) */

#include <iostream>
using namespace std;

bool areRotations(string s1, string s2)
{
    // check length
    if (s1.length() != s2.length())
        return false;

    // concatenate the two strings
    string temp = s1 + s2;

    return (temp.find(s2) != string::npos);
}

int main()
{
    string s1 = "ABCD", s2 = "CDAB";
    if (areRotations(s1, s2))
    {
        cout << "Given strings are rotations of one another" << endl;
    }
    else
    {
        cout << "Given strings are NOT rotations of one another" << endl;
    }
    return 0;
}