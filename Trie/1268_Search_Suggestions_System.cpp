
struct TrieNode
{
    vector<TrieNode *> children;
    bool isEndOfWord;
    TrieNode() : children(26, NULL), isEndOfWord(false) {}
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void INsert(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    void SearchPrefix(TrieNode *node, const string &prefix, vector<string> &res)
    {
        if (res.size() == 3)
            return;
        if (node->isEndOfWord)
            res.push_back(prefix);
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i])
                SearchPrefix(node->children[i], prefix + char('a' + i), res);
        }
    }
    vector<string> getWordsWithPrefix(const string &prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (!node->children[index])
                return {};
            node = node->children[index];
        }
        vector<string> res;
        SearchPrefix(node, prefix, res);
        return res;
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Trie trie;
        for (const string &product : products)
            trie.INsert(product);
        vector<vector<string>> res;
        string prefix = "";
        for (char ch : searchWord)
        {
            prefix += ch;
            res.push_back(trie.getWordsWithPrefix(prefix));
        }
        return res;
    }
};