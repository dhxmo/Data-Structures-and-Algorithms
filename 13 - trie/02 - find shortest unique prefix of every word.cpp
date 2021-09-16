/* Search and insert into a trie data structure */

#include <iostream>
using namespace std;

#define MAX 256
// max length of input word
#define MAX_WORD_LEN 500

// trie node
struct TrieNode
{
    struct TrieNode *children[MAX];
    int freq;
};

struct TrieNode *createNode(void)
{
    struct TrieNode *parentNode = new TrieNode;
    parentNode->freq = 1;
    for (int i = 0; i < MAX; i++)
    {
        parentNode->children[i] = NULL;
    }

    return parentNode;
}

void insert(struct TrieNode *root, string str)
{
    struct TrieNode *crawler = root;
    int strLen = str.length();

    // traverse the length of the string
    for (int i = 0; i < strLen; i++)
    {
        // index of child node from current char in str
        int index = str[i];

        // create new child
        if (!crawler->children[index])
            crawler->children[index] = createNode();
        else
            (crawler->children[index]->freq)++;

        // move to the next child
        crawler = crawler->children[index];
    }
}

// prints unique prefix for every word stored in trie
// prefixes stored in prefix[]
void findPrefixUtil(struct TrieNode *root, char prefix[], int index)
{
    // corner case
    if (root == NULL)
        return;

    // bsae case
    if (root->freq == 1)
    {
        prefix[index] = '\0';
        cout << prefix << " ";
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (root->children[i] != NULL)
        {
            prefix[index] = i;
            findPrefixUtil(root->children[i], prefix, index + 1);
        }
    }
}

// print all prefixes that uniquely represent all words in arr[0...n-1]
// Time Complexity: O(N) 
// where N is the total number of characters in all words
void findPrefixes(string arr[], int n)
{
    // trie of all words
    struct TrieNode *root = createNode();
    root->freq = 0;
    for (int i = 0; i < n; i++)
        insert(root, arr[i]);

    // array to store all prefixes
    char prefix[MAX_WORD_LEN];

    //print all prefixes
    findPrefixUtil(root, prefix, 0);
}

int main()
{
    string keys[] = {"lion", "loin", "lover", "loser", "laughter", "slaughter"};
    int n = sizeof(keys) / sizeof(keys[0]);
    findPrefixes(keys, n);
    cout << endl;

    return 0;
}