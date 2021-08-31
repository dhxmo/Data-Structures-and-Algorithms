/* Search and insert into a trie data structure */

#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 26;

/* Time Complexity: O(key_length)
Space Complexity: O(ALPHABET_SIZE * key_length * N) 
                where N is number of keys in Trie*/

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

int main()
{
    string keys[] = {"avada", "kedavra", "potter", "voldemort"};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct TrieNode *root = createNode();

    // construct trie
    for (int i = 0; i < n; i++)
    {
        insert(root, keys[i]);
    }

    search(root, "dumbledore") ? cout << "Key Found! " << endl : cout << "Key Not Found" << endl;
    search(root, "potter") ? cout << "Key Found! " << endl : cout << "Key Not Found" << endl;

    return 0;
}