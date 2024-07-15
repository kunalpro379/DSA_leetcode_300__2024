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
    void findAllPaths(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &res)
    {
        if (root == NULL)
            return;

        // push current node to the path
        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL && targetSum == root->val)
            res.push_back(path); // reached at leaf so return path iff valid

        else
        {
            findAllPaths(root->left, targetSum - root->val, path, res);
            findAllPaths(root->right, targetSum - root->val, path, res);
        }

        path.pop_back(); // backtrack o prev node for further solutions
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> path;
        findAllPaths(root, targetSum, path, result);
        return result;
    }
};