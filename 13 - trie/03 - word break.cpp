/* Given an input string and a dictionary of words, find out
if the input string can be segmented into a space-separated sequence
of dictionary words. See following examples for more details.  */

#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool wordEnd;
};

struct TrieNode *createNode(void)
{
    struct TrieNode *parentNode = new TrieNode;
    parentNode->wordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        parentNode->children[i] = NULL;
    }

    return parentNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *crawler = root;

    for (int i = 0; i < key.length(); i++)
    {
        // 'b' - 'a' = 98-97 = 1 -> log to children[1]
        int index = key[i] - 'a';
        if (!crawler->children[index])
            crawler->children[index] = createNode();

        // move to the next child
        crawler = crawler->children[index];
    }

    // once iteration is done, mark the end
    crawler->wordEnd = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *crawler = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!crawler->children[index])
            return false;

        // move to the next child
        crawler = crawler->children[index];
    }

    return (crawler->wordEnd);
}

/*
Time Complexity: O(n.w)
                where n is the number of trie nodes 
                and w is the word length
Space Complexity: O(n + sum of word length)
 */
bool wordBreak(string str, TrieNode *root)
{
    int size = str.size();

    // base case
    if (size == 0)
        return true;

    for (int i = 1; i <= size; i++)
    {
        // The parameter for search is str.substr(0, i)
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of
        // length size-i
        if (search(root, str.substr(0, i)) &&
            wordBreak(str.substr(i, size - i), root))
            return true;
    }

    return false;
}

int main()
{
    string dictionary[] = {"mobile", "samsung", "sam",
                           "sung", "ma\n", "mango",
                           "icecream", "and", "go", "i",
                           "like", "ice", "cream"};
    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    struct TrieNode *root = createNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, dictionary[i]);

    wordBreak("ilikesamsung", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango", root) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangok", root) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}