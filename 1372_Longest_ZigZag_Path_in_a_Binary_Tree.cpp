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
class Solution
{
public:
    /*
        int maxlen=0;
        void dfs(TreeNode* node, bool isLeft, int length){
                if(!node) return;
                maxlen=max(maxlen, length);
                if(isLeft){
                    dfs(node->left, false, length+1);//path goin left
                    dfs(node->right,true, 1);//try new right path
                }
                else{
                    dfs(node->right, true, length+1);//path goin right
                    dfs(node->left, false, 1);//try new left path
                }
        }
        int longestZigZag(TreeNode* root) {
            if(!root) return 0;
            dfs(root, true, 0);//left
            dfs(root,false, 0);//right
            return maxlen;
        }
    */

    // dynamic prog approch

    int maxlen = 0;
    pair<int, int> longestZigZagPath(TreeNode *node)
    {
        if (!node)
            return {-1, -1};
        auto [leftleft, leftright] = longestZigZagPath(node->left);
        auto [rightleft, rightright] = longestZigZagPath(node->right);
        int left = leftright + 1;
        int right = rightleft + 1;
        maxlen = max({maxlen, left, right});
        return {left, right};
    }
    int longestZigZag(TreeNode *root)
    {
        longestZigZagPath(root);
        return maxlen;
    }
};