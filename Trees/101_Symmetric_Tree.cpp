/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetricHelper(TreeNode* leftSubTree, TreeNode* RightSubTree){
        if(!leftSubTree&&!RightSubTree) return true;
        if(!leftSubTree||!RightSubTree)return false;
        if(leftSubTree->val!=RightSubTree->val)return false;
        return isSymmetricHelper(leftSubTree->left, RightSubTree->right)&&isSymmetricHelper(leftSubTree->right,RightSubTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isSymmetricHelper(root->left,root->right);
    }
};