/*
class TrieNode {
public:


    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() : children(26, nullptr), isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool searchPrefix(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};
*/
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        // filling table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // checking if s from i to j is in the dict so dp[j]=true;
                if (dp[j] && wordset.find(s.substr(j, i - j)) != wordset.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};