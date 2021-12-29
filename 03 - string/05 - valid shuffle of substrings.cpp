/*
Check if a string is a valid shuffle of two distinct strings
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> convertToASCII(std::string s)
{
    std::vector<int> string_to_ascii;

    for (int i = 0; i < s.length(); i++)
    {
        string_to_ascii.push_back((int)s[i]);
    }
    return string_to_ascii;
}

// Time Complexity: O(NlogN) for the sort
void validShuffle(std::string str1, std::string str2, std::string combined[], int combined_length)
{
    std::string combined_string = str1 + str2;
    std::vector<int> combined_string_ascii = convertToASCII(combined_string);

    sort(combined_string_ascii.begin(), combined_string_ascii.end());

    for (int i = 0; i < combined_length; i++)
    {
        std::vector<int> compare_string_ascii = convertToASCII(combined[i]);
        sort(compare_string_ascii.begin(), compare_string_ascii.end());
        if (combined_string_ascii == compare_string_ascii)
        {
            std::cout << combined[i] << " is a valid shuffle of " << str1 << " & " << str2 << "\n";
        }
        else {
            std::cout << combined[i] << " is not a valid shuffle of " << str1 << " & " << str2 << "\n";

        }
    }
}

int main()
{

    std::string str1 = "XY";
    std::string str2 = "12";
    std::string combined[] = {"1XY2", "Y1X2", "Y21XX"};
    int combined_length = sizeof(combined) / sizeof(combined[0]);

    validShuffle(str1, str2, combined, combined_length);

    return 0;
}
