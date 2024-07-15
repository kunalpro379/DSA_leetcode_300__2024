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
    int maxLevelSum(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> Que;
        Que.push(root);
        int maxlevel = 0;
        int maxsum = INT_MIN;
        int currentlevel = 1;
        while (!Que.empty())
        {
            int levelSize = Que.size();
            int levelsum = 0;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = Que.front();
                Que.pop();
                levelsum += node->val;

                if (node->left)
                    Que.push(node->left);
                if (node->right)
                    Que.push(node->right);
            }
            if (levelsum > maxsum)
            {
                maxsum = levelsum;
                maxlevel = currentlevel;
            }
            currentlevel++;
        }
        return maxlevel;
    }
};