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
    void inorderTraversal(TreeNode *root, vector<int> &nodes)
    {
        if (root == NULL)
            return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }
    TreeNode *sortedArrayToBST(vector<int> &nodes, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nodes[mid]);
        root->left = sortedArrayToBST(nodes, start, mid - 1);
        root->right = sortedArrayToBST(nodes, mid + 1, end);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nodes;
        inorderTraversal(root, nodes);
        return sortedArrayToBST(nodes, 0, nodes.size() - 1);
    }
};