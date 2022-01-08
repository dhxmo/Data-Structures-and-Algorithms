/*
Write a program that takes a string as argument, and that prints out a
table giving, for each character that occurs in the string, the character and its
frequency of occurrence.
 */
#include <iostream>
#include <map>

void frequency_counter(std::string str)
{
    std::map<char, int> umap;

    std::cout << "Character\tFrequency\n";

    for (int i = 0; i < str.length(); i++)
    {
        if (umap[str[i]] == 0)
        {
            umap[str[i]] == 1;
        }
        umap[str[i]]++;
    }

    std::map<char, int>::iterator it = umap.begin();
    while (it != umap.end())
    {
        std::cout << "  " << it->first << "\t\t" << "  " << it->second << "\n";
        it++;
    }
}

int main()
{
    std::string str = "leeeetcoodescodingcoders";
    frequency_counter(str);
    return 0;
}