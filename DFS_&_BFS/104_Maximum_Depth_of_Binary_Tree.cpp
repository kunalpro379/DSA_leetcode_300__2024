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
    int DFSHelper(TreeNode* root){
        if(!root)return 0;
        return max(DFSHelper(root->left),DFSHelper(root->right))+1;
    }
    int BFSHelper(TreeNode* root){
        if(!root)return 0;
        queue<TreeNode*>Q;
        Q.push(root);
        int depth=0;
        while(!Q.empty()){
            int size=Q.size();
            for(int i=0;i<size;i++){
                TreeNode* current=Q.front();
                Q.pop();
                if(current->left)Q.push(current->left);
                if(current->left)Q.push(current->right);
            }
            depth++;
        }return depth;

    }
    int maxDepth(TreeNode* root) {
        return DFSHelper(root);
        return BFSHelper(root);
    }
};