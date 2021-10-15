/* Given a string S of distinct character of size N and their corresponding
frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build
the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: If two elements have same frequency, then the element which occur at
first will be taken on the left of Binary Tree and other one to the right. */

#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;

// to map each character its huffman value
map<char, string> codes;

// to store the frequency of character of the input data
map<char, int> freq;

// huffman tree node
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;

    // constructor
    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// utility function for priority_queue
struct compare
{
    bool operator()(MinHeapNode *left, MinHeapNode *right)
    {
        return (left->freq > right->freq);
    }
};

// utility function to store map each character with its
// frequency in input string
void calcFreq(string str, int n)
{
    for (int i = 0; i < str.size(); i++)
        freq[str[i]]++;
}

// print huffman codes
void printCodes(struct MinHeapNode *root, string str)
{
    // base case
    if (!root)
        return;

    // If the node's data is not '$' that means it's not an internal node
    //  and print the string.
    if (root->data != '$')
    {
        cout << root->data << ": " << str << endl;
    }

    // print recursively
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// utility function to store characters along with
// their huffman value in a hash table
void storeCodes(struct MinHeapNode *root, string str)
{
    if (root == NULL)
        return;
    if (root->data != '$')
        codes[root->data] = str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

// store heap tree
priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

/*
Time Complexity is O(nlogn) because we are extracting minimum nodes 2*(n-1) times and each time whenever a node is being extracted from the heap then a function called heapify() is being called to rearrange the element according to their priority.This function heapify() takes O(logn) time.

Space Complexity: O(N)
 */
void HuffmanCodes(int size)
{
    // initialize tree
    struct MinHeapNode *left, *right, *top;

    // create minHeap
    for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        // add frequencies of nodes
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    storeCodes(minHeap.top(), "");
}

// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string
string decode_file(struct MinHeapNode *root, string s)
{
    string ans = "";
    struct MinHeapNode *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        // reached leaf node
        if (curr->left == NULL and curr->right == NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans + '\0';
}

int main()
{

    string str = "toBeEncodedData";
    string encodedString, decodedString;

    calcFreq(str, str.length());
    HuffmanCodes(str.length());

    cout << "Character With there Frequencies:\n";
    for (auto v = codes.begin(); v != codes.end(); v++)
        cout << v->first << ' ' << v->second << endl;

    for (auto i : str)
        encodedString += codes[i];

    cout << "\nEncoded Huffman data:\n"
         << encodedString << endl;

    decodedString = decode_file(minHeap.top(), encodedString);
    cout << "\nDecoded Huffman Data:\n"
         << decodedString << endl;
    return 0;
}