#include <iostream>
#include <algorithm>

int main()
{
    std::string str = "abba";

    int i = 0, j = str.length() - 1;

    while (i < j)
    {
        if (str[i++] != str[j--])
        {
            std::cout << str << " is not a palindrome" << std::endl;

            return 0;
        }
        std::cout << str << " is a palindrome" << std::endl;

        return 1;
    }
}