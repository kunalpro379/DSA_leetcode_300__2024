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
    TreeNode *getNode(unordered_map<int, TreeNode *> &nodes, int val)
    {
        if (nodes.find(val) == nodes.end())
        {
            nodes[val] = new TreeNode(val);
        }
        return nodes[val];
    }

    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        if (descriptions.empty())
            return NULL;

        unordered_map<int, TreeNode *> nodes;
        unordered_map<int, int> childToParent;
        TreeNode *root = NULL;

        for (auto &desc : descriptions)
        {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            TreeNode *parentNode = getNode(nodes, parent);
            TreeNode *childNode = getNode(nodes, child);

            if (isLeft == 1)
            {
                parentNode->left = childNode;
            }
            else
            {
                parentNode->right = childNode;
            }

            childToParent[child] = parent;
        }

        for (auto &node : nodes)
        {
            if (childToParent.find(node.first) == childToParent.end())
            {
                root = node.second;
                break;
            }
        }

        return root;
    }
};