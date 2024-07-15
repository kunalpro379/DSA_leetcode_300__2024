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
    // void helper(TreeNode* node, int depth,vector<int>res){
    //     if(!node) return ;
    //     if(depth==res.size()){res.push_back(node->val);}
    //     helper(node->right, depth+1, res);
    //     helper(node->left,depth+1,res);
    // }
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int>res;
    //     if(!root) return res;

    //     helper(root,0,res);
    //     return res;
    // }
    // #solution 2
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> levelQ;
        levelQ.push(root);

        while (!levelQ.empty())
        {
            int levelSize = levelQ.size();
            int rightMostVal;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = levelQ.front();
                levelQ.pop();
                rightMostVal = currentNode->val;
                if (currentNode->left)
                    levelQ.push(currentNode->left);
                if (currentNode->right)
                    levelQ.push(currentNode->right);
            }
            res.push_back(rightMostVal);
        }
        return res;
    }
};