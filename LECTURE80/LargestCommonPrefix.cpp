#include<iostream>
#include<vector>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode * children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode * root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    // changed: added index parameter instead of substr
    void insertUtil(TrieNode* root, string &word, int idx)
    {
        //base case
        if(idx == word.length())
        {
            root -> isTerminal = true;
            return;
        }

        int index = word[idx] - 'a';
        TrieNode * child;

        //present
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            //absent
            child = new TrieNode(word[idx]);
            root -> childCount++;
            root -> children[index] = child;
        }

        //RECURSION
        insertUtil(child, word, idx + 1); // changed
    }

    void insertWord(string &word) // changed: pass by reference
    {
        insertUtil(root, word, 0); // changed
    }

    void lcp(string str, string & ans)
    {
        TrieNode * Node = root;
        for(int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if(Node -> childCount == 1 && !Node->isTerminal) // changed: use Node
            {
                ans.push_back(ch);

                int index = ch - 'a';
                Node = Node -> children[index];
            }
            else
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie * t = new Trie('\0');

    for(int i = 0; i < n; i++)
    {
        t -> insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t -> lcp(first, ans);
    return ans;
}

int main()
{
    vector<string> arr = {"flower", "flow", "flight"};
    int n = arr.size();

    string prefix = longestCommonPrefix(arr, n);
    cout << "Longest Common Prefix: " << prefix << endl;

    return 0;
}
