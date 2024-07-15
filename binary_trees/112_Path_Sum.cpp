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
    int solve(TreeNode *root, int targetsum, int currentsum)
    {

        if (root == NULL)
            return INT_MIN;
        currentsum += root->val;

        if (root->left == NULL && root->right == NULL)
            if (currentsum == targetsum)
            {
                return targetsum;
            }
            else
            {
                return INT_MIN;
            }

        int x = solve(root->left, targetsum, currentsum);
        int y = solve(root->right, targetsum, currentsum);
        if (x == targetsum || y == targetsum)
            return targetsum;

        return INT_MIN;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {

        if (root == NULL)
            return false;
        return solve(root, targetSum, 0) == targetSum;
    }
};