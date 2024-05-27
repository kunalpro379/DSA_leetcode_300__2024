class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEnd;
    TrieNode()
    {
        isEnd = false;
        // this.isEnd=isEnd;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void Insert(const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    string longestCommonPrefixHelper()
    {
        TrieNode *node = root;
        string prefix;
        while (node && !node->isEnd && node->children.size() == 1)
        {
            auto it = node->children.begin();
            prefix += it->first;
            node = it->second;
        }
        return prefix;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        Trie trie;
        for (const string &str : strs)
            trie.Insert(str);
        return trie.longestCommonPrefixHelper();
    }
};
// class Solution {
// public:
// class TrieNode{
// public:
// char data;
// int childcount;
// TrieNode* children[26];
// bool isTerminal;

//     //coinstructor
// TrieNode(char ch){
// data =ch;
// for (int i=0;i<26;i++){
// children[i]=NULL;

// }
// int childcount=0;
// isTerminal=false;

// }

// };

// class Trie{
// public:
//  TrieNode* root;

//  Trie(char ch){root=new TrieNode(ch);
//  }
//  void InsertWordUtil(TrieNode* root,string word){
//      //base case
// if(word.length()==0){
// root->isTerminal=true;
// return;

// }
// int index=word[index]-'a';
// TrieNode* child;
// //present
// if(root-> children[index]!=NULL){
// child=root->children[index];

// }
// else{
// //absent
// child=new TrieNode(word[0]);
// root->children[index]=child;
// root->childcount++;

// }
// //recursion
// InsertWordUtil(child,word.substr(1));

//  }
//  void InsertWord(string word){
//      InsertWordUtil(root,word);
//  }
// //  void SearchUtil(){}
// //  void SearchWord(){}

// //using trie
// void lcp(string str, string  &ans){

//     for(int i=0;i<str.length();i++){
//         char ch =str[i];
//         if(root->childcount==1){

//             ans.push_back(ch);
//             //aage badhte hai
//             int index=ch-'a';
//             root=root->children[index];
//         }
//         else{
//             break;
//         }
//         if(root->isTerminal)
//         break;
//     }
// }
//     string longestCommonPrefix(vector<string>& strs) {
//        //root ko pucha tere kitne child hai
//        //ek child hai toh ture ans me store karliya
//        // ek se jyada child hai toh false

// Trie * T =new Trie('\0');
// //Strings ko insert karddiya
// for(int i=0; i<strs.size();i++){
// T->InsertWord(strs[i]);

// }
// string first=strs[0];
// string ans="";
// T->lcp(first, ans);
// return ans;
//     }
// };
// };